#include<iostream>
#include<string>

using namespace std;
//ҵ�����ģʽ

//����ҵ����������BussinessService���ṩҵ�����ӿ�
class BussinessService
{
public:
	BussinessService() {};
	virtual ~BussinessService() {};

	virtual void doProcessing() = 0;
};

//���������ҵ�����ʵ����GarbageCollectionService
class GarbageCollectionService :public BussinessService
{
public:
	GarbageCollectionService() {};
	~GarbageCollectionService() {};

	void doProcessing();
};

void GarbageCollectionService::doProcessing()
{
	cout << "ѡ�������������" << endl;
}

//���������ҵ�����ʵ����ViewPipelineSerice
class ViewPipelineSerice :public BussinessService
{
public:
	ViewPipelineSerice() {};
	~ViewPipelineSerice() {};

	void doProcessing();
};

void ViewPipelineSerice::doProcessing()
{
	cout << "ѡ��鿴��ˮ�߹���" << endl;
}

//����һ����ѯ������BusinessLookUp  ��ѯ��ط�������ṩҵ�����Է������ķ���
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

//����һ��ҵ�����BusinessDelegate�࣬�ṩ�˶�ҵ����񷽷��ķ���
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


//����һ���ͻ�����client
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
