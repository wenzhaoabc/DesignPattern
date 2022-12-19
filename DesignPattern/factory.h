//
// Created by zst on 2022/12/10.
//

#ifndef DESIGNP_FACTORY_H
#define DESIGNP_FACTORY_H

#include <string>
#include "GarbageType.h"


class GarbageBin {
public:
    virtual ~GarbageBin() {};

    // ʢ������
    virtual std::string contain_garbage() const = 0;
};

class DryGarbageBin : public GarbageBin {
public:
    std::string contain_garbage() const override {
        return "�ѷ����ڸ�����Ͱ��";
    }
};

class WetGarbageBin : public GarbageBin {
public:
    std::string contain_garbage() const override {
        return "�ѷ�����ʪ����Ͱ��";
    }
};

class RecoverableGarbageBin : public GarbageBin {
public:
    std::string contain_garbage() const override {
        return "�ѷ����ڿɻ�������Ͱ��";
    }
};

class HarmfulGarbageBin : public GarbageBin {
public:
    std::string contain_garbage() const override {
        return "�ѷ������к�����Ͱ��";
    }
};

/**
 * @author zst
 * ����Ͱ������
 */
class GarbageFactory {
public:
    GarbageBin *get_garbage_bin(GARBAGE_TYPE garbage_type) {
        switch (garbage_type) {
            case Dry:
                return new DryGarbageBin;
                break;
            case Wet:
                return new WetGarbageBin;
                break;
            case Recoverable:
                return new RecoverableGarbageBin;
                break;
            case Harmful:
                return new HarmfulGarbageBin;
                break;
            default:
                return nullptr;
                break;
        }
    }
};


#endif //DESIGNP_FACTORY_H
