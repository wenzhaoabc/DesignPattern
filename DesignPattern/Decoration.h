#ifndef	 _Decoration_
#define  _Decoration_

#include "ymyHeader.h"
#include "Piece.h"
//ymy 2022.12.15

//���ļ�ʵ����װ����ģʽ���Կɻ��հ������а�װ�ӹ�
//�ɻ���������װ�ӿڣ��̳��˰�����
class Piece_pack :public Piece {
protected:
	//��Ա��������
	Piece* piece;
public:
	//���캯��������Ҫ���а�װ�İ���
	Piece_pack(Piece* c) { this->piece = c; }
	//չʾ��������
	void show();
};


//С������װ�࣬ʵ���˰�����װ�ӿ�
class SmallPiece :public Piece_pack {
public:
	//���캯��������Ҫ���а�װ��С�����İ���
	SmallPiece(Piece* piece) :Piece_pack(piece) {}
	//չʾ����������
	void show();
private:
	//��װ��С����
	void pack(Piece* piece);
};


//�������װ�࣬ʵ���˰�����װ�ӿ�
class BigPiece :public Piece_pack {
public:
	//���캯��������Ҫ���а�װ�ɴ�����İ���
	BigPiece(Piece* piece) :Piece_pack(piece) {}
	//չʾ����������
	void show();
private:
	//��װ�ɴ����
	void pack(Piece* piece);
};

#endif