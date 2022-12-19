#include "Flyweight.h"

/*
*函数：MiddlePiece::make
*参数：null
*功能：生产中等型号包裹
*/
void MiddlePiece::make() {
	kind->make();
	cout << "中型包裹" << endl;
}

/*
*函数：RigidPlasticKind::make
*参数：null
*功能：生产硬质塑料包裹
*/
void RigidPlasticKind::make() {
	cout << "生产硬质塑料包裹 ";
}

/*
*函数：SoftPlasticKind::make
*参数：null
*功能：生产软质塑料包裹
*/
void SoftPlasticKind::make() {
	cout << "生产软质塑料包裹 ";
}

/*
*函数：RigidPlasticKind
*参数：null
*功能：撤销硬质塑料包裹
*/
void RigidPlasticKind::unmake() {
	cout << "撤销硬质塑料包裹" << endl;
}
/*
*函数：FishKind::unmake
*参数：null
*功能：撤销软质塑料包裹
*/
void SoftPlasticKind::unmake() {
	cout << "撤销软质塑料包裹" << endl;
}
/*
*函数：MiddlePiece::unmake
*参数：null
*功能：撤销中型包裹
*/
void MiddlePiece::unmake() {
	cout << "撤销中型包裹" << endl;
}
/*
*函数：Factory
*参数：string key
*功能：如果没有需要的类型的包裹，则通过需求生产对应的包裹；如果已经有此类包裹，则返回此类包裹Piece
*/
Piece* Factory::GetFlyweights(string key) {
	if (flyweights.count(key) == 0)
	{
		string str = "";
		Piece_pack* c;
		if (key == "bigplastic") {
			c = new BigPiece(new PlasticPiece());
			str = "大型塑料包裹";
		}
		else if (key == "smallplastic") {
			c = new SmallPiece(new PlasticPiece());
			str = "小型塑料包裹";
		}
		else if (key == "bigpaper") {
			c = new BigPiece(new PaperPiece());
			str = "大型纸质包裹";
		}
		else if (key == "smallpaper") {
			c = new SmallPiece(new PaperPiece());
			str = "小型纸质包裹";
		}
		flyweights.insert(make_pair(key, c));
		cout << "Factory:GetFlyweights:将新的类型\"" << str << "\"加入到工厂中" << endl;
	}
	else
		cout << "Factory:GetFlyweights:该类型已存在，使用已有类型" << endl;
	return (Piece*)flyweights[key];
}
