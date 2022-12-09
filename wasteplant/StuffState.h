#pragma once
#include<iostream>
using namespace std;
class Stuff;

class StuffState
{
	string description;
	
public:
	StuffState();
	~StuffState();
	virtual void doAction(Stuff* stuff);
	string getStateDescription();
protected:
	void setStateDescription(string d);
};

class OnDuty :public StuffState
{
public:
	OnDuty();
	~OnDuty();
	void doAction(Stuff* stuff);
};

class OffDuty :public StuffState
{
public:
	OffDuty();
	~OffDuty();
	void doAction(Stuff* stuff);
};
