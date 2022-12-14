#include<iostream>
#include"FrontController.h"
using namespace std;



void FrontControllerPatternDemo() {
	cout << "前端控制器模式展示：" << endl;
	cout << endl;
	FrontController* frontController = new FrontController();
	frontController->dispatchRequest("HOME");
	cout << endl;
	frontController->dispatchRequest("STUDENT");
	cout << endl;
}