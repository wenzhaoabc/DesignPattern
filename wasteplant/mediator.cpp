#include <iostream>
#include <string>
#include "header.h"
using namespace std;

class Mediator;//中介类


//抽象人
class Person
{
protected:
	Mediator* m_mediator; //中介
public:
	virtual void SetMediator(Mediator* mediator) {} //设置中介
	virtual void SendMessage(string message) {}    //向中介发送信息
	virtual void GetMessage(string message) {}     //从中介获取信息
};
//抽象中介机构
class Mediator
{
public:
	virtual void Send(string message, Person* person) {}
	virtual void SetA(Person* A) {}  //设置其中一方
	virtual void SetB(Person* B) {}
};
//用户
class User : public Person
{
public:
	void SetMediator(Mediator* mediator) { m_mediator = mediator; }
	void SendMessage(string message) { m_mediator->Send(message, this); }
	void GetMessage(string message) { cout << "用户收到清理完毕信息" << endl; }
};
//清理工
class Cleaner : public Person
{
public:
	void SetMediator(Mediator* mediator) { m_mediator = mediator; }
	void SendMessage(string message) { m_mediator->Send(message, this); }
	void GetMessage(string message) { cout << "清理工收到信息，即将去清理：" << endl; }
};
//中介
class RubbishMediator : public Mediator
{
private:
	Person* m_A; //用户
	Person* m_B; //清理工
public:
	RubbishMediator() : m_A(0), m_B(0) {}
	void SetA(Person* A) { m_A = A; }
	void SetB(Person* B) { m_B = B; }
	void Send(string message, Person* person)
	{
		if (person == m_A) //用户提出反馈
		{
			cout << "用户：" + message << endl;
			m_B->GetMessage(message); //清理工收到反馈
		}
		else {
			cout << "清理工：" + message << endl;
			m_A->GetMessage(message);
		}
	}
};



void test_mediator()//中介者
{
	Mediator* mediator = new RubbishMediator();
	Person* person1 = new User();    //用户
	Person* person2 = new Cleaner();  //清理工
	mediator->SetA(person1);
	mediator->SetB(person2);
	person1->SetMediator(mediator);
	person2->SetMediator(mediator);
	person1->SendMessage("XXX街道发现很多垃圾，麻烦通知清理工来清理一下\n");
	person2->SendMessage("XXX街道已经清理完毕\n");
	delete person1; delete person2; delete mediator;

}
