#include "MyChoice.h"
#include "ChoiceTrash.h"

MyChoice::MyChoice()
{
}

MyChoice::~MyChoice()
{
}

void MyChoice::setChoice(string c)
{
	this->choice = c;
}

std::string MyChoice::getChoice()
{
	return this->choice;
}

//ChoiceTrash* MyChoice::saveChoiceToChoiceTrash()
//{
//	return new ChoiceTrash(this->choice);
//}

void MyChoice::getChoiceFromChoiceTrash(ChoiceTrash old)
{
	this->choice = old.getChoice();
}
