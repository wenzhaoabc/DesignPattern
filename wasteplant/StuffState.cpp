#include "StuffState.h"
#include "Stuff.h"

OnDuty::OnDuty()
{
	this->setStateDescription("on duty");
}

OnDuty::~OnDuty()
{
}

void OnDuty::doAction(Stuff* stuff)
{
	if(stuff->getState() == nullptr || stuff->getState()->getStateDescription() != "on duty")
	{
		stuff->setState(*this);
	}
	else
	{
		cout << "stuff have been on duty" << endl;
	}
	return;
}

OffDuty::OffDuty()
{
	this->setStateDescription("off duty");
}

OffDuty::~OffDuty()
{
}

void OffDuty::doAction(Stuff* stuff)
{
	if (stuff->getState() == nullptr || stuff->getState()->getStateDescription() != "off duty")
	{
		stuff->setState(*this);
	}
	else
	{
		cout << "stuff have been off duty" << endl;
	}
	return;
}

void StuffState::setStateDescription(string d)
{
	this->description = d;
}

StuffState::StuffState()
{
}

StuffState::~StuffState()
{
}

void StuffState::doAction(Stuff* stuff)
{
}

string StuffState::getStateDescription()
{
	return description;
}
