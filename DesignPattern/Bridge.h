#pragma once
#include<iostream>
using namespace std;

int test_bridge();
//实现类接口:垃圾种类
class Waste{
public:
	virtual ~Waste(){}
	virtual std::string GarbageType() const = 0;
};

//具体实现类：干垃圾
class DryGarbage :public Waste {
public:
	string GarbageType() const override {
		return"干垃圾处理\n";
	}
};

//具体实现类：湿垃圾
class WetGarbage :public Waste {
public:
	string GarbageType() const override {
		return"湿垃圾处理\n";
	}
};

//具体实现类：可回收垃圾
class RecoverableGarbage :public Waste {
public:
	string GarbageType() const override {
		return"可回收垃圾处理\n";
	}
};

//具体实现类：有害垃圾
class HarmfulGarbage :public Waste {
public:
	string GarbageType() const override {
		return"有害垃圾处理\n";
	}
};

//抽象化类：垃圾分类处理
class GarbageClassification {
protected:
	Waste* garbage_;

public:
	GarbageClassification(Waste* garbage):garbage_(garbage){
	}

	virtual ~GarbageClassification(){
	}

	virtual string Operation() const {
		return "一般垃圾处理：\n" +
			this->garbage_->GarbageType();
	}
};

//扩展抽象类：大型垃圾处理
class BigGarbageClassification :public GarbageClassification {
public:
	BigGarbageClassification(Waste* garbage) :GarbageClassification(garbage) {
	}

	string Operation() const override {
		return "大型垃圾处理:\n" +
			this->garbage_->GarbageType();
	}
};

void Classify(const GarbageClassification& classification){

	cout << classification.Operation() << endl;
}

int test_bridge() {
	Waste* garbage = new WetGarbage;
	GarbageClassification* classification = new GarbageClassification(garbage);
	Classify(*classification);
	delete garbage;
	delete classification;

	garbage = new HarmfulGarbage;
	classification = new BigGarbageClassification(garbage);
	Classify(*classification);
	delete garbage;
	delete classification;

	return 0;
}


