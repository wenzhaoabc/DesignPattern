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

void ProxyPatternDemo()
{
    cout << "����ģʽչʾ��" << endl;
    //С��
    Person* xiaoM = new XiaoM;

    //��һ���н��æ�ⷿ��
    Person* intermediary = new Intermediary(xiaoM);

    intermediary->rentHouse();
    cout << endl;

}
//����