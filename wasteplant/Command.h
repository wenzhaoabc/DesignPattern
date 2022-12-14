#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Painter
{
public:
	Painter() {}
	~Painter() {}

	// 绘制圆
	void DrawCircle()
	{
		std::cout << "绘制 ——> 圆_" << ++mCircleCount << '\n' << '\n';
	}

	// 擦除圆
	void EraseCircle()
	{
		std::cout << "擦除 ——> 圆_" << mCircleCount-- << '\n' << '\n';
	}

	void DrawRectangle()
	{
		std::cout << "绘制 ——> 矩形_" << ++mRectangleCount << '\n' << '\n';
	}

	void EraseRectangle()
	{
		std::cout << "擦除 ——> 矩形_" << mRectangleCount-- << '\n' << '\n';
	}

	void DrawLine()
	{
		std::cout << "绘制 ——> 直线_" << ++mLineCount << '\n' << '\n';
	}

	void EraseLine()
	{
		std::cout << "擦除 ——> 直线_" << mLineCount-- << '\n' << '\n';
	}

	void DrawTriangle()
	{
		std::cout << "绘制 ——> 三角形_" << ++mTriangleCount << '\n' << '\n';
	}

	void EraseTriangle()
	{
		std::cout << "擦除 ——> 三角形_" << mTriangleCount-- << '\n' << '\n';
	}

private:
	int mCircleCount = 0;
	int mRectangleCount = 0;
	int mLineCount = 0;
	int mTriangleCount = 0;
};
// 抽象命令类（声明公共的命令执行接口ExecuteCommand和命令撤销接口RevokeCommand）
class Command
{
public:
	Command(Painter* painter)
	{
		this->mPainter = painter;
	}

	virtual ~Command() {}

	virtual void ExecuteCommand() = 0; // 执行虚函数，延迟到具体命令类中重写

	virtual void RevokeCommand() = 0;  // 撤销虚函数，延迟到具体命令类中重写

protected:
	Painter* mPainter = nullptr; // 维护一个画家对象
};


// 圆命令类（在执行命令的同时，画家对象也会执行具体的操作）
class CircleCommand :public Command
{
public:
	// 子类的构造函数必须使用初始化列表来调用父类的构造函数
	CircleCommand(Painter* painter) :Command(painter) {}


	~CircleCommand() {}

	// 重写ExecuteCommand()，画家执行绘制圆命令
	virtual void ExecuteCommand()
	{
		mPainter->DrawCircle();
	}

	// 重写RevokeCommand()，画家执行擦除圆命令
	virtual void RevokeCommand()
	{
		mPainter->EraseCircle();
	}
};


// 矩形命令
class RectangleCommand :public Command
{
public:
	RectangleCommand(Painter* painter) :Command(painter) {}
	~RectangleCommand() {}

	virtual void ExecuteCommand()
	{
		mPainter->DrawRectangle();
	}

	virtual void RevokeCommand()
	{
		mPainter->EraseRectangle();
	}
};

// 直线命令
class LineCommand :public Command
{
public:
	LineCommand(Painter* painter) :Command(painter) {}
	~LineCommand() {}
	virtual void ExecuteCommand()
	{
		mPainter->DrawLine();
	}

	virtual void RevokeCommand()
	{
		mPainter->EraseLine();
	}
};

// 三角形命令
class TriangleCommand :public Command
{
public:
	TriangleCommand(Painter* painter) :Command(painter) {}
	~TriangleCommand() {}

	virtual void ExecuteCommand()
	{
		mPainter->DrawTriangle();
	}

	virtual void RevokeCommand()
	{
		mPainter->EraseTriangle();
	}
};
class ProcessCommand
{
public:
	ProcessCommand() {}
	~ProcessCommand() {}

	// 通知
	void Notify()
	{
		for (size_t i = 0; i < mCommandList.size(); ++i)
		{
			mCommandList[i]->ExecuteCommand();
		}
	}

	// 撤销上一个命令
	void Revoke()
	{
		mCommandList[mCommandList.size() - 1]->RevokeCommand();
		mCommandList.pop_back();
	}

	// 存储命令
	void setCommand(Command* cmd)
	{
		mCommandList.push_back(cmd);
	}

private:
	std::vector<Command*> mCommandList; // 命令容器，按顺序存储各种命令，方便进行撤销。
};

void CommandPatternDemo();
