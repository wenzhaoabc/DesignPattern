#include<iostream>
using namespace std;
//���������Ϊ����������DryWasteDisposal,ʪ��������WetWasteDisposal,�ɻ�����������RecoverableWasteDisposal,�к���������HarmfulWasteDisposal
//����һ������ģ����Game
class WD
{
public:
	WD() {};
	virtual ~WD() {};
	virtual void startWD() = 0;
	virtual void WDing() = 0;
	virtual void endWD() = 0;
	void play() { startWD(); WDing(); endWD(); };  //����ʹ��virtual
};

//�����̳�ģ����WD��DryWD
class DryWD :WD
{
public:
	DryWD() {};
	virtual ~DryWD() {};

	void startWD() { cout << "����������ʼ" << endl; };
	void WDing() { cout << "�����������С�����" << endl; };
	void endWD() { cout << "������������ϡ�" << endl; };
	void play() { cout << "����������" << endl; };
};

//�����̳�ģ����WD��WetWD
class WetWD :WD
{
public:
	WetWD() {};
	virtual ~WetWD() {};

	void startWD() { cout << "ʪ��������ʼ" << endl; };
	void WDing() { cout << "ʪ���������С�����" << endl; };
	void endWD() { cout << "ʪ����������ϡ�" << endl; };
	void play() { cout << "ʪ��������" << endl; };
};
//�����̳�ģ����WD��RecoverableWD
class RecoverableWD :WD
{
public:
	RecoverableWD() {};
	virtual ~RecoverableWD() {};

	void startWD() { cout << "�ɻ�����������ʼ" << endl; };
	void WDing() { cout << "�ɻ������������С�����" << endl; };
	void endWD() { cout << "�ɻ�������������ϡ�" << endl; };
	void play() { cout << "�ɻ�����������" << endl; };
};
//�����̳�ģ����WD��HarmfulWD
class HarmfulWD :WD
{
public:
	HarmfulWD() {};
	virtual ~HarmfulWD() {};

	void startWD() { cout << "�к���������ʼ" << endl; };
	void WDing() { cout << "�к����������С�����" << endl; };
	void endWD() { cout << "�к�����������ϡ�" << endl; };
	void play() { cout << "�к���������" << endl; };
};
//ģ����ʵ�ֺ���
void TemplatePatternDemo()
{
	WD* wd1 = (WD*)new DryWD();
	wd1->play();

	cout << endl;

	WD* wd2 = (WD*)new WetWD();
	wd2->play();
	cout << endl;

	WD* wd3 = (WD*)new RecoverableWD();
	wd3->play();
	cout << endl;

	WD* wd4 = (WD*)new HarmfulWD();
	wd4->play();
	delete wd1;
	wd1 = NULL;

	delete wd2;
	wd2 = NULL;

	delete wd3;
	wd3 = NULL;

	delete wd4;
	wd4 = NULL;

}