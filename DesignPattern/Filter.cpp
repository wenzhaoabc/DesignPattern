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

	garbages.push_back(new Garbage("���ϴ�", Dry));
	garbages.push_back(new Garbage("���ͷ", Dry));
	garbages.push_back(new Garbage("ʣ��", Wet));
	garbages.push_back(new Garbage("��Ƥ", Wet));
	garbages.push_back(new Garbage("һ��ֲ��", Wet));
	garbages.push_back(new Garbage("ֽ��", Recoverable));
	garbages.push_back(new Garbage("����ƿ", Recoverable));
	garbages.push_back(new Garbage("�ϵ��", Harmful));
	garbages.push_back(new Garbage("ӫ���", Harmful));
	garbages.push_back(new Garbage("���ڵ���������", Harmful));

	Bin* dryBin = new DryBin();
	Bin* wetBin = new WetBin();
	Bin* recoverableBin = new RecoverableBin();
	Bin* harmfulBin = new HarmfulBin();

	cout << "��������" << endl;
	printGarbages(dryBin->filter(garbages));
	cout << endl;

	cout << "ʪ������" << endl;
	printGarbages(wetBin->filter(garbages));
	cout << endl;

	cout << "�ɻ���������" << endl;
	printGarbages(recoverableBin->filter(garbages));
	cout << endl;

	cout << "�к�������" << endl;
	printGarbages(harmfulBin->filter(garbages));
	cout << endl;

	return 0;
}
