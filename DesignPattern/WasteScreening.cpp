#include "WasteScreening.h"
#include "Visitor.h"
#include <iostream>
#include <fstream>
using namespace std;

WasteScreening::WasteScreening()
{
}

WasteScreening::~WasteScreening()
{
}

void WasteScreening::accept(MyVisitor* visitor)
{
}

void WasteScreening::read(std::string file)
{
	string tmp;
	ifstream f;
	f.open(file, ios::in);
	while (getline(f,tmp))this->text = this->text+tmp+"\r\n";	//¶ÁÈëÎÄ¼þ
	f.close();
	return;
}

string WasteScreening::getContent()
{
	return text;
}

LandFill::LandFill()
{
}

LandFill::~LandFill()
{
}

void LandFill::accept(MyVisitor* visitor)
{
	read(".\\text\\landFill.txt");
}

Stale::Stale()
{
}

Stale::~Stale()
{
}

void Stale::accept(MyVisitor* visitor)
{
	read(".\\text.\\stale.txt");
}

Industrial::Industrial()
{
}

Industrial::~Industrial()
{
}

void Industrial::accept(MyVisitor* visitor)
{
	read(".\\text\\industrail.txt");
}

Decoration::Decoration()
{
}

Decoration::~Decoration()
{
}

void Decoration::accept(MyVisitor* visitor)
{
	read(".\\text\\decoration.txt");
}

