#include <iostream>

using namespace std;

// 目标: 垃圾桶
class GarbageBin {
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
class DryGarbageBinAdapter : public GarbageBin {
public:
    DryGarbageBinAdapter() {
        oGarbageBin = new DryGarbageBin();
    }
    ~DryGarbageBinAdapter() {
        delete oGarbageBin;
    }

    void use() override {
        oGarbageBin->UseDryGarbageBin();
    }

private:
    DryGarbageBin* oGarbageBin;
};

// 湿垃圾桶适配器
class WetGarbageBinAdapter : public GarbageBin {
public:
    WetGarbageBinAdapter() {
        oGarbageBin = new WetGarbageBin();
    }
    ~WetGarbageBinAdapter() {
        delete oGarbageBin;
    }

    void use() override {
        oGarbageBin->UseWetGarbageBin();
    }

private:
    WetGarbageBin* oGarbageBin;
};

// 可回收垃圾桶适配器
class RecoverableGarbageBinAdapter : public GarbageBin {
public:
    RecoverableGarbageBinAdapter() {
        oGarbageBin = new RecoverableGarbageBin();
    }
    ~RecoverableGarbageBinAdapter() {
        delete oGarbageBin;
    }

    void use() override {
        oGarbageBin->UseRecoverableGarbageBin();
    }

private:
    RecoverableGarbageBin* oGarbageBin;
};

// 有害垃圾桶适配器
class HarmfulGarbageBinAdapter : public GarbageBin {
public:
    HarmfulGarbageBinAdapter() {
        oGarbageBin = new HarmfulGarbageBin();
    }
    ~HarmfulGarbageBinAdapter() {
        delete oGarbageBin;
    }

    void use() override {
        oGarbageBin->UseHarmfulGarbageBin();
    }

private:
    HarmfulGarbageBin* oGarbageBin;
};

int Adapterfunction() {
    //使用干垃圾桶
    GarbageBin* GarbageBin1 = new DryGarbageBinAdapter();
    GarbageBin1->use();
    //使用湿垃圾桶
    GarbageBin* GarbageBin2 = new WetGarbageBinAdapter();
    GarbageBin2->use();
    //使用可回收垃圾桶
    GarbageBin* GarbageBin3 = new RecoverableGarbageBinAdapter();
    GarbageBin3->use();
    //使用有害垃圾桶
    GarbageBin* GarbageBin4 = new HarmfulGarbageBinAdapter();
    GarbageBin4->use();
    return 0;
}
