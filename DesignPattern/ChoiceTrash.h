#pragma once

#include <iostream>
#include "MyChoice.h"
using namespace std;

class ChoiceTrash
{
private:
	std::string choice;
public:
	ChoiceTrash(string c);
	~ChoiceTrash();
	std::string getChoice();
};

