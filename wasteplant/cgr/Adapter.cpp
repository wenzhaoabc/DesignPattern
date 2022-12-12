#include <iostream>

using namespace std;

// Ŀ��: ����Ͱ
class Motor {
public:
    virtual void use() = 0;
};

// ������1: ������Ͱ
class DryGarbageBin {
public:
    void UseDryGarbageBin() {
        cout << "ʹ�ø�����Ͱ" << endl;
    }
};

// ������2: ʪ����Ͱ
class WetGarbageBin {
public:
    void UseWetGarbageBin() {
        cout << "ʹ��ʪ����Ͱ" << endl;
    }
};

// ������3: �ɻ�������Ͱ
class RecoverableGarbageBin {
public:
    void UseRecoverableGarbageBin() {
        cout << "ʹ�ÿɻ�������Ͱ" << endl;
    }
};

// ������4: �к�����Ͱ
class HarmfulGarbageBin {
public:
    void UseHarmfulGarbageBin() {
        cout << "ʹ���к�����Ͱ" << endl;
    }
};

// ������Ͱ������
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

// ʪ����Ͱ������
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

// �ɻ�������Ͱ������
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

// �к�����Ͱ������
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
    //ʹ�ø�����Ͱ
    Motor* motor1 = new DryGarbageBinAdapter();
    motor1->use();
    //ʹ��ʪ����Ͱ
    Motor* motor2 = new WetGarbageBinAdapter();
    motor2->use();
    //ʹ�ÿɻ�������Ͱ
    Motor* motor3 = new RecoverableGarbageBinAdapter();
    motor3->use();
    //ʹ���к�����Ͱ
    Motor* motor4 = new HarmfulGarbageBinAdapter();
    motor4->use();
    return 0;
}
