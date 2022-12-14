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
        if (days <= 1)
        {
            cout << "我是主管，有权批准一天假，同意了！" << endl;
        }
        else
        {
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
        if (days <= 3)
        {
            cout << "我是经理，有权批准三以下的假，同意了！" << endl;
        }
        else
        {
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
        if (days <= 7)
        {
            cout << "我是老板，最多让你请7天假，同意了！" << endl;
        }
        else
        {
            cout << "你请的假事假太长了，不同意！" << endl;
        }
    }
};


void ChainOfReponsibilityPatternDemo();
