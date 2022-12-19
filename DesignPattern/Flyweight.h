#pragma once
/*
实现模式：享元模式、桥梁模式
*/
#include"ymyHeader.h"
#include"Decoration.h"

//种类类，抽象类
class Kind {
public:
	virtual void unmake() = 0;
	virtual void make() = 0;
};

//包装类，抽象类，大包装和小包装的父类
class Package {
public:
	virtual void unmake() = 0;
	virtual void make() = 0;
};

//生产硬质塑料
class RigidPlasticKind :public Kind {
public:
	virtual void make();
	virtual void unmake();
};

//生产软质塑料
class SoftPlasticKind :public Kind {
	virtual void make();
	virtual void unmake();
};

//增加新的尺寸：中型包装
class MiddlePiece :public Package {
public:
	MiddlePiece(Kind* k) :kind(k) {}
	virtual void make();
	virtual void unmake();
private:
	Kind* kind;
};

//通过哈希表匹配需要生产或管理的包裹类型
class Factory {
public:
	Factory() {}
	Piece* GetFlyweights(string key);
private:
	map<string, Piece_pack*> flyweights;
};