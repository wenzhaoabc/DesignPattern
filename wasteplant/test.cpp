#include <iostream>
#include <string>
#include "header.h"
using namespace std;

int main() {
	string choice;
	string intro = "1:解释器模式\n2:迭代器模式\n3:中介者模式\n4:拦截过滤器模式\n5:退出\n";
	cout << intro;
	while (true) {
		//cout << intro;
		cout << "请输入您的选择：";
		getline(cin, choice);
		if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5") {
			cout << "输入不符合要求，请重新输入" << endl;

		}
		else {
			if (choice == "1") {
				test_explain();
			}
			else if (choice == "2") {
				test_iterator();
			}
			else if (choice == "3") {
				test_mediator();
			}
			else if (choice == "4") {
				test_intercept();
			}
			else {
				break;
			}
		}
	}
	return 0;
}