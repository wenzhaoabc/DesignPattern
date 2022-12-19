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
        cout << "一家工厂想请垃圾处理站为他们处理垃圾" << endl;
        cout << "向代理服务点提出委托申请" << endl;
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
        cout << "代理服务点将申请提交给垃圾处理中心" << endl;
    }
private:
    Client* m_Client;
};


void ProxyPatternDemo();
