#include<iostream>
#include"ChainOfResponsibility.h"
using namespace std;


void ChainOfReponsibilityPatternDemo()
{
	cout << "������ģʽչʾ��" << endl;
    cout << endl;
    Handler* director = new Director;
    Handler* manager = new Manager;
    Handler* boss = new Boss;

    //����������
    director->SetNextHandler(manager);
    manager->SetNextHandler(boss);


    director->HandleRequest(1);
    director->HandleRequest(2);
    director->HandleRequest(5);
    director->HandleRequest(8);
   
	cout << endl;
}