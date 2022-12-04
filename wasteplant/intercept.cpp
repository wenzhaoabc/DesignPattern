#include <iostream>
#include <string>
#include <list>
#include "header.h"
using namespace std;

//1、过滤器（Filter） - 过滤器在请求处理程序执行请求之前或之后，执行某些任务。
//2、过滤器链（Filter Chain） - 过滤器链带有多个过滤器，并在 Target 上按照定义的顺序执行这些过滤器。
//3、Target - Target 对象是请求处理程序。
//4、过滤管理器（Filter Manager） - 过滤管理器管理过滤器和过滤器链。
//5、客户端（Client） - Client 是向 Target 对象发送请求的对象。


//创建过滤器抽象接口类Filter
class Filter
{
public:
	Filter() {};
	virtual ~Filter() {};
	virtual void execute(string request) = 0;
};

//创建过滤器实体类AuthenticationFilter
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

//创建过滤器实体类DebugFilter
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

//创建请求处理程序Target类
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

//创建过滤器链，将多个过滤器实体对象连接起来，实现更强大的过滤功能
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

//创建过滤器管理类FilterManager，主要是管理过滤器链，负责增删改查过滤器链
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

//创建客户端Client
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



void test_intercept()//拦截过滤
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