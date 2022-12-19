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

    bool empty() // 返回队列是否为空
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
        int m_id; // 工作id

        ThreadPool *m_pool;
    public:

        ThreadWorker(ThreadPool *pool, const int id) : m_pool(pool), m_id(id) {
        }

        // 重载()操作
        void operator()() {
            std::function<void()> func;
            bool dequeued; // 是否正在取出队列中元素
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

    bool m_shutdown; // 线程池是否关闭

    SafeQueue<std::function<void()>> m_queue; // 执行函数安全队列，即任务队列

    std::vector<std::thread> m_threads; // 工作线程队列

    std::mutex m_conditional_mutex; // 线程休眠锁互斥变量

    std::condition_variable m_conditional_lock; // 线程环境锁，可以让线程处于休眠或者唤醒状态

public:
    // 线程池构造函数
    ThreadPool(const int n_threads = 4)
            : m_threads(std::vector<std::thread>(n_threads)), m_shutdown(false) {
    }

    ThreadPool(const ThreadPool &) = delete;

    ThreadPool(ThreadPool &&) = delete;

    ThreadPool &operator=(const ThreadPool &) = delete;

    ThreadPool &operator=(ThreadPool &&) = delete;

    void init() {
        for (int i = 0; i < m_threads.size(); ++i) {
            m_threads.at(i) = std::thread(ThreadWorker(this, i)); // 分配工作线程
        }
    }

    void shutdown() {
        m_shutdown = true;
        m_conditional_lock.notify_all(); // 通知，唤醒所有工作线程

        for (int i = 0; i < m_threads.size(); ++i) {
            if (m_threads.at(i).joinable()) // 判断线程是否在等待
            {
                m_threads.at(i).join(); // 将线程加入到等待队列
            }
        }
    }

    template<typename F, typename... Args>
    auto submit(F &&f, Args &&...args) -> std::future<decltype(f(args...))> {
        std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f),
                                                               std::forward<Args>(args)...); // 连接函数和参数定义，特殊函数类型，避免左右值错误
        auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);

        std::function<void()> warpper_func = [task_ptr]() {
            (*task_ptr)();
        };

        // 队列通用安全封包函数，并压入安全队列
        m_queue.enqueue(warpper_func);

        m_conditional_lock.notify_one();

        // 返回先前注册的任务指针
        return task_ptr->get_future();
    }
};

#endif //DESIGNP_THREADPOOL_H
