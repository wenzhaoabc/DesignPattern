#include <iostream>
#include <string>
#include "header.h"
using namespace std;

int main() {
	string choice;
	string intro = "1:������ģʽ\n2:������ģʽ\n3:�н���ģʽ\n4:���ع�����ģʽ\n5:�˳�\n";
	cout << intro;
	while (true) {
		//cout << intro;
		cout << "����������ѡ��";
		getline(cin, choice);
		if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5") {
			cout << "���벻����Ҫ������������" << endl;

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