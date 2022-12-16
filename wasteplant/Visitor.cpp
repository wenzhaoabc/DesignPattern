#include "Visitor.h"
#include "WasteScreening.h"

#include <iostream>
#include<string>
using namespace std;

MyVisitor::MyVisitor()
{
}

MyVisitor::~MyVisitor()
{
}

void MyVisitor::chooseProfession()
{
	int choice = -1;
	cout << "now choose your question on WasteProfession: ";
	cout << "1. LandFill  2. Stale  3. Industrail  4. Decoration" << endl;
	cout << "you choose: " ;
	cin >> choice;

	switch (choice)
	{
	case 1:
		this->visit(new LandFill());
		break;
	case 2:
		this->visit(new Stale());
		break;
	case 3:
		this->visit(new Industrial());
		break;
	case 4:
		this->visit(new Decoration());
		break;
	default:
		cout << "you input an invaild key!" << endl;
		break;
	}
}

void MyVisitor::visit(LandFill* landFill)
{
	landFill->accept(this);
	std::string s = landFill->getContent();
	cout << s << endl;
	return;
}

void MyVisitor::visit(Stale* stale)
{
	stale->accept(this);
	std::string s = stale->getContent();
	cout << s << endl;
	return;
}

void MyVisitor::visit(Industrial* industrail)
{
	industrail->accept(this);
	std::string s = industrail->getContent();
	cout << s << endl;
	return;
}

void MyVisitor::visit(Decoration* decoration)
{
	decoration->accept(this);
	std::string s = decoration->getContent();
	cout << s << endl;
	return;
}
