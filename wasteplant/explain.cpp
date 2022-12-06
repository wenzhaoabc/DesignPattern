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
//识别干垃圾
class Residual :public ab_rubbish {
};

//识别湿垃圾
class Householdfood :public ab_rubbish {
};

//识别可回收垃圾
class Recyclable :public ab_rubbish {
};

//识别有害垃圾
class Hazardous :public ab_rubbish {
};

void test_explain() {
	cout << "请输入垃圾名称" << endl;
	string content;
	getline(cin, content);
	Residual residual;
	Householdfood householdfood;
	Recyclable recyclable;
	Hazardous hazardous;
	string result = "";
	residual.setRubbish("餐盒、餐巾纸、湿纸巾、卫生间用纸、塑料袋、食品包装袋、污染严重的纸、烟蒂、纸尿裤、大骨头、贝壳、花盆、陶瓷");
	householdfood.setRubbish("剩饭剩菜、瓜皮、果核、花卉绿植、过期食品、牛奶");
	recyclable.setRubbish("酱油瓶、易拉罐、饮料瓶、洗发水瓶、塑料玩具、书本、报纸、广告单、纸板箱、衣服、床上用品");
	hazardous.setRubbish("充电电池、纽扣电池、蓄电池、油漆桶、杀虫剂、荧光灯、节能灯、废药品");
	if (residual.interpret(content)) {
		cout << content + "为干垃圾" << endl;
	}
	else if (householdfood.interpret(content)) {
		cout << content + "为湿垃圾" << endl;
	}
	else if (recyclable.interpret(content)) {
		cout << content + "为可回收垃圾" << endl;
	}
	else if (hazardous.interpret(content)) {
		cout << content + "为有害垃圾" << endl;
	}
}