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
 * 线程池模式测试
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
    std::cout << "线程池测试样例" << std::endl;
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
 * 工厂模式，选择垃圾桶测试
 */
void FactoryGarbageBin() {
    GarbageFactory garbageFactory;
    // 根据垃圾类型获得相应垃圾桶
    GarbageBin* dryGarbageBin = garbageFactory.get_garbage_bin(Dry);
    // 垃圾桶盛放垃圾
    std::string res = dryGarbageBin->contain_garbage();
    std::cout << res << std::endl;
    delete dryGarbageBin;
}

/**
 * 抽象工厂模式测试
 */
void AbstractFactory() {
    // 从抽象工厂种获取一个工厂
    ConcreteProProcess* pre = new ConcreteProProcess();
    DryPipeLine* dryProcess = pre->CreateDryPipeLine();
    // 获取该工厂的产品
    std::string res = dryProcess->dry_process();
    std::cout << res << std::endl;
}

/**
 * 单例模式测试
 */
void Singleton() {
    GeneralManager& ceo = GeneralManager::getInstance();
    ceo.setName("王经理");
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
