#include <iostream>

using namespace std;

// Ŀ��: ����Ͱ
class GarbageBin {
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

// ʪ����Ͱ������
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

// �ɻ�������Ͱ������
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

// �к�����Ͱ������
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
    //ʹ�ø�����Ͱ
    GarbageBin* GarbageBin1 = new DryGarbageBinAdapter();
    GarbageBin1->use();
    //ʹ��ʪ����Ͱ
    GarbageBin* GarbageBin2 = new WetGarbageBinAdapter();
    GarbageBin2->use();
    //ʹ�ÿɻ�������Ͱ
    GarbageBin* GarbageBin3 = new RecoverableGarbageBinAdapter();
    GarbageBin3->use();
    //ʹ���к�����Ͱ
    GarbageBin* GarbageBin4 = new HarmfulGarbageBinAdapter();
    GarbageBin4->use();
    return 0;
}
