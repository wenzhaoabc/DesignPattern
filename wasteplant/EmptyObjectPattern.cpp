#include<iostream>
#include<string>
#include "EmptyObjectPattern.h"
using namespace std;
//��ĩ�������۱�ʵ����ResidentEvaluationForm
class ResidentEvaluationForm
{
public:
	ResidentEvaluationForm(int id, string a, string b) 
	{ 
		ResidentId = id; 
		name = a;
		evaluation = b;
	}
	int GetResidentId() { return ResidentId; }
	string GetName() { return name; }
	string GetEvaluation() { return evaluation; }
private:
	int ResidentId;//��������֤��
	string name;//���������
	string evaluation;//�������������������
};

//����������PrintREF��ӡ��ĩ�������۱�
class PrintREF
{
public:
	PrintREF() {};
	PrintREF(ResidentEvaluationForm* f) { form = f; };
	virtual ~PrintREF() {};
	virtual void print() = 0;//���麯���������ඨ�壬������ʵ�֣����ڴ�ӡ������

protected:
	ResidentEvaluationForm* form;
};

//������չ�˳�����PrintREF��ʵ����RealPrintREF��
class RealPrintREF :PrintREF
{
public:
	 RealPrintREF(ResidentEvaluationForm* f) { form = f; };
	~RealPrintREF() {};
	void print()
	{
		cout << "�������֤���ţ�" << form->GetResidentId() << endl;
		cout << "����������" << form->GetName() << endl;
		cout << "��������������������ۣ�" << form->GetEvaluation() << endl;
	}
};

//������չ�˳�����PrintREF�Ŀ���NullPrintREF��
class NullPrintREF :PrintREF
{
public:
	NullPrintREF(ResidentEvaluationForm* f) { form = f; };
	~NullPrintREF(){};
	void print()
	{
		cout << "���񲻴��ڣ���ӡʧ��" << endl;
	}

};

//����PrintREFDemo�࣬������ȡʵ���������ʵ��
class PrintREFDemo
{
public:
	PrintREFDemo() {};
	~PrintREFDemo() {};
	static int residentId[20];//������20������
	static PrintREF* GetResidentId(ResidentEvaluationForm* f);
};
//�����������֤��Ϊ���£�
int PrintREFDemo::residentId[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

PrintREF* PrintREFDemo::GetResidentId(ResidentEvaluationForm* f)
{
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		if (residentId[i] ==f->GetResidentId())
		{
			return (PrintREF*)new RealPrintREF (f);
		}
	}
	return (PrintREF*)new NullPrintREF (f);
}

void EmptyObjectPatternDemo()
{
	//�������ž������۱�
	ResidentEvaluationForm* f1 = new ResidentEvaluationForm(1, "����", "���ã�����Ŭ����");
	ResidentEvaluationForm* f2 = new ResidentEvaluationForm(2, "����", "һ��");
	ResidentEvaluationForm* f3 = new ResidentEvaluationForm(50, "����", "��̫��");
	ResidentEvaluationForm* f4 = new ResidentEvaluationForm(71, "����", "�ǳ���");
	PrintREF* c1 = PrintREFDemo::GetResidentId(f1);
	PrintREF* c2 = PrintREFDemo::GetResidentId(f2);
	PrintREF* c3 = PrintREFDemo::GetResidentId(f3);
	PrintREF* c4 = PrintREFDemo::GetResidentId(f4);
	//�ֱ�������ű�
	cout << "f1: ";
	c1->print();
	cout << "f2: ";
	c2->print();
	cout << "f3: ";
	c3->print();
	cout << "f4: ";
	c4->print();
	delete f1;
	f1 = NULL;

	delete f2;
	f2 = NULL;

	delete f3;
	f3 = NULL;

	delete f4;
	f4 = NULL;

	delete c1;
	c1 = NULL;

	delete c2;
	c2 = NULL;

	delete c3;
	c3 = NULL;

	delete c4;
	c4 = NULL;

}

