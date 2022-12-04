#include <iostream>
#include <string>
#include "header.h"
using namespace std;

class expression {
public:
	virtual bool interpret(string content) = 0;
};

class ab_rubbish :public expression {
public:
	ab_rubbish() {};
	ab_rubbish(string r) {
		rubbish = r;
	}
	bool interpret(string content) {
		string::size_type result;
		result = rubbish.find(content);
		if (result == string::npos) {
			return false;
		}
		else {
			return true;
		}
	}
	void setRubbish(string r) {
		rubbish = r;
	}

private:
	string rubbish;
};
//ʶ�������
class Residual :public ab_rubbish {
};

//ʶ��ʪ����
class Householdfood :public ab_rubbish {
};

//ʶ��ɻ�������
class Recyclable :public ab_rubbish {
};

//ʶ���к�����
class Hazardous :public ab_rubbish {
};

void test_explain() {
	cout << "��������������" << endl;
	string content;
	getline(cin, content);
	Residual residual;
	Householdfood householdfood;
	Recyclable recyclable;
	Hazardous hazardous;
	string result = "";
	residual.setRubbish("�ͺС��ͽ�ֽ��ʪֽ����������ֽ�����ϴ���ʳƷ��װ������Ⱦ���ص�ֽ���̵١�ֽ��㡢���ͷ�����ǡ����衢�մ�");
	householdfood.setRubbish("ʣ��ʣ�ˡ���Ƥ�����ˡ�������ֲ������ʳƷ��ţ��");
	recyclable.setRubbish("����ƿ�������ޡ�����ƿ��ϴ��ˮƿ��������ߡ��鱾����ֽ����浥��ֽ���䡢�·���������Ʒ");
	hazardous.setRubbish("����ء�Ŧ�۵�ء����ء�����Ͱ��ɱ�����ӫ��ơ����ܵơ���ҩƷ");
	if (residual.interpret(content)) {
		cout << content + "Ϊ������" << endl;
	}
	else if (householdfood.interpret(content)) {
		cout << content + "Ϊʪ����" << endl;
	}
	else if (recyclable.interpret(content)) {
		cout << content + "Ϊ�ɻ�������" << endl;
	}
	else if (hazardous.interpret(content)) {
		cout << content + "Ϊ�к�����" << endl;
	}
}