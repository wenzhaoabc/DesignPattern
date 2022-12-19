#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Visitor.h"

class WasteScreening
{
private:
	std::string text;
public:
	WasteScreening();
	~WasteScreening();
	virtual void accept(MyVisitor* visitor);
	void read(std::string file);
	std::string getContent();
};

class LandFill :public WasteScreening {
public:
	LandFill();
	~LandFill();
	//void read(std::string file);
	virtual void accept(MyVisitor* visitor);
	//std::string getContent();
};

class Stale :public WasteScreening
{
public:
	Stale();
	~Stale();
	//void read(std::string file);
	virtual void accept(MyVisitor* visitor);
	//std::string getContent();

};

class Industrial :public WasteScreening {
public:
	Industrial();
	~Industrial();
	//void read(std::string file);
	virtual void accept(MyVisitor* visitor);
	//std::string getContent();
};

class Decoration :public WasteScreening {
public:
	Decoration();
	~Decoration();
	//void read(std::string file);
	virtual void accept(MyVisitor* visitor);
	//std::string getContent();
};
