#include"Decoration.h"

//������װ�ӿ���ĳ�Ա������˵���԰��������˰�װ
void Piece_pack::show() {
	//������װ������˵����ζ԰������а�װ
	piece->show();
	piece->show();
}
//�̳а�����װ�࣬��������װ��С�����ĳ�Ա����
void SmallPiece::show() {
	cout << "�ɻ���С����:show:";
	piece->show();
	//������װ����
	pack(piece);
}
//С������װ����
void SmallPiece::pack(Piece* piece) {
	cout << "(small)(ʹ��װ����ģʽ���԰������а�װ)" << endl;
}
//�̳а�����װ�࣬��������װ�ɴ�����ĳ�Ա����
void BigPiece::show() {
	cout << "�ɻ��մ����:show:";
	piece->show();
	pack(piece);
}
//С������װ����
void BigPiece::pack(Piece* piece) {
	cout << "(big)(ʹ��װ����ģʽ���԰������а�װ)" << endl;
}
