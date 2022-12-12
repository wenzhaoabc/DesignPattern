#include<iostream>
#include<string>
using namespace std;
//垃圾分为四种：干垃圾Dry,湿垃圾Wet,可回收垃圾Recoverable,有害垃圾Harmful
//创建垃圾处理抽象类，即接口
class WasteDisposal
{
public:

	virtual void Disposal() = 0;//垃圾处理

};
//创建干垃圾处理的策略抽象类
class DryWasteDisposal :public WasteDisposal
{
public:
	void Disposal()
	{
		cout << "转入干垃圾处理流水线——" << endl;
		cout << "干垃圾处理完毕！" << endl;
	}
};
//创建湿垃圾处理的策略抽象类
class WetWasteDisposal :public WasteDisposal
{
public:
	void Disposal()
	{
		cout << "转入湿垃圾处理流水线——" << endl;
		cout << "湿垃圾处理完毕！" << endl;
	}
};
//创建可回收垃圾处理的策略抽象类
class RecoverWasteDisposal :public WasteDisposal
{
public:
	void Disposal()
	{
		cout << "转入可回收垃圾处理流水线——" << endl;
		cout << "可回收垃圾处理完毕！" << endl;
	}
};
//创建有害垃圾处理的策略抽象类
class HarmfulWasteDisposal :public WasteDisposal
{
public:
	void Disposal()
	{
		cout << "转入有害垃圾处理流水线——" << endl;
		cout << "有害垃圾垃圾处理完毕！" << endl;
	}
};
//创建上下文类，根据垃圾类型使得垃圾处理的实现接口自动选择策略去处理垃圾
class Waste
{
public:
	Waste()
	{
		//构造中两个指针设置为Nullptr
		m_WasteDisposal = nullptr;
	}

	~Waste()
	{
		//析构中释放
		delete m_WasteDisposal;
	}

	void PerformWasteDisposal()
	{
		m_WasteDisposal->Disposal();
	}

	void SetWasteDisposal(WasteDisposal* wasteDisposal)
	{
		//防止内存泄漏
		delete m_WasteDisposal;
		m_WasteDisposal = wasteDisposal;
	}

private:
	WasteDisposal* m_WasteDisposal;
};
//策略模式实现函数
void StrategicPatternDemo()
{
	Waste* waste = new Waste();
	//一开始设置垃圾为干垃圾
	cout << "干垃圾进入垃圾处理站，开始处理：" << endl;
	waste->SetWasteDisposal(new DryWasteDisposal);
	//执行策略
	waste->PerformWasteDisposal();

	//一开始设置垃圾为湿垃圾
	cout << "湿垃圾进入垃圾处理站，开始处理：" << endl;
	waste->SetWasteDisposal(new WetWasteDisposal);
	//执行策略
	waste->PerformWasteDisposal();

	//一开始设置垃圾为可回收垃圾
	cout << "可回收垃圾进入垃圾处理站，开始处理：" << endl;
	waste->SetWasteDisposal(new RecoverWasteDisposal);
	//执行策略
	waste->PerformWasteDisposal();

	//一开始设置垃圾为有害垃圾
	cout << "有害垃圾进入垃圾处理站，开始处理：" << endl;
	waste->SetWasteDisposal(new HarmfulWasteDisposal);
	//执行策略
	waste->PerformWasteDisposal();

}