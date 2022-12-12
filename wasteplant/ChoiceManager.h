#pragma once

#include <iostream>
#include <list>
using namespace std;
class ChoiceTrash;
class ChoiceManager
{
private:
	list<ChoiceTrash>  choice_list;
public:
	ChoiceManager();
	~ChoiceManager();
	void add(string trash);
	ChoiceTrash get(int index);

};

