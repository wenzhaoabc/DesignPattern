#pragma once
#include<iostream>
#include <string>
using namespace std;
//Subject
class Person
{
public:
    virtual void rentHouse() = 0;
};


//RealSubject
class XiaoM :public Person
{
public:
    void rentHouse()
    {
        cout << "小明需要租一间房子！" << endl;
    }
};

//Proxy
class Intermediary :public Person
{
public:
    Intermediary(Person* person) :m_Person(person) {}
    void rentHouse()
    {
        m_Person->rentHouse();
        cout << "中介抽取佣金百分之10！" << endl;
    }
private:
    Person* m_Person;
};


void ProxyPatternDemo();
