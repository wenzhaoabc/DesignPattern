#include<iostream>
#include "factory.h"
#include "EmptyObjectPattern.h"
#include "StrategicPattern.h"
#include "TemplatePattern.h"
#include "TransferObjectPattern.h"
using namespace std;
int main() {
	Factory f;
	f.test();
	cout << endl;
	cout << "�ն���ģʽչʾ��" << endl;
	EmptyObjectPatternDemo();//����ʵ�ֿն���ģʽ�ĺ���
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "����ģʽչʾ��" << endl;
	StrategicPatternDemo();//���ò���ģʽʵ�ֺ���
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "ģ��ģʽչʾ��" << endl;
	TemplatePatternDemo();//����ģ��ģʽʵ�ֺ���
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "�������ģʽչʾ��" << endl;
	TransferObjectPatternDemo();//���ô������ģʽʵ�ֺ���


	return 0;
}