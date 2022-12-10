/**
 * @author zst
 */

#include <iostream>
#include <random>
#include <functional>
#include "ThreadPool.h"
#include "Factory.h"
#include "AbstractFactory.h"
#include "Singleton.h"


std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dist(-1000, 1000);
auto rnd = std::bind(dist, mt);

/**
 * �̳߳�ģʽ����
 */
void simulate_hard_computation() {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000 + rnd()));
}

void multiply(const int a, const int b) {
    simulate_hard_computation();
    const int res = a * b;
    std::cout << a << " * " << b << " = " << res << std::endl;
}

void multiply_output(int& out, const int a, const int b) {
    simulate_hard_computation();
    out = a * b;
    std::cout << a << " * " << b << " = " << out << std::endl;
}

int multiply_return(const int a, const int b) {
    simulate_hard_computation();
    const int res = a * b;
    std::cout << a << " * " << b << " = " << res << std::endl;
    return res;
}

void thread_pool_example() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "�̳߳ز�������" << std::endl;
    ThreadPool pool(3);
    pool.init();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 10; ++j) {
            pool.submit(multiply, i, j);
        }
    }
    int output_ref;
    auto future1 = pool.submit(multiply_output, std::ref(output_ref), 5, 6);
    future1.get();
    std::cout << "Last operation result is equals to" << output_ref << std::endl;

    auto future2 = pool.submit(multiply_return, 5, 3);
    int res = future2.get();
    std::cout << "Last operation result is equals to" << res << std::endl;
    pool.shutdown();
}

/**
 * ����ģʽ��ѡ������Ͱ����
 */
void FactoryGarbageBin() {
    GarbageFactory garbageFactory;
    // �����������ͻ����Ӧ����Ͱ
    GarbageBin* dryGarbageBin = garbageFactory.get_garbage_bin(Dry);
    // ����Ͱʢ������
    std::string res = dryGarbageBin->contain_garbage();
    std::cout << res << std::endl;
    delete dryGarbageBin;
}

/**
 * ���󹤳�ģʽ����
 */
void AbstractFactory() {
    // �ӳ��󹤳��ֻ�ȡһ������
    ConcreteProProcess* pre = new ConcreteProProcess();
    DryPipeLine* dryProcess = pre->CreateDryPipeLine();
    // ��ȡ�ù����Ĳ�Ʒ
    std::string res = dryProcess->dry_process();
    std::cout << res << std::endl;
}

/**
 * ����ģʽ����
 */
void Singleton() {
    GeneralManager& ceo = GeneralManager::getInstance();
    ceo.setName("������");
    std::cout << ceo.getName() << std::endl;

    GeneralManager& ceo2 = GeneralManager::getInstance();
    std::cout << ceo2.getName() << std::endl;
}

int main() {
    thread_pool_example();
    FactoryGarbageBin();
    AbstractFactory();
    Singleton();
    return 0;
}
