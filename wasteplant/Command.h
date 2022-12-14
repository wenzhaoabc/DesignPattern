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

	// �����������ͻ�
	void DrawCircle()
	{
		std::cout << "���� ����> �������ͻ�" << ++mCircleCount << '\n' << '\n';
	}

	// �ر��������ͻ�
	void EraseCircle()
	{
		std::cout << "�ر� ����> �������ͻ�" << mCircleCount-- << '\n' << '\n';
	}

	void DrawRectangle()
	{
		std::cout << "���� ����> ��ɸ�ֻ�" << ++mRectangleCount << '\n' << '\n';
	}

	void EraseRectangle()
	{
		std::cout << "�ر� ����> ��ɸ�ֻ�" << mRectangleCount-- << '\n' << '\n';
	}

	void DrawLine()
	{
		std::cout << "���� ����> ��Ͳɸ�ֻ�" << ++mLineCount << '\n' << '\n';
	}

	void EraseLine()
	{
		std::cout << "�ر� ����> ��Ͳɸ�ֻ�" << mLineCount-- << '\n' << '\n';
	}

	void DrawTriangle()
	{
		std::cout << "���� ����> ��ѡ���豸" << ++mTriangleCount << '\n' << '\n';
	}

	void EraseTriangle()
	{
		std::cout << "�ر� ����> ��ѡ���豸" << mTriangleCount-- << '\n' << '\n';
	}

private:
	int mCircleCount = 0;
	int mRectangleCount = 0;
	int mLineCount = 0;
	int mTriangleCount = 0;
};
// ���������ࣨ��������������ִ�нӿ�ExecuteCommand��������ӿ�RevokeCommand��
class Command
{
public:
	Command(Painter* painter)
	{
		this->mPainter = painter;
	}

	virtual ~Command() {}

	virtual void ExecuteCommand() = 0; // ִ���麯�����ӳٵ���������������д

	virtual void RevokeCommand() = 0;  // �����麯�����ӳٵ���������������д

protected:
	Painter* mPainter = nullptr; // ά��һ�����Ҷ���
};


// �������ͻ������ࣨ��ִ�������ͬʱ������̨����Ҳ��ִ�о���Ĳ�����
class CircleCommand :public Command
{
public:
	// ����Ĺ��캯������ʹ�ó�ʼ���б������ø���Ĺ��캯��
	CircleCommand(Painter* painter) :Command(painter) {}


	~CircleCommand() {}

	// ��дExecuteCommand()������ִ̨�п����������ͻ�����
	virtual void ExecuteCommand()
	{
		mPainter->DrawCircle();
	}

	// ��дRevokeCommand()������ִ̨�йر��������ͻ�����
	virtual void RevokeCommand()
	{
		mPainter->EraseCircle();
	}
};


// ��������
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

// ֱ������
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

// ����������
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

	// ֪ͨ
	void Notify()
	{
		for (size_t i = 0; i < mCommandList.size(); ++i)
		{
			mCommandList[i]->ExecuteCommand();
		}
	}

	// ������һ������
	void Revoke()
	{
		mCommandList[mCommandList.size() - 1]->RevokeCommand();
		mCommandList.pop_back();
	}

	// �洢����
	void setCommand(Command* cmd)
	{
		mCommandList.push_back(cmd);
	}

private:
	std::vector<Command*> mCommandList; // ������������˳��洢�������������г�����
};

void CommandPatternDemo();
