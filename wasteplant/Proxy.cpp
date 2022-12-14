#include <iostream>
#include <string>
#include"Proxy.h"
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

void ProxyPatternDemo()
{
    cout << "代理模式展示：" << endl;
    //小明
    Person* xiaoM = new XiaoM;

    //找一个中介帮忙租房子
    Person* intermediary = new Intermediary(xiaoM);

    intermediary->rentHouse();
    cout << endl;

}
//场景