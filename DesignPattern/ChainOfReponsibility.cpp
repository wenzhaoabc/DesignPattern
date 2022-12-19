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

    cout << "���2�죺" << endl;
    director->HandleRequest(2);
    cout << endl;
    cout << "���5�죺" << endl;
    director->HandleRequest(5);
    cout << endl;
    cout << "���15�죺" << endl;
    director->HandleRequest(15);
    cout << endl;
    cout << "���20�죺" << endl;
    director->HandleRequest(20);
    cout << endl;
   
	cout << endl;
}