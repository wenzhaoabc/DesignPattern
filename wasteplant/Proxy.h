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
        cout << "С����Ҫ��һ�䷿�ӣ�" << endl;
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
        cout << "�н��ȡӶ��ٷ�֮10��" << endl;
    }
private:
    Person* m_Person;
};


void ProxyPatternDemo();
