#pragma once
#include "WorkingSchedule.h"
#include "StuffState.h"


class Stuff
{
protected:
	string name;
	StuffState state;
	WorkingSchedule *schedule=nullptr;
public:
	void setName(string n);
	void subjectSchedule(WorkingSchedule *schedule,string n);
	void update();

	void setState(StuffState state);
	StuffState* getState();


};

