#include<iostream>
#include"ChainOfResponsibility.h"
using namespace std;


void ChainOfReponsibilityPatternDemo()
{
	cout << "责任链模式展示：" << endl;
    cout << endl;
    Handler* director = new Director;
    Handler* manager = new Manager;
    Handler* boss = new Boss;

    //设置责任链
    director->SetNextHandler(manager);
    manager->SetNextHandler(boss);

    cout << "请假2天：" << endl;
    director->HandleRequest(2);
    cout << endl;
    cout << "请假5天：" << endl;
    director->HandleRequest(5);
    cout << endl;
    cout << "请假15天：" << endl;
    director->HandleRequest(15);
    cout << endl;
    cout << "请假20天：" << endl;
    director->HandleRequest(20);
    cout << endl;
   
	cout << endl;
}