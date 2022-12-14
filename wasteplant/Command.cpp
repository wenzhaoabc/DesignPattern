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

	// ����Բ
	void DrawCircle()
	{
		std::cout << "���� ����> Բ_" << ++mCircleCount << '\n' << '\n';
	}

	// ����Բ
	void EraseCircle()
	{
		std::cout << "���� ����> Բ_" << mCircleCount-- << '\n' << '\n';
	}

	void DrawRectangle()
	{
		std::cout << "���� ����> ����_" << ++mRectangleCount << '\n' << '\n';
	}

	void EraseRectangle()
	{
		std::cout << "���� ����> ����_" << mRectangleCount-- << '\n' << '\n';
	}

	void DrawLine()
	{
		std::cout << "���� ����> ֱ��_" << ++mLineCount << '\n' << '\n';
	}

	void EraseLine()
	{
		std::cout << "���� ����> ֱ��_" << mLineCount-- << '\n' << '\n';
	}

	void DrawTriangle()
	{
		std::cout << "���� ����> ������_" << ++mTriangleCount << '\n' << '\n';
	}

	void EraseTriangle()
	{
		std::cout << "���� ����> ������_" << mTriangleCount-- << '\n' << '\n';
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


// Բ�����ࣨ��ִ�������ͬʱ�����Ҷ���Ҳ��ִ�о���Ĳ�����
class CircleCommand :public Command
{
public:
	// ����Ĺ��캯������ʹ�ó�ʼ���б������ø���Ĺ��캯��
	CircleCommand(Painter* painter) :Command(painter) {}


	~CircleCommand() {}

	// ��дExecuteCommand()������ִ�л���Բ����
	virtual void ExecuteCommand()
	{
		mPainter->DrawCircle();
	}

	// ��дRevokeCommand()������ִ�в���Բ����
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



void CommandPatternDemo()
{
	cout << "����ģʽչʾ��" << endl;

	// �������
	Painter* xjm = new Painter();  // ����ִ�ж���
	Command* circle_cmd_1 = new CircleCommand(xjm);     // ��Բ1
	Command* line_cmd_1 = new LineCommand(xjm);         // ��ֱ��1
	Command* triangle_cmd_1 = new TriangleCommand(xjm); // ��������1
	Command* circle_cmd_2 = new CircleCommand(xjm);     // ��Բ2

	ProcessCommand* cch = new ProcessCommand(); // �������󣨸���ѽ��յ�������й��˲��ַ�������ִ���ߣ�

	// ���ø�������
	cch->setCommand(circle_cmd_1);
	cch->setCommand(line_cmd_1);
	cch->setCommand(triangle_cmd_1);
	cch->setCommand(circle_cmd_2);

	cch->Notify(); // ������֪ͨ������

	cch->Revoke(); // ����Բ2
	cch->Revoke(); // ����ֱ��

	cout << endl;
}