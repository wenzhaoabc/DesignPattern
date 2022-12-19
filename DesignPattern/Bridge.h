#pragma once
#include<iostream>
using namespace std;

int test_bridge();
//ʵ����ӿ�:��������
class Waste{
public:
	virtual ~Waste(){}
	virtual std::string GarbageType() const = 0;
};

//����ʵ���ࣺ������
class DryGarbage :public Waste {
public:
	string GarbageType() const override {
		return"����������\n";
	}
};

//����ʵ���ࣺʪ����
class WetGarbage :public Waste {
public:
	string GarbageType() const override {
		return"ʪ��������\n";
	}
};

//����ʵ���ࣺ�ɻ�������
class RecoverableGarbage :public Waste {
public:
	string GarbageType() const override {
		return"�ɻ�����������\n";
	}
};

//����ʵ���ࣺ�к�����
class HarmfulGarbage :public Waste {
public:
	string GarbageType() const override {
		return"�к���������\n";
	}
};

//�����ࣺ�������ദ��
class GarbageClassification {
protected:
	Waste* garbage_;

public:
	GarbageClassification(Waste* garbage):garbage_(garbage){
	}

	virtual ~GarbageClassification(){
	}

	virtual string Operation() const {
		return "һ����������\n" +
			this->garbage_->GarbageType();
	}
};

//��չ�����ࣺ������������
class BigGarbageClassification :public GarbageClassification {
public:
	BigGarbageClassification(Waste* garbage) :GarbageClassification(garbage) {
	}

	string Operation() const override {
		return "������������:\n" +
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


