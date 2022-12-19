#pragma once
#include<iostream>
#include<string>
#include<list>
using namespace std;

//部件接口
class Component
{
public:
	virtual void process() = 0;
    virtual ~Component() {};
};

//树节点
class Composite :public Component 
{
public:
	Composite(const string s) :name(s) {};
	void add(Component* element) { elements.push_back(element);	}
	void remove(Component* element) { elements.remove(element); }

	void process()
	{
		//1. process current node
        cout << this->name << " 启动" << endl;

		//2. process leaf nodes
		for (auto& e : elements)
			e->process(); //多态调用
	}
private:
	string name;
	list<Component*>elements; //子节点列表
};

//叶子节点
class Leaf : public Component {
    
public:
    Leaf(const string s) : name(s) {}

    void process() {
        //process current node
        cout << this->name << " 启动" << endl;
    }
 
private:
   string name;
};


int test_composite()
{

    Composite root("垃圾处理中心");
    Composite treeNode1("干垃圾处理线");
    Composite treeNode2("湿垃圾处理线");
    Composite treeNode3("可回收垃圾处理线");
    Composite treeNode4("有害垃圾处理线");
    Leaf leaf1("大型干垃圾处理机A");
    Leaf leaf2("普通干垃圾处理机A");
    Leaf leaf3("普通湿垃圾处理机A");
    Leaf leaf4("普通湿垃圾处理机B");
    Leaf leaf5("普通可回收垃圾处理机A");
    Leaf leaf6("普通有害垃圾处理机A");

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

