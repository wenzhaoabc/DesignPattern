#include <iostream>
#include <string>
#include"Proxy.h"
using namespace std;



void ProxyPatternDemo()
{
    cout << "����ģʽչʾ��" << endl;
    cout << endl;
    //С��
    Client* factory = new FactoryClient;

    //��һ���н��æ�ⷿ��
    Client* intermediary = new Intermediary(factory);

    intermediary->disposeGarbage();
    cout << endl;

}
//����