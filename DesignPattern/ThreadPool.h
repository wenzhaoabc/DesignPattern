//
// Created by zst on 2022/12/10.
//

#ifndef DESIGNP_THREADPOOL_H
#define DESIGNP_THREADPOOL_H

#include <mutex>
#include <queue>
#include <functional>
#include <future>
#include <thread>
#include <utility>
#include <vector>

template<typename T>
class SafeQueue {
private:
    std::queue<T> m_queue;
    std::mutex m_mutex;

public:
    SafeQueue() {}

    SafeQueue(SafeQueue &&other) {}

    ~SafeQueue() {}

    bool empty() // ���ض����Ƿ�Ϊ��
    {
        std::unique_lock<std::mutex> lock(m_mutex);

        return m_queue.empty();
    }

    int size() {
        std::unique_lock<std::mutex> lock(m_mutex);

        return m_queue.size();
    }

    void enqueue(T &t) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.emplace(t);
    }

    bool dequeue(T &t) {
        std::unique_lock<std::mutex> lock(m_mutex);

        if (m_queue.empty())
            return false;
        t = std::move(m_queue.front());

        m_queue.pop();

        return true;
    }
};

class ThreadPool {
private:
    class ThreadWorker {
    private:
        int m_id; // ����id

        ThreadPool *m_pool;
    public:

        ThreadWorker(ThreadPool *pool, const int id) : m_pool(pool), m_id(id) {
        }

        // ����()����
        void operator()() {
            std::function<void()> func;
            bool dequeued; // �Ƿ�����ȡ��������Ԫ��
            while (!m_pool->m_shutdown) {
                {
                    std::unique_lock<std::mutex> lock(m_pool->m_conditional_mutex);

                    if (m_pool->m_queue.empty()) {
                        m_pool->m_conditional_lock.wait(lock);
                    }


                    dequeued = m_pool->m_queue.dequeue(func);
                }

                if (dequeued)
                    func();
            }
        }
    };

    bool m_shutdown; // �̳߳��Ƿ�ر�

    SafeQueue<std::function<void()>> m_queue; // ִ�к�����ȫ���У����������

    std::vector<std::thread> m_threads; // �����̶߳���

    std::mutex m_conditional_mutex; // �߳��������������

    std::condition_variable m_conditional_lock; // �̻߳��������������̴߳������߻��߻���״̬

public:
    // �̳߳ع��캯��
    ThreadPool(const int n_threads = 4)
            : m_threads(std::vector<std::thread>(n_threads)), m_shutdown(false) {
    }

    ThreadPool(const ThreadPool &) = delete;

    ThreadPool(ThreadPool &&) = delete;

    ThreadPool &operator=(const ThreadPool &) = delete;

    ThreadPool &operator=(ThreadPool &&) = delete;

    void init() {
        for (int i = 0; i < m_threads.size(); ++i) {
            m_threads.at(i) = std::thread(ThreadWorker(this, i)); // ���乤���߳�
        }
    }

    void shutdown() {
        m_shutdown = true;
        m_conditional_lock.notify_all(); // ֪ͨ���������й����߳�

        for (int i = 0; i < m_threads.size(); ++i) {
            if (m_threads.at(i).joinable()) // �ж��߳��Ƿ��ڵȴ�
            {
                m_threads.at(i).join(); // ���̼߳��뵽�ȴ�����
            }
        }
    }

    template<typename F, typename... Args>
    auto submit(F &&f, Args &&...args) -> std::future<decltype(f(args...))> {
        std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f),
                                                               std::forward<Args>(args)...); // ���Ӻ����Ͳ������壬���⺯�����ͣ���������ֵ����
        auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);

        std::function<void()> warpper_func = [task_ptr]() {
            (*task_ptr)();
        };

        // ����ͨ�ð�ȫ�����������ѹ�밲ȫ����
        m_queue.enqueue(warpper_func);

        m_conditional_lock.notify_one();

        // ������ǰע�������ָ��
        return task_ptr->get_future();
    }
};

#endif //DESIGNP_THREADPOOL_H
