#ifndef	 _Decoration_
#define  _Decoration_

#include "ymyHeader.h"
#include "Piece.h"
//ymy 2022.12.15

//此文件实现了装饰器模式，对可回收包裹进行包装加工
//可回收垃圾包装接口，继承了包裹类
class Piece_pack :public Piece {
protected:
	//成员变量包裹
	Piece* piece;
public:
	//构造函数，传入要进行包装的包裹
	Piece_pack(Piece* c) { this->piece = c; }
	//展示包裹种类
	void show();
};


//小包裹包装类，实现了包裹包装接口
class SmallPiece :public Piece_pack {
public:
	//构造函数，传入要进行包装成小包裹的包裹
	SmallPiece(Piece* piece) :Piece_pack(piece) {}
	//展示包裹的种类
	void show();
private:
	//包装成小包裹
	void pack(Piece* piece);
};


//大包裹包装类，实现了包裹包装接口
class BigPiece :public Piece_pack {
public:
	//构造函数，传入要进行包装成大包裹的包裹
	BigPiece(Piece* piece) :Piece_pack(piece) {}
	//展示包裹的种类
	void show();
private:
	//包装成大包裹
	void pack(Piece* piece);
};

#endif