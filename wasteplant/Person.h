#pragma once
#include <string>
class Person
{
public:
	void setName(std::string name) { this->name = name; }
	void setId(std::string id) { this->id = id; }
	std::string getName() { return this->name; }
	std::string getId() { return this->id; }

private:
	std::string  id;
	std::string name;
};
