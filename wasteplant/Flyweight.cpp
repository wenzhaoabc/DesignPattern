#include "Flyweight.h"

/*
*������MiddlePiece::make
*������null
*���ܣ������е��ͺŰ���
*/
void MiddlePiece::make() {
	kind->make();
	cout << "���Ͱ���" << endl;
}

/*
*������RigidPlasticKind::make
*������null
*���ܣ�����Ӳ�����ϰ���
*/
void RigidPlasticKind::make() {
	cout << "����Ӳ�����ϰ��� ";
}

/*
*������SoftPlasticKind::make
*������null
*���ܣ������������ϰ���
*/
void SoftPlasticKind::make() {
	cout << "�����������ϰ��� ";
}

/*
*������RigidPlasticKind
*������null
*���ܣ�����Ӳ�����ϰ���
*/
void RigidPlasticKind::unmake() {
	cout << "����Ӳ�����ϰ���" << endl;
}
/*
*������FishKind::unmake
*������null
*���ܣ������������ϰ���
*/
void SoftPlasticKind::unmake() {
	cout << "�����������ϰ���" << endl;
}
/*
*������MiddlePiece::unmake
*������null
*���ܣ��������Ͱ���
*/
void MiddlePiece::unmake() {
	cout << "�������Ͱ���" << endl;
}
/*
*������Factory
*������string key
*���ܣ����û����Ҫ�����͵İ�������ͨ������������Ӧ�İ���������Ѿ��д���������򷵻ش������Piece
*/
Piece* Factory::GetFlyweights(string key) {
	if (flyweights.count(key) == 0)
	{
		string str = "";
		Piece_pack* c;
		if (key == "bigplastic") {
			c = new BigPiece(new PlasticPiece());
			str = "�������ϰ���";
		}
		else if (key == "smallplastic") {
			c = new SmallPiece(new PlasticPiece());
			str = "С�����ϰ���";
		}
		else if (key == "bigpaper") {
			c = new BigPiece(new PaperPiece());
			str = "����ֽ�ʰ���";
		}
		else if (key == "smallpaper") {
			c = new SmallPiece(new PaperPiece());
			str = "С��ֽ�ʰ���";
		}
		flyweights.insert(make_pair(key, c));
		cout << "Factory:GetFlyweights:���µ�����\"" << str << "\"���뵽������" << endl;
	}
	else
		cout << "Factory:GetFlyweights:�������Ѵ��ڣ�ʹ����������" << endl;
	return (Piece*)flyweights[key];
}
