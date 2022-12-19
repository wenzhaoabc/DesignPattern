#pragma once
#include<string>
#include"GarbageType.h"

class Garbage
{
public:
	void setName(std::string name) { this->name = name; }
	std::string getName() { return this->name; }
	void setType(GARBAGE_TYPE type) { this->type = type; }
	int getType() { return this->type; }
	Garbage(std::string name, GARBAGE_TYPE type) :name(name), type(type) {};
private:
	std::string name;
	GARBAGE_TYPE type;
};
