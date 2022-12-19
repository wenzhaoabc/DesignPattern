#pragma once
#include<iostream>
#include <string>
using namespace std;
//Subject
class Client
{
public:
    virtual void  disposeGarbage() = 0;
};


//RealSubject
class FactoryClient :public Client
{
public:
    void disposeGarbage()
    {
        cout << "һ�ҹ���������������վΪ���Ǵ�������" << endl;
        cout << "������������ί������" << endl;
        cout << endl;
    }
};

//Proxy
class Intermediary :public Client
{
public:
    Intermediary(Client* client) :m_Client(client) {}
    void disposeGarbage()
    {
        m_Client->disposeGarbage();
        cout << "�������㽫�����ύ��������������" << endl;
    }
private:
    Client* m_Client;
};


void ProxyPatternDemo();
