#include <iostream>
#include <string>
#include <list>
#include "header.h"
using namespace std;

//1����������Filter�� - �����������������ִ������֮ǰ��֮��ִ��ĳЩ����
//2������������Filter Chain�� - �����������ж�������������� Target �ϰ��ն����˳��ִ����Щ��������
//3��Target - Target ���������������
//4�����˹�������Filter Manager�� - ���˹���������������͹���������
//5���ͻ��ˣ�Client�� - Client ���� Target ����������Ķ���


//��������������ӿ���Filter
class Filter
{
public:
	Filter() {};
	virtual ~Filter() {};
	virtual void execute(string request) = 0;
};

//����������ʵ����AuthenticationFilter
class AuthenticationFilter :public Filter
{
public:
	AuthenticationFilter() {};
	~AuthenticationFilter() {};
	void execute(string request);
};

void AuthenticationFilter::execute(string request)
{
	cout << "AuthenticationFilter request: " << request << endl;
}

//����������ʵ����DebugFilter
class DebugFilter :public Filter
{
public:
	DebugFilter() {};
	~DebugFilter() {};
	void execute(string request);
};

void DebugFilter::execute(string request)
{
	cout << "DebugFilter request: " << request << endl;
}

//�������������Target��
class Target
{
public:
	Target() {};
	~Target() {};
	void execute(string request);
};

void Target::execute(string request)
{
	cout << "Target request: " << request << endl;
}

//�������������������������ʵ���������������ʵ�ָ�ǿ��Ĺ��˹���
class FilterChain
{
public:
	FilterChain() {};
	~FilterChain();
	void addFilter(Filter* filter);
	void execute(string request);
	void setTarget(Target* target);

private:
	list<Filter*> filterList;
	Target* target;
};

FilterChain::~FilterChain()
{
	list<Filter*>::iterator it;
	for (it = this->filterList.begin(); it != this->filterList.end(); ++it)
	{
		delete (*it);
		(*it) = NULL;
	}
	delete this->target;
	this->target = NULL;
}
void FilterChain::addFilter(Filter* filter)
{
	this->filterList.push_back(filter);
}
void FilterChain::execute(string request)
{
	list<Filter*>::iterator it;
	for (it = this->filterList.begin(); it != this->filterList.end(); ++it)
	{
		(*it)->execute(request);
	}
	this->target->execute(request);
}
void FilterChain::setTarget(Target* target)
{
	this->target = target;
}

//����������������FilterManager����Ҫ�ǹ������������������ɾ�Ĳ��������
class FilterManager
{
public:
	FilterManager(Target* target);
	~FilterManager();
	void setFilter(Filter* filter);
	void filterRequest(string request);

private:
	FilterChain* filterchain;
};

FilterManager::FilterManager(Target* target)
{
	this->filterchain = new FilterChain();
	this->filterchain->setTarget(target);
}
FilterManager::~FilterManager()
{
	delete this->filterchain;
	this->filterchain = NULL;
}
void FilterManager::setFilter(Filter* filter)
{
	this->filterchain->addFilter(filter);
}
void FilterManager::filterRequest(string request)
{
	this->filterchain->execute(request);
}

//�����ͻ���Client
class Client
{
public:
	Client() {};
	~Client() {};
	void setFilterManager(FilterManager* filterManager);
	void sendRequest(string request);

private:
	FilterManager* filtermanager;
};

void Client::setFilterManager(FilterManager* filterManager)
{
	this->filtermanager = filterManager;
}
void Client::sendRequest(string request)
{
	this->filtermanager->filterRequest(request);
}



void test_intercept()//���ع���
{
	FilterManager* filtermanager = new FilterManager(new Target());
	filtermanager->setFilter(new AuthenticationFilter());
	filtermanager->setFilter(new DebugFilter());

	Client* client = new Client();
	client->setFilterManager(filtermanager);
	client->sendRequest("Home");

	delete filtermanager;
	filtermanager = NULL;

	delete client;
	client = NULL;

	//system("pause");
}