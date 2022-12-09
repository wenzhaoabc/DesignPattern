#include<iostream>
#include "lmq.h"
using namespace std;

	static Stuff stuff1;
	static Stuff stuff2;
	static Stuff stuff3;
void init2(WorkingSchedule* schedule)
{

	stuff1.subjectSchedule(schedule, "hong");
	stuff2.subjectSchedule(schedule, "huang");
	stuff3.subjectSchedule(schedule, "lan");

	return;
}

void init3()
{
	stuff1.setName("hong");
	stuff2.setName("huang");
	stuff3.setName("lan");
}

void setStuffsState(OnDuty& on, OffDuty& off)
{
	if (&on != nullptr)
	{
		on.doAction(&stuff1);
		on.doAction(&stuff2);
	}
	else cout << "error: interface on duty state hasn't been inited!" << endl;
	if (&off != nullptr)
	{
		off.doAction(&stuff3);
	}
	else cout << "error: interface off state hasn't been inited!" << endl;
}

int main()
{
	while (1)
	{
		int choice = -1;
		cout << "please enter a choice:" << endl;
		cout << "1. WasteScreening, designed by visitor pattern" << endl;
		cout << "2. NotifySchudule designed by observer pattern" << endl;
		cout << "3. ModifyStuffState designed by state pattern" << endl;
		cout << "0. quit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			MyVisitor myVisitor;
			myVisitor.chooseProfession();
			break;
		}
		case 2: {
			WorkingSchedule schedule;
			init2(&schedule);
			schedule.notifyALLStuff();
			cout << endl;
			break;
		}
		case 3: {
			init3();
			static OnDuty onDutyState;
			static OffDuty offDutyState;
			setStuffsState(onDutyState, offDutyState);
			cout << endl;
			break;
		}
		case 0: {
			cout << "now you quit the system, bye.";
			return 0;
		}
		default:
			cout << "you have entered an invaild key!" << endl;
			break;
		}
	}
	return 0;
}