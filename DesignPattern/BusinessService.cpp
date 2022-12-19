#include<iostream>
#include<string>

using namespace std;
//业务代表模式

//创建业务服务抽象类BussinessService，提供业务服务接口
class BussinessService
{
public:
	BussinessService() {};
	virtual ~BussinessService() {};

	virtual void doProcessing() = 0;
};

//创建具体的业务服务实体类GarbageCollectionService
class GarbageCollectionService :public BussinessService
{
public:
	GarbageCollectionService() {};
	~GarbageCollectionService() {};

	void doProcessing();
};

void GarbageCollectionService::doProcessing()
{
	cout << "选择回收垃圾功能" << endl;
}

//创建具体的业务服务实体类ViewPipelineSerice
class ViewPipelineSerice :public BussinessService
{
public:
	ViewPipelineSerice() {};
	~ViewPipelineSerice() {};

	void doProcessing();
};

void ViewPipelineSerice::doProcessing()
{
	cout << "选择查看流水线功能" << endl;
}

//创建一个查询服务类BusinessLookUp  查询相关服务对象，提供业务对象对服务对象的访问
class BusinessLookUp
{
public:
	BusinessLookUp() {};
	~BusinessLookUp() {};

	BussinessService* getBusinessService(string serviceType);
};

BussinessService* BusinessLookUp::getBusinessService(string serviceType)
{
	if ("GarbageCollection" == serviceType)
	{
		return new GarbageCollectionService();
	}
	else if ("ViewPipeline" == serviceType)
	{
		return new ViewPipelineSerice();
	}
}

//创建一个业务代表BusinessDelegate类，提供了对业务服务方法的访问
class BusinessDelegate
{
public:
	BusinessDelegate();
	~BusinessDelegate();

	void setServiceType(string serviceType);
	void doTask();
private:
	string serviceType;
	BusinessLookUp* lookupService;
	BussinessService* tbusinessService;
};

BusinessDelegate::BusinessDelegate()
{
	lookupService = new BusinessLookUp();
}
BusinessDelegate::~BusinessDelegate()
{
	delete lookupService;
	lookupService = NULL;
}

void BusinessDelegate::setServiceType(string serviceType)
{
	this->serviceType = serviceType;
}
void BusinessDelegate::doTask()
{
	tbusinessService = lookupService->getBusinessService(serviceType);
	tbusinessService->doProcessing();
}


//创建一个客户端类client
class client
{
public:
	client(BusinessDelegate* tbusinessService);
	~client();

	void doTask();
private:
	BusinessDelegate* mbusinessService;
};

client::client(BusinessDelegate* tbusinessService)
{
	this->mbusinessService = tbusinessService;
}
client::~client()
{

}

void client::doTask()
{
	this->mbusinessService->doTask();
}

int BusinessService()
{
	BusinessDelegate* businessdelegate = new BusinessDelegate();
	businessdelegate->setServiceType("GarbageCollection");
	client* mclient = new client(businessdelegate);
	mclient->doTask();

	businessdelegate->setServiceType("ViewPipeline");
	mclient->doTask();

	delete businessdelegate;
	businessdelegate = NULL;

	delete mclient;
	mclient = NULL;
	return 0;
}
