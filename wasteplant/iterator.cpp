#include <iostream>
#include <string>
#include <vector>
#include "header.h"
using namespace std;

//Iterator: ���������
//ConcreteIterator: ���������
//Aggregate : ����ۺ���
//ConcreteAggregate : ����ۺ���

template<class Item>

//Iterator: ���������
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


//Aggregate : ����ۺ���
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



//ConcreteIterator: ���������
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





//ConcreteAggregate : ����ۺ���
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


void test_iterator()//����	
{
    cout << "�������༰����Ҫ�����������£�" << endl;
    Aggregate<string>* aggr = new ConcreteAggregate<string>();
    aggr->pushData("�������У��ͺС��ͽ�ֽ��ʪֽ����������ֽ�����ϴ���ʳƷ��װ������Ⱦ���ص�ֽ���̵١�ֽ��㡢���ͷ�����ǡ����衢�մ�");
    aggr->pushData("ʪ�����У�ʣ��ʣ�ˡ���Ƥ�����ˡ�������ֲ������ʳƷ��ţ��");
    aggr->pushData("�ɻ��������У�����ƿ�������ޡ�����ƿ��ϴ��ˮƿ��������ߡ��鱾����ֽ����浥��ֽ���䡢�·���������Ʒ");
    aggr->pushData("�к������У�����ء�Ŧ�۵�ء����ء�����Ͱ��ɱ�����ӫ��ơ����ܵơ���ҩƷ");
    Iterator<string>* it = aggr->createIterator();

    for (it->first(); !it->isDone(); it->next())
    {
        std::cout << *it->curItem() << std::endl;
    }
}