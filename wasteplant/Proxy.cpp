#include <iostream>
#include <string>
#include"Proxy.h"
using namespace std;



void ProxyPatternDemo()
{
    cout << "����ģʽչʾ��" << endl;
    cout << endl;
    //С��
    Person* xiaoM = new XiaoM;

    //��һ���н��æ�ⷿ��
    Person* intermediary = new Intermediary(xiaoM);

    intermediary->rentHouse();
    cout << endl;

}
//����