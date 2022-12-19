#include<iostream>
#include "factory.h"
#include"Proxy.h"
#include"FrontController.h"
#include"Command.h"
#include"ChainOfResponsibility.h"

using namespace std;
int lyr_main() {
	ProxyPatternDemo();
	
	CommandPatternDemo();

	ChainOfReponsibilityPatternDemo();

	FrontControllerPatternDemo();

	return 0;
}