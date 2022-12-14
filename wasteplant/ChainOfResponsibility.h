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
        if (days <= 1)
        {
            cout << "�������ܣ���Ȩ��׼һ��٣�ͬ���ˣ�" << endl;
        }
        else
        {
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
        if (days <= 3)
        {
            cout << "���Ǿ�����Ȩ��׼�����µļ٣�ͬ���ˣ�" << endl;
        }
        else
        {
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
        if (days <= 7)
        {
            cout << "�����ϰ壬���������7��٣�ͬ���ˣ�" << endl;
        }
        else
        {
            cout << "����ļ��¼�̫���ˣ���ͬ�⣡" << endl;
        }
    }
};


void ChainOfReponsibilityPatternDemo();
