#include<iostream>
#include "factory.h"
#include "EmptyObjectPattern.h"
#include "StrategicPattern.h"
#include "TemplatePattern.h"
#include "TransferObjectPattern.h"
using namespace std;
int main() {
	Factory f;
	f.test();
	cout << endl;
	cout << "空对象模式展示：" << endl;
	EmptyObjectPatternDemo();//调用实现空对象模式的函数
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "策略模式展示：" << endl;
	StrategicPatternDemo();//调用策略模式实现函数
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "模板模式展示：" << endl;
	TemplatePatternDemo();//调用模板模式实现函数
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "传输对象模式展示：" << endl;
	TransferObjectPatternDemo();//调用传输对象模式实现函数


	return 0;
}