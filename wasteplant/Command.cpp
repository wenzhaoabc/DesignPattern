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
	Command* circle_cmd_1 = new CircleCommand(xjm);     // �����������ͻ�1
	Command* line_cmd_1 = new LineCommand(xjm);         // ������Ͳɸ�ֻ�1
	Command* triangle_cmd_1 = new TriangleCommand(xjm); // ������ѡ���豸1
	Command* circle_cmd_2 = new CircleCommand(xjm);     // �����������ͻ�2

	ProcessCommand* cch = new ProcessCommand(); // �������󣨸���ѽ��յ�������й��˲��ַ�������ִ���ߣ�

	// ���ø�������
	cch->setCommand(circle_cmd_1);
	cch->setCommand(line_cmd_1);
	cch->setCommand(triangle_cmd_1);
	cch->setCommand(circle_cmd_2);

	cch->Notify(); // ������֪ͨ������̨

	cch->Revoke(); // �ر��������ͻ�2
	cch->Revoke(); // �رչ�Ͳɸ�ֻ�

	cout << endl;
}