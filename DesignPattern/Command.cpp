#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include"Command.h"

using namespace std;




void CommandPatternDemo()
{
	cout << "命令模式展示：" << endl;
	cout << endl;
	// 命令组合
	Painter* xjm = new Painter();  // 命令执行对象
	Command* circle_cmd_1 = new CircleCommand(xjm);     // 开启链板输送机1
	Command* line_cmd_1 = new LineCommand(xjm);         // 开启滚筒筛分机1
	Command* triangle_cmd_1 = new TriangleCommand(xjm); // 开启风选机设备1
	Command* circle_cmd_2 = new CircleCommand(xjm);     // 开启链板输送机2

	ProcessCommand* cch = new ProcessCommand(); // 命令处理对象（负责把接收的命令进行过滤并分发给命令执行者）

	// 设置各项命令
	cch->setCommand(circle_cmd_1);
	cch->setCommand(line_cmd_1);
	cch->setCommand(triangle_cmd_1);
	cch->setCommand(circle_cmd_2);

	cch->Notify(); // 将命令通知给控制台

	cch->Revoke(); // 关闭链板输送机2
	cch->Revoke(); // 关闭滚筒筛分机

	cout << endl;
}