#include<iostream>
#include<string>
#include "EmptyObjectPattern.h"
using namespace std;
//年末居民评价表实体类ResidentEvaluationForm
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
	int ResidentId;//居民的身份证号
	string name;//居民的姓名
	string evaluation;//居民对垃圾处理厂的评价
};

//创建抽象类PrintREF打印年末居民评价表
class PrintREF
{
public:
	PrintREF() {};
	PrintREF(ResidentEvaluationForm* f) { form = f; };
	virtual ~PrintREF() {};
	virtual void print() = 0;//纯虚函数，抽象类定义，派生类实现，用于打印表单内容

protected:
	ResidentEvaluationForm* form;
};

//创建扩展了抽象类PrintREF的实体类RealPrintREF。
class RealPrintREF :PrintREF
{
public:
	 RealPrintREF(ResidentEvaluationForm* f) { form = f; };
	~RealPrintREF() {};
	void print()
	{
		cout << "居民身份证件号：" << form->GetResidentId() << endl;
		cout << "居民姓名：" << form->GetName() << endl;
		cout << "居民对于垃圾处理厂的评价：" << form->GetEvaluation() << endl;
	}
};

//创建扩展了抽象类PrintREF的空类NullPrintREF。
class NullPrintREF :PrintREF
{
public:
	NullPrintREF(ResidentEvaluationForm* f) { form = f; };
	~NullPrintREF(){};
	void print()
	{
		cout << "居民不存在，打印失败" << endl;
	}

};

//创建PrintREFDemo类，用来获取实体类或空类的实例
class PrintREFDemo
{
public:
	PrintREFDemo() {};
	~PrintREFDemo() {};
	static int residentId[20];//假设有20个居民
	static PrintREF* GetResidentId(ResidentEvaluationForm* f);
};
//假设居民的身份证号为如下：
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
	//创建四张居民评价表单
	ResidentEvaluationForm* f1 = new ResidentEvaluationForm(1, "张三", "还好，继续努力！");
	ResidentEvaluationForm* f2 = new ResidentEvaluationForm(2, "李四", "一般");
	ResidentEvaluationForm* f3 = new ResidentEvaluationForm(50, "王五", "不太好");
	ResidentEvaluationForm* f4 = new ResidentEvaluationForm(71, "赵六", "非常差");
	PrintREF* c1 = PrintREFDemo::GetResidentId(f1);
	PrintREF* c2 = PrintREFDemo::GetResidentId(f2);
	PrintREF* c3 = PrintREFDemo::GetResidentId(f3);
	PrintREF* c4 = PrintREFDemo::GetResidentId(f4);
	//分别输出四张表单
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

