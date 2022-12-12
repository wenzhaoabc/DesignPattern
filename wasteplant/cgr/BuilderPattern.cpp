#include <iostream>
using namespace std;

typedef enum MANTYPETag
{
    kDryGarbageBin,
    kWetGarbageBin,
    kRecoverableGarbageBin,
    kHarmfulGarbageBin
}MANTYPE;

//GarbageBin
class GarbageBin
{
public:
    void SettheGarbageCanLid(MANTYPE type) { m_Type = type; }//��������Ͱ��
    void SettheGarbageCan(MANTYPE type) { m_Type = type; }//��������Ͱ��
    void ShowGarbageBin()
    {
        switch (m_Type)
        {
        case kDryGarbageBin:
            cout << "���������Ͱ" << endl;
            return;

        case kWetGarbageBin:
            cout << "����ʪ����Ͱ" << endl;
            return;

        case kRecoverableGarbageBin:
            cout << "����ɻ�������Ͱ" << endl;
            return;
        case kHarmfulGarbageBin:
            cout << "�����к�����Ͱ" << endl;
            return;
        }
    }

private:
    MANTYPE m_Type;
};

// Builder
class Builder
{
public:
    virtual void BuildtheGarbageCanLid() {}
    virtual void BuildtheGarbageCan() {}
    virtual GarbageBin* GetGarbageBin() { return NULL; }
};

// DryGarbageBinBuilder
class DryGarbageBinBuilder : public Builder
{
public:
    DryGarbageBinBuilder() { m_DryGarbageBin = new GarbageBin(); }
    void BuildtheGarbageCanLid() { m_DryGarbageBin->SettheGarbageCanLid(kDryGarbageBin); }
    void BuildtheGarbageCan() { m_DryGarbageBin->SettheGarbageCan(kDryGarbageBin); }
    GarbageBin* GetGarbageBin() { return m_DryGarbageBin; }

private:
    GarbageBin* m_DryGarbageBin;
};


// WetGarbageBinBuilder
class WetGarbageBinBuilder : public Builder
{
public:
    WetGarbageBinBuilder() { m_WetGarbageBin = new GarbageBin(); }
    void BuildtheGarbageCanLid() { m_WetGarbageBin->SettheGarbageCanLid(kWetGarbageBin); }
    void BuildtheGarbageCan() { m_WetGarbageBin->SettheGarbageCan(kWetGarbageBin); }
    GarbageBin* GetGarbageBin() { return m_WetGarbageBin; }

private:
    GarbageBin* m_WetGarbageBin;
};

// RecoverableGarbageBinBuilder
class RecoverableGarbageBinBuilder : public Builder
{
public:
    RecoverableGarbageBinBuilder() { m_RecoverableGarbageBin = new GarbageBin(); }
    void BuildtheGarbageCanLid() { m_RecoverableGarbageBin->SettheGarbageCanLid(kRecoverableGarbageBin); }
    void BuildtheGarbageCan() { m_RecoverableGarbageBin->SettheGarbageCan(kRecoverableGarbageBin); }
    GarbageBin* GetGarbageBin() { return m_RecoverableGarbageBin; }

private:
    GarbageBin* m_RecoverableGarbageBin;
};

// HarmfulGarbageBinBuilder
class HarmfulGarbageBinBuilder : public Builder
{
public:
    HarmfulGarbageBinBuilder() { m_HarmfulGarbageBin = new GarbageBin(); }
    void BuildtheGarbageCanLid() { m_HarmfulGarbageBin->SettheGarbageCanLid(kHarmfulGarbageBin); }
    void BuildtheGarbageCan() { m_HarmfulGarbageBin->SettheGarbageCan(kHarmfulGarbageBin); }
    GarbageBin* GetGarbageBin() { return m_HarmfulGarbageBin; }

private:
    GarbageBin* m_HarmfulGarbageBin;
};

// Director
class Director
{
public:
    Director(Builder* builder) { m_Builder = builder; }
    void CreateGarbageBin();

private:
    Builder* m_Builder;
};

void Director::CreateGarbageBin()
{
    m_Builder->BuildtheGarbageCanLid();
    m_Builder->BuildtheGarbageCan();
}



int BuilderPattern()
{
    //���������Ͱ
    Builder* builderObj1 = new DryGarbageBinBuilder();
    Director directorObj1(builderObj1);
    directorObj1.CreateGarbageBin();
    GarbageBin* manObj1 = builderObj1->GetGarbageBin();
    if (manObj1 == NULL)
        return 0;
    manObj1->ShowGarbageBin();
    //�������
    delete manObj1;
    manObj1 = NULL;
    delete builderObj1;
    builderObj1 = NULL;
    //����ʪ����Ͱ
    Builder* builderObj2 = new WetGarbageBinBuilder();
    Director directorObj2(builderObj2);
    directorObj2.CreateGarbageBin();
    GarbageBin* manObj2 = builderObj2->GetGarbageBin();
    if (manObj2 == NULL)
        return 0;
    manObj2->ShowGarbageBin();
    //�������
    delete manObj2;
    manObj2 = NULL;
    delete builderObj2;
    builderObj2 = NULL;
    //����ɻ�������Ͱ
    Builder* builderObj3 = new RecoverableGarbageBinBuilder();
    Director directorObj3(builderObj3);
    directorObj3.CreateGarbageBin();
    GarbageBin* manObj3 = builderObj3->GetGarbageBin();
    if (manObj3 == NULL)
        return 0;
    manObj3->ShowGarbageBin();
    //�������
    delete manObj3;
    manObj3 = NULL;
    delete builderObj3;
    builderObj3 = NULL;
    //�����к�����Ͱ
    Builder* builderObj4 = new HarmfulGarbageBinBuilder();
    Director directorObj4(builderObj4);
    directorObj4.CreateGarbageBin();
    GarbageBin* manObj4 = builderObj4->GetGarbageBin();
    if (manObj4 == NULL)
        return 0;
    manObj4->ShowGarbageBin();
    //�������
    delete manObj4;
    manObj4 = NULL;
    delete builderObj4;
    builderObj4 = NULL;

    return 0;
};