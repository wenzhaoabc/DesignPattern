#pragma once
#include<iostream>
#include<string>
#include<list>
using namespace std;

//�����ӿ�
class Component
{
public:
	virtual void process() = 0;
    virtual ~Component() {};
};

//���ڵ�
class Composite :public Component 
{
public:
	Composite(const string s) :name(s) {};
	void add(Component* element) { elements.push_back(element);	}
	void remove(Component* element) { elements.remove(element); }

	void process()
	{
		//1. process current node
        cout << this->name << " ����" << endl;

		//2. process leaf nodes
		for (auto& e : elements)
			e->process(); //��̬����
	}
private:
	string name;
	list<Component*>elements; //�ӽڵ��б�
};

//Ҷ�ӽڵ�
class Leaf : public Component {
    
public:
    Leaf(const string s) : name(s) {}

    void process() {
        //process current node
        cout << this->name << " ����" << endl;
    }
 
private:
   string name;
};


int test_composite()
{

    Composite root("������������");
    Composite treeNode1("������������");
    Composite treeNode2("ʪ����������");
    Composite treeNode3("�ɻ�������������");
    Composite treeNode4("�к�����������");
    Leaf leaf1("���͸����������A");
    Leaf leaf2("��ͨ�����������A");
    Leaf leaf3("��ͨʪ���������A");
    Leaf leaf4("��ͨʪ���������B");
    Leaf leaf5("��ͨ�ɻ������������A");
    Leaf leaf6("��ͨ�к����������A");

    root.add(&treeNode1);
    root.add(&treeNode2);
    root.add(&treeNode3);
    root.add(&treeNode4);

    treeNode1.add(&leaf1);
    treeNode1.add(&leaf2);
    treeNode2.add(&leaf3);
    treeNode2.add(&leaf4);
    treeNode3.add(&leaf5);
    treeNode4.add(&leaf6);

    root.process();

    return 0;
}

