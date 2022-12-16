#include "WorkingSchedule.h"
#include "Stuff.h"

WorkingSchedule::WorkingSchedule()
{
}

WorkingSchedule::~WorkingSchedule()
{
}



void WorkingSchedule::attach(Stuff *stuff)
{
	this->stuffs.push_back(stuff);
}

void WorkingSchedule::notifyALLStuff()
{
	list<Stuff*>::iterator it;
	for (it = this->stuffs.begin(); it != this->stuffs.end(); it++)
	{
		(* it)->update();
	}
}
