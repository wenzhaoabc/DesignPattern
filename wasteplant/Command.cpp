#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include"Command.h"

using namespace std;




void CommandPatternDemo()
{
	cout << "����ģʽչʾ��" << endl;
	cout << endl;
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