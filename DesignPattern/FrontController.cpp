#include<iostream>
#include"FrontController.h"
using namespace std;



void FrontControllerPatternDemo() {
	cout << "ǰ�˿�����ģʽչʾ��" << endl;
	cout << endl;
	FrontController* frontController = new FrontController();
	frontController->dispatchRequest("�ලԱ");
	cout << endl;
	frontController->dispatchRequest("����");
	cout << endl;
}