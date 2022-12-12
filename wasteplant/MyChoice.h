#pragma once

#include <iostream>
using namespace std;

class ChoiceTrash;
class MyChoice
{
private:
	std::string choice;
public:
	MyChoice();
	~MyChoice();
	void setChoice(string c);
	std::string getChoice();
	//ChoiceTrash* saveChoiceToChoiceTrash();
	void getChoiceFromChoiceTrash(ChoiceTrash old);
};

