#include<iostream>
using namespace std;
//垃圾处理分为干垃圾处理DryWasteDisposal,湿垃圾处理WetWasteDisposal,可回收垃圾处理RecoverableWasteDisposal,有害垃圾处理HarmfulWasteDisposal
//创建一个抽象模板类Game
class WD
{
public:
	WD() {};
	virtual ~WD() {};
	virtual void startWD() = 0;
	virtual void WDing() = 0;
	virtual void endWD() = 0;
	void play() { startWD(); WDing(); endWD(); };  //不能使用virtual
};

//创建继承模板类WD的DryWD
class DryWD :WD
{
public:
	DryWD() {};
	virtual ~DryWD() {};

	void startWD() { cout << "干垃圾处理开始" << endl; };
	void WDing() { cout << "干垃圾处理中。。。" << endl; };
	void endWD() { cout << "干垃圾处理完毕。" << endl; };
	void play() { cout << "干垃圾处理：" << endl; };
};

//创建继承模板类WD的WetWD
class WetWD :WD
{
public:
	WetWD() {};
	virtual ~WetWD() {};

	void startWD() { cout << "湿垃圾处理开始" << endl; };
	void WDing() { cout << "湿垃圾处理中。。。" << endl; };
	void endWD() { cout << "湿垃圾处理完毕。" << endl; };
	void play() { cout << "湿垃圾处理：" << endl; };
};
//创建继承模板类WD的RecoverableWD
class RecoverableWD :WD
{
public:
	RecoverableWD() {};
	virtual ~RecoverableWD() {};

	void startWD() { cout << "可回收垃圾处理开始" << endl; };
	void WDing() { cout << "可回收垃圾处理中。。。" << endl; };
	void endWD() { cout << "可回收垃圾处理完毕。" << endl; };
	void play() { cout << "可回收垃圾处理：" << endl; };
};
//创建继承模板类WD的HarmfulWD
class HarmfulWD :WD
{
public:
	HarmfulWD() {};
	virtual ~HarmfulWD() {};

	void startWD() { cout << "有害垃圾处理开始" << endl; };
	void WDing() { cout << "有害垃圾处理中。。。" << endl; };
	void endWD() { cout << "有害垃圾处理完毕。" << endl; };
	void play() { cout << "有害垃圾处理：" << endl; };
};
//模板类实现函数
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