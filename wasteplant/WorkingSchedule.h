#pragma once
#include <iostream>
#include <list>
using namespace std;

class Stuff;

class WorkingSchedule
{
private:
	list<Stuff*> stuffs;

public:
	WorkingSchedule();
	~WorkingSchedule();

	void attach(Stuff *stuff);
	void notifyALLStuff();
};

