#include"Decoration.h"

//包裹包装接口类的成员函数，说明对包裹进行了包装
void Piece_pack::show() {
	//包裹包装函数，说明如何对包裹进行包装
	piece->show();
	piece->show();
}
//继承包裹包装类，将包裹包装成小包裹的成员函数
void SmallPiece::show() {
	cout << "可回收小包裹:show:";
	piece->show();
	//包裹包装函数
	pack(piece);
}
//小包裹包装函数
void SmallPiece::pack(Piece* piece) {
	cout << "(small)(使用装饰器模式，对包裹进行包装)" << endl;
}
//继承包裹包装类，将包裹包装成大包裹的成员函数
void BigPiece::show() {
	cout << "可回收大包裹:show:";
	piece->show();
	pack(piece);
}
//小包裹包装函数
void BigPiece::pack(Piece* piece) {
	cout << "(big)(使用装饰器模式，对包裹进行包装)" << endl;
}
