//
// Created by zst on 2022/12/10.
// 单例模式，线程安全,全局一个总经理
//

#ifndef DESIGNP_SINGLETON_H
#define DESIGNP_SINGLETON_H

#include <string>

class GeneralManager {
private:
    GeneralManager() {};

    ~GeneralManager() {};

    GeneralManager(const GeneralManager &);

    GeneralManager &operator=(const GeneralManager &);

    std::string name;
public:
    static GeneralManager &getInstance() {
        static GeneralManager instance;
        return instance;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        GeneralManager::name = name;
    }
};

#endif //DESIGNP_SINGLETON_H
