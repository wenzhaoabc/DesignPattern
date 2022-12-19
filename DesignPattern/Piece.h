#pragma once
using namespace std;
//ymy 2022.12.15

//Piece指可回收垃圾处理完再利用的包裹，为与后续包装操作Pack区分，使用Piece指代
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

//塑料可回收包裹
class PlasticPiece :public Piece {
public:
	PlasticPiece() { price = 0; produce_time = 0; }
	PlasticPiece(int p, int pt);
	virtual void show() {
		cout << endl;
	};
};

//纸质可回收包裹
class PaperPiece :public Piece {
public:
	PaperPiece() { price = 0; produce_time = 0; }
	PaperPiece(int p, int pt);
	virtual void show() {
		cout << endl;
	};
};


