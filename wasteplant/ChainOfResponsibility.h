#pragma once
#include<iostream>

using namespace std;
//��������
class Handler
{
public:
    Handler() { m_pNextHandler = NULL; }
    virtual ~Handler() {}

    //������һ��������
    void SetNextHandler(Handler* successor) { m_pNextHandler = successor; }

    //��������
    virtual void HandleRequest(int days) = 0;
protected:
    Handler* m_pNextHandler;  // �����
};


//���崦���ߡ�����
class Director :public Handler
{
public:
    //��������
    virtual void HandleRequest(int days)
    {
        if (days <= 3)
        {
            cout << "�鳤�����" << days << "��,���������죬��׼" << endl;
        }
        else
        {
            cout << "�鳤�����ʱ�䳬��3�죬ת�����ų�" << endl;
            m_pNextHandler->HandleRequest(days);
        }
    }
};

//���崦���ߡ�����
class Manager :public Handler
{
public:
    //��������
    virtual void HandleRequest(int days)
    {
        if (days <= 7)
        {
            cout << "���ų������"<<days<<"��,������7�죬��׼" << endl;
        }
        else
        {
            cout << "���ų������ʱ�䳬��7�죬ת������" << endl;
            m_pNextHandler->HandleRequest(days);
        }
    }
};

//���崦���ߡ��ϰ�
class Boss :public Handler
{
public:
    //��������
    virtual void HandleRequest(int days)
    {
        if (days <= 15)
        {
            cout << "�������" << days << "��,������15�죬��׼" << endl;
        }
        else
        {
            cout << "�������ʱ�������������׼" << endl;
        }
    }
};


void ChainOfReponsibilityPatternDemo();
