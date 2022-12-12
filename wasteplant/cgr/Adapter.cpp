#include <iostream>

using namespace std;

// 目标: 垃圾桶
class Motor {
public:
    virtual void use() = 0;
};

// 适配者1: 干垃圾桶
class DryGarbageBin {
public:
    void UseDryGarbageBin() {
        cout << "使用干垃圾桶" << endl;
    }
};

// 适配者2: 湿垃圾桶
class WetGarbageBin {
public:
    void UseWetGarbageBin() {
        cout << "使用湿垃圾桶" << endl;
    }
};

// 适配者3: 可回收垃圾桶
class RecoverableGarbageBin {
public:
    void UseRecoverableGarbageBin() {
        cout << "使用可回收垃圾桶" << endl;
    }
};

// 适配者4: 有害垃圾桶
class HarmfulGarbageBin {
public:
    void UseHarmfulGarbageBin() {
        cout << "使用有害垃圾桶" << endl;
    }
};

// 干垃圾桶适配器
class DryGarbageBinAdapter : public Motor {
public:
    DryGarbageBinAdapter() {
        emotor = new DryGarbageBin();
    }
    ~DryGarbageBinAdapter() {
        delete emotor;
    }

    void use() override {
        emotor->UseDryGarbageBin();
    }

private:
    DryGarbageBin* emotor;
};

// 湿垃圾桶适配器
class WetGarbageBinAdapter : public Motor {
public:
    WetGarbageBinAdapter() {
        omotor = new WetGarbageBin();
    }
    ~WetGarbageBinAdapter() {
        delete omotor;
    }

    void use() override {
        omotor->UseWetGarbageBin();
    }

private:
    WetGarbageBin* omotor;
};

// 可回收垃圾桶适配器
class RecoverableGarbageBinAdapter : public Motor {
public:
    RecoverableGarbageBinAdapter() {
        omotor = new RecoverableGarbageBin();
    }
    ~RecoverableGarbageBinAdapter() {
        delete omotor;
    }

    void use() override {
        omotor->UseRecoverableGarbageBin();
    }

private:
    RecoverableGarbageBin* omotor;
};

// 有害垃圾桶适配器
class HarmfulGarbageBinAdapter : public Motor {
public:
    HarmfulGarbageBinAdapter() {
        omotor = new HarmfulGarbageBin();
    }
    ~HarmfulGarbageBinAdapter() {
        delete omotor;
    }

    void use() override {
        omotor->UseHarmfulGarbageBin();
    }

private:
    HarmfulGarbageBin* omotor;
};

int Adapterfunction() {
    //使用干垃圾桶
    Motor* motor1 = new DryGarbageBinAdapter();
    motor1->use();
    //使用湿垃圾桶
    Motor* motor2 = new WetGarbageBinAdapter();
    motor2->use();
    //使用可回收垃圾桶
    Motor* motor3 = new RecoverableGarbageBinAdapter();
    motor3->use();
    //使用有害垃圾桶
    Motor* motor4 = new HarmfulGarbageBinAdapter();
    motor4->use();
    return 0;
}
