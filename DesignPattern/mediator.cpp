#include <iostream>
#include <string>
#include "header.h"
using namespace std;

class Mediator;//�н���


//������
class Person
{
protected:
	Mediator* m_mediator; //�н�
public:
	virtual void SetMediator(Mediator* mediator) {} //�����н�
	virtual void SendMessage(string message) {}    //���н鷢����Ϣ
	virtual void GetMessage(string message) {}     //���н��ȡ��Ϣ
};
//�����н����
class Mediator
{
public:
	virtual void Send(string message, Person* person) {}
	virtual void SetA(Person* A) {}  //��������һ��
	virtual void SetB(Person* B) {}
};
//�û�
class User : public Person
{
public:
	void SetMediator(Mediator* mediator) { m_mediator = mediator; }
	void SendMessage(string message) { m_mediator->Send(message, this); }
	void GetMessage(string message) { cout << "�û��յ����������Ϣ" << endl; }
};
//����
class Cleaner : public Person
{
public:
	void SetMediator(Mediator* mediator) { m_mediator = mediator; }
	void SendMessage(string message) { m_mediator->Send(message, this); }
	void GetMessage(string message) { cout << "�����յ���Ϣ������ȥ����" << endl; }
};
//�н�
class RubbishMediator : public Mediator
{
private:
	Person* m_A; //�û�
	Person* m_B; //����
public:
	RubbishMediator() : m_A(0), m_B(0) {}
	void SetA(Person* A) { m_A = A; }
	void SetB(Person* B) { m_B = B; }
	void Send(string message, Person* person)
	{
		if (person == m_A) //�û��������
		{
			cout << "�û���" + message << endl;
			m_B->GetMessage(message); //�����յ�����
		}
		else {
			cout << "������" + message << endl;
			m_A->GetMessage(message);
		}
	}
};



void test_mediator()//�н���
{
	Mediator* mediator = new RubbishMediator();
	Person* person1 = new User();    //�û�
	Person* person2 = new Cleaner();  //����
	mediator->SetA(person1);
	mediator->SetB(person2);
	person1->SetMediator(mediator);
	person2->SetMediator(mediator);
	person1->SendMessage("XXX�ֵ����ֺܶ��������鷳֪ͨ����������һ��\n");
	person2->SendMessage("XXX�ֵ��Ѿ��������\n");
	delete person1; delete person2; delete mediator;

}
