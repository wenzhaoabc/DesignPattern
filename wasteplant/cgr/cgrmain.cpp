#include <iostream>
#include"Adapter.h"
#include"Prototype.h"
#include"BusinessService.h"
#include"BuilderPattern.h"
using namespace std;
int main() {
	cout << "----------������ģʽ---------" << endl;
	BuilderPattern();
	cout << "-----------------------------" << endl;
	cout << "----------ԭ��ģʽ-----------" << endl;
	Prototype();
	cout << "-----------------------------" << endl;
	cout << "----------������ģʽ---------" << endl;
	Adapterfunction();
	cout << "-----------------------------" << endl;
	cout << "----------ҵ�����ģʽ-------" << endl;
	BusinessService();
	cout << "-----------------------------" << endl;
}