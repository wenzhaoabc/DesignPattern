#include"Filter.h"

list<Garbage*>DryBin::filter(list<Garbage*>garbages)
{
	list<Garbage*> listGarbage;
	for (auto it : garbages)
	{
		if (it->getType() == Dry)
		{
			listGarbage.push_back(it);
		}
	}
	return listGarbage;
}

list<Garbage*>WetBin::filter(list<Garbage*>garbages)
{
	list<Garbage*> listGarbage;
	for (auto it : garbages)
	{
		if (it->getType() == Wet)
		{
			listGarbage.push_back(it);
		}
	}
	return listGarbage;
}

list<Garbage*>RecoverableBin::filter(list<Garbage*>garbages)
{
	list<Garbage*> listGarbage;
	for (auto it : garbages)
	{
		if (it->getType() == Recoverable)
		{
			listGarbage.push_back(it);
		}
	}
	return listGarbage;
}

list<Garbage*>HarmfulBin::filter(list<Garbage*>garbages)
{
	list<Garbage*> listGarbage;
	for (auto it : garbages)
	{
		if (it->getType() == Harmful)
		{
			listGarbage.push_back(it);
		}
	}
	return listGarbage;
}

void printGarbages(list<Garbage*>garbages)
{
	for (auto it : garbages)
	{
		cout << it->getName() << "  ";
	}
	cout << endl;
}

int test_filter()
{
	list<Garbage*> garbages;

	garbages.push_back(new Garbage("塑料袋", Dry));
	garbages.push_back(new Garbage("大骨头", Dry));
	garbages.push_back(new Garbage("剩饭", Wet));
	garbages.push_back(new Garbage("瓜皮", Wet));
	garbages.push_back(new Garbage("一种植物", Wet));
	garbages.push_back(new Garbage("纸箱", Recoverable));
	garbages.push_back(new Garbage("塑料瓶", Recoverable));
	garbages.push_back(new Garbage("废电池", Harmful));
	garbages.push_back(new Garbage("荧光灯", Harmful));
	garbages.push_back(new Garbage("过期的连花清瘟", Harmful));

	Bin* dryBin = new DryBin();
	Bin* wetBin = new WetBin();
	Bin* recoverableBin = new RecoverableBin();
	Bin* harmfulBin = new HarmfulBin();

	cout << "干垃圾：" << endl;
	printGarbages(dryBin->filter(garbages));
	cout << endl;

	cout << "湿垃圾：" << endl;
	printGarbages(wetBin->filter(garbages));
	cout << endl;

	cout << "可回收垃圾：" << endl;
	printGarbages(recoverableBin->filter(garbages));
	cout << endl;

	cout << "有害垃圾：" << endl;
	printGarbages(harmfulBin->filter(garbages));
	cout << endl;

	return 0;
}
