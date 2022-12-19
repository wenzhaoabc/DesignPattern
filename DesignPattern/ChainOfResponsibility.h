#pragma once
#include<iostream>

using namespace std;
//抽象处理者
class Handler
{
public:
    Handler() { m_pNextHandler = NULL; }
    virtual ~Handler() {}

    //设置下一个处理者
    void SetNextHandler(Handler* successor) { m_pNextHandler = successor; }

    //处理请求
    virtual void HandleRequest(int days) = 0;
protected:
    Handler* m_pNextHandler;  // 后继者
};


//具体处理者、主管
class Director :public Handler
{
public:
    //处理请求
    virtual void HandleRequest(int days)
    {
        if (days <= 3)
        {
            cout << "组长：请假" << days << "天,不超过三天，批准" << endl;
        }
        else
        {
            cout << "组长：请假时间超过3天，转交部门长" << endl;
            m_pNextHandler->HandleRequest(days);
        }
    }
};

//具体处理者、经理
class Manager :public Handler
{
public:
    //处理请求
    virtual void HandleRequest(int days)
    {
        if (days <= 7)
        {
            cout << "部门长：请假"<<days<<"天,不超过7天，批准" << endl;
        }
        else
        {
            cout << "部门长：请假时间超过7天，转交经理" << endl;
            m_pNextHandler->HandleRequest(days);
        }
    }
};

//具体处理者、老板
class Boss :public Handler
{
public:
    //处理请求
    virtual void HandleRequest(int days)
    {
        if (days <= 15)
        {
            cout << "经理：请假" << days << "天,不超过15天，批准" << endl;
        }
        else
        {
            cout << "经理：请假时间过长，不予批准" << endl;
        }
    }
};


void ChainOfReponsibilityPatternDemo();
