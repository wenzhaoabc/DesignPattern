#pragma once
using namespace std;
//ymy 2022.12.15

//Pieceָ�ɻ������������������õİ�����Ϊ�������װ����Pack���֣�ʹ��Pieceָ��
class Piece {
public:
	Piece() { price = 0; produce_time = 0; }
	Piece(int p, int pt) :price(p), produce_time(pt) {}
	virtual void show() = 0;
	void setprice(int);
	int  getbigprice();
	int getsmallprice();
	int getprotime();
protected:
	int price;
	int produce_time;
};

//���Ͽɻ��հ���
class PlasticPiece :public Piece {
public:
	PlasticPiece() { price = 0; produce_time = 0; }
	PlasticPiece(int p, int pt);
	virtual void show() {
		cout << endl;
	};
};

//ֽ�ʿɻ��հ���
class PaperPiece :public Piece {
public:
	PaperPiece() { price = 0; produce_time = 0; }
	PaperPiece(int p, int pt);
	virtual void show() {
		cout << endl;
	};
};


