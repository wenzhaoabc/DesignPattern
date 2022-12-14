#include <iostream>
#include <string>
#include"Proxy.h"
using namespace std;



void ProxyPatternDemo()
{
    cout << "代理模式展示：" << endl;
    cout << endl;
    //小明
    Person* xiaoM = new XiaoM;

    //找一个中介帮忙租房子
    Person* intermediary = new Intermediary(xiaoM);

    intermediary->rentHouse();
    cout << endl;

}
//场景