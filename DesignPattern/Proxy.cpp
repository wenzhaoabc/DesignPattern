#include <iostream>
#include <string>
#include"Proxy.h"
using namespace std;



void ProxyPatternDemo()
{
    cout << "代理模式展示：" << endl;
    cout << endl;
    //小明
    Client* factory = new FactoryClient;

    //找一个中介帮忙租房子
    Client* intermediary = new Intermediary(factory);

    intermediary->disposeGarbage();
    cout << endl;

}
//场景