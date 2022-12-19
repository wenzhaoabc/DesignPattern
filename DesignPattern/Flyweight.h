#pragma once
/*
ʵ��ģʽ����Ԫģʽ������ģʽ
*/
#include"ymyHeader.h"
#include"Decoration.h"

//�����࣬������
class Kind {
public:
	virtual void unmake() = 0;
	virtual void make() = 0;
};

//��װ�࣬�����࣬���װ��С��װ�ĸ���
class Package {
public:
	virtual void unmake() = 0;
	virtual void make() = 0;
};

//����Ӳ������
class RigidPlasticKind :public Kind {
public:
	virtual void make();
	virtual void unmake();
};

//������������
class SoftPlasticKind :public Kind {
	virtual void make();
	virtual void unmake();
};

//�����µĳߴ磺���Ͱ�װ
class MiddlePiece :public Package {
public:
	MiddlePiece(Kind* k) :kind(k) {}
	virtual void make();
	virtual void unmake();
private:
	Kind* kind;
};

//ͨ����ϣ��ƥ����Ҫ���������İ�������
class Factory {
public:
	Factory() {}
	Piece* GetFlyweights(string key);
private:
	map<string, Piece_pack*> flyweights;
};