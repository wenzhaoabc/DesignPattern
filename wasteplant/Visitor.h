#pragma once

class WasteScreening;
class LandFill;
class Stale;
class Industrial;
class Decoration;

class MyVisitor
{
public:
	MyVisitor();
	~MyVisitor();
	void chooseProfession();
	void visit(LandFill* landFill);
	void visit(Stale* stale);
	void visit(Industrial* industrail);
	void visit(Decoration* decoration);
};




