#include "Stuff.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void Stuff::setName(string n)
{
	this->name = n;
	return;
}

void Stuff::subjectSchedule(WorkingSchedule *schedule, string n)
{
	this->setName(n);
	this->schedule = schedule;
	this->schedule->attach(this);
}

void Stuff::update()
{
	//read the schedule;
	string tmp;
	string tmp2;
	ifstream s;
	s.open(".\\text\\schedule.txt",ios::in);
	while (getline(s,tmp))
	{
		tmp2 = tmp;
		if (this->name!="" && tmp.find(this->name) != string::npos) {
			cout << tmp2 << endl;
			break;
		}
	}
	s.close();
	//cout << "error: no find " << this->name << " in the working schedule." << endl;
	return;
}

void Stuff::setState(StuffState state)
{
	this->state = state;
	cout << "stuff " << this->name << " is now " << this->state.getStateDescription() << endl;
}

StuffState* Stuff::getState()
{
	return &(this->state);
}
