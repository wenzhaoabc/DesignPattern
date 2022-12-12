#include <iostream>
#include"Adapter.h"
#include"Prototype.h"
#include"BusinessService.h"
#include"BuilderPattern.h"
using namespace std;
int main() {
	cout << "----------建造者模式---------" << endl;
	BuilderPattern();
	cout << "-----------------------------" << endl;
	cout << "----------原型模式-----------" << endl;
	Prototype();
	cout << "-----------------------------" << endl;
	cout << "----------适配器模式---------" << endl;
	Adapterfunction();
	cout << "-----------------------------" << endl;
	cout << "----------业务代表模式-------" << endl;
	BusinessService();
	cout << "-----------------------------" << endl;
}