#pragma once
#include"Garbage.h"
#include"GarbageType.h"
#include<iostream>
#include<list>
using namespace std;

class Bin
{
public:
	virtual list<Garbage*>filter(list<Garbage*>garbages) = 0;
};

class DryBin :public Bin
{
public:
	virtual list<Garbage*>filter(list<Garbage*>garbages);
};

class WetBin :public Bin
{
public:
	virtual list<Garbage*>filter(list<Garbage*>garbages);
};

class RecoverableBin :public Bin
{
public:
	virtual list<Garbage*>filter(list<Garbage*>garbages);
};

class HarmfulBin :public Bin
{
public:
	virtual list<Garbage*>filter(list<Garbage*>garbages);
};

int test_filter();
void printGarbages(list<Garbage*>garbages);
