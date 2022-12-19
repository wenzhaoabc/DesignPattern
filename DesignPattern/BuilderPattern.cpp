#include <iostream>
using namespace std;

typedef enum GarbageBinTYPETag
{
    kDryGarbageBin,
    kWetGarbageBin,
    kRecoverableGarbageBin,
    kHarmfulGarbageBin
}GarbageBinTYPE;

//GarbageBin
class GarbageBin
{
public:
    void SettheGarbageCanLid(GarbageBinTYPE type) { m_Type = type; }//��������Ͱ��
    void SettheGarbageCan(GarbageBinTYPE type) { m_Type = type; }//��������Ͱ��
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
    GarbageBinTYPE m_Type;
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
    GarbageBin* GarbageBinObj1 = builderObj1->GetGarbageBin();
    if (GarbageBinObj1 == NULL)
        return 0;
    GarbageBinObj1->ShowGarbageBin();
    //�������
    delete GarbageBinObj1;
    GarbageBinObj1 = NULL;
    delete builderObj1;
    builderObj1 = NULL;
    //����ʪ����Ͱ
    Builder* builderObj2 = new WetGarbageBinBuilder();
    Director directorObj2(builderObj2);
    directorObj2.CreateGarbageBin();
    GarbageBin* GarbageBinObj2 = builderObj2->GetGarbageBin();
    if (GarbageBinObj2 == NULL)
        return 0;
    GarbageBinObj2->ShowGarbageBin();
    //�������
    delete GarbageBinObj2;
    GarbageBinObj2 = NULL;
    delete builderObj2;
    builderObj2 = NULL;
    //����ɻ�������Ͱ
    Builder* builderObj3 = new RecoverableGarbageBinBuilder();
    Director directorObj3(builderObj3);
    directorObj3.CreateGarbageBin();
    GarbageBin* GarbageBinObj3 = builderObj3->GetGarbageBin();
    if (GarbageBinObj3 == NULL)
        return 0;
    GarbageBinObj3->ShowGarbageBin();
    //�������
    delete GarbageBinObj3;
    GarbageBinObj3 = NULL;
    delete builderObj3;
    builderObj3 = NULL;
    //�����к�����Ͱ
    Builder* builderObj4 = new HarmfulGarbageBinBuilder();
    Director directorObj4(builderObj4);
    directorObj4.CreateGarbageBin();
    GarbageBin* GarbageBinObj4 = builderObj4->GetGarbageBin();
    if (GarbageBinObj4 == NULL)
        return 0;
    GarbageBinObj4->ShowGarbageBin();
    //�������
    delete GarbageBinObj4;
    GarbageBinObj4 = NULL;
    delete builderObj4;
    builderObj4 = NULL;

    return 0;
};