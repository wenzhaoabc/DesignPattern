#include <iostream>
#include <string>
#include <vector>
#include "header.h"
using namespace std;

//Iterator: 抽象迭代器
//ConcreteIterator: 具体迭代器
//Aggregate : 抽象聚合类
//ConcreteAggregate : 具体聚合类

template<class Item>

//Iterator: 抽象迭代器
class Iterator
{
public:
    Iterator() {};
    virtual ~Iterator() {};

    virtual void first() = 0;
    virtual void next() = 0;
    virtual Item* curItem() = 0;
    virtual bool isDone() = 0;
};


//Aggregate : 抽象聚合类
template<class Item>
class Aggregate {
public:
    Aggregate() {};
    virtual ~Aggregate() {};

    virtual void pushData(Item item) = 0;
    virtual Iterator<Item>* createIterator() = 0;
    virtual Item& operator[](int index) = 0;
    virtual int getSize() = 0;
};



//ConcreteIterator: 具体迭代器
template<class Item>

class ConcreteIterator : public Iterator <Item>
{
public:
    ConcreteIterator(Aggregate<Item>* a) :aggr(a), cur(0) {};
    virtual ~ConcreteIterator() {};

    virtual void first();
    virtual void next();
    virtual Item* curItem();
    virtual bool isDone();
private:
    Aggregate<Item>* aggr;
    int cur;
};

template<class Item>
void ConcreteIterator<Item>::first()
{
    cur = 0;
}

template<class Item>
void ConcreteIterator<Item>::next()
{
    if (cur < aggr->getSize())
        cur++;
}

template<class Item>
Item* ConcreteIterator<Item>::curItem()
{
    if (cur < aggr->getSize())
    {
        return &(*aggr)[cur];
    }
    else
    {
        return NULL;
    }
}

template<class Item>
bool ConcreteIterator<Item>::isDone()
{
    return cur >= aggr->getSize();
}





//ConcreteAggregate : 具体聚合类
template <class Item>
class ConcreteAggregate : public Aggregate<Item>
{
public:
    ConcreteAggregate() {};
    virtual ~ConcreteAggregate() {};

    virtual void pushData(Item item);
    virtual Iterator<Item>* createIterator();
    virtual Item& operator[](int index);
    virtual int getSize();
private:
    vector<Item> data;
};

template <class Item>
void ConcreteAggregate<Item>::pushData(Item item)
{
    data.push_back(item);
}

template <class Item>
Iterator<Item>* ConcreteAggregate<Item>::createIterator()
{
    return new ConcreteIterator<Item>(this);
}

template <class Item>
Item& ConcreteAggregate<Item>::operator[](int index)
{
    return data[index];
}

template <class Item>
int ConcreteAggregate<Item>::getSize()
{
    return data.size();
}


void test_iterator()//迭代	
{
    cout << "垃圾分类及其主要包括垃圾如下：" << endl;
    Aggregate<string>* aggr = new ConcreteAggregate<string>();
    aggr->pushData("干垃圾有：餐盒、餐巾纸、湿纸巾、卫生间用纸、塑料袋、食品包装袋、污染严重的纸、烟蒂、纸尿裤、大骨头、贝壳、花盆、陶瓷");
    aggr->pushData("湿垃圾有：剩饭剩菜、瓜皮、果核、花卉绿植、过期食品、牛奶");
    aggr->pushData("可回收垃圾有：酱油瓶、易拉罐、饮料瓶、洗发水瓶、塑料玩具、书本、报纸、广告单、纸板箱、衣服、床上用品");
    aggr->pushData("有害垃圾有：充电电池、纽扣电池、蓄电池、油漆桶、杀虫剂、荧光灯、节能灯、废药品");
    Iterator<string>* it = aggr->createIterator();

    for (it->first(); !it->isDone(); it->next())
    {
        std::cout << *it->curItem() << std::endl;
    }
}