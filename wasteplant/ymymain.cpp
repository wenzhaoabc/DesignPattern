#include<iostream>
#include"Piece.h"
#include"Decoration.h"
#include"Flyweight.h"
#include"DAO.h"

using namespace std;

void Menu();          //菜单
void Decoration();    //装饰器模式
void Flyweight();     //享元模式
void DAO();           //数据访问对象模式

int main() {
	Menu();

	return 0;
}

void Menu() {
	int choice = -1;
	while (true) {
		cout << " please choose what to show:                  " << endl;
		cout << "===============================================" << endl;
		cout << "                                              " << endl;
		cout << "           1.包装包裹（装饰期模式）          " << endl;
		cout << "           2.生产包裹（享元模式）     " << endl;
		cout << "           3.人员管理（数据访问对象模式）  " << endl;
		cout << "           0.退出                 " << endl;
		cout << "                                              " << endl;
		cout << "                                              " << endl;
		cout << "===============================================" << endl;
		cin >> choice;
		if (!choice)
			return;
		else if (choice == 1)
			Decoration();
		else if (choice == 2)
			Flyweight();
		else if (choice == 3)
			DAO();
		else
			cout << "请正确输入选项！！\n\n";
	}
}

//装饰器模式，用于包装可回收包裹
void Decoration() {
	cout << endl;
	cout << "==========组装包裹!========" << endl;
	Piece* plasticPiece = new PlasticPiece();//实例化一个蔬菜罐头
	Piece* paperPiece = new PaperPiece();//实例化一个肉罐头
	SmallPiece smallPlasticPiece = SmallPiece(plasticPiece);//生产小型蔬菜罐头
	BigPiece bigPaperPiece = BigPiece(paperPiece);//生产大型肉罐头
	smallPlasticPiece.show();
	bigPaperPiece.show();
	cout << "=======================================\n" << endl;
	cout << "\n\n\n";
}

//装饰器模式，用于生产不同大小和内容的包裹
//其中菜单选择部分为外观模式
void Flyweight() {
    cout << "新增加的包裹类型：\n";
	Kind* rigidPlasticKind = new RigidPlasticKind();
	Kind* softPlasticKind = new SoftPlasticKind();
	MiddlePiece* middlePiece = new MiddlePiece(softPlasticKind);   //生产中型软质塑料包裹
	middlePiece->make();
	Factory* factory = new Factory();

	//外观模式
	cout << " \n\n请输入要生产的包裹类型（输入1-4）         " << endl;
	cout << "===============================================" << endl;
	cout << "                                              " << endl;
	cout << "              1.大型纸质包裹          " << endl;
	cout << "              2.小型纸质包裹          " << endl;
	cout << "              3.大型塑料包裹          " << endl;
	cout << "              4.小型塑料包裹          " << endl;
	cout << "                                              " << endl;
	cout << "===============================================" << endl;

	int choice;
	cin >> choice;
	Piece* f;
	if(choice == 1)
		f = factory->GetFlyweights("bigpaper");
	else if(choice == 2)
		f = factory->GetFlyweights("smallpaper");
	else if (choice == 3)
		f = factory->GetFlyweights("bigplastic");
	else if (choice == 4)
		f = factory->GetFlyweights("smallplatic");
	cout << "\n\n\n";
}

//数据访问对象模式，对职工进行增删改查
void DAO()
{
    printf("-------------------职员信息管理系统-----------------------\n");
    printf("1：初始化管理系统\n");
    printf("2：新增一个职员信息并录入\n");
    printf("3：删除一个职员信息\n");
    printf("4：查找一个职员的成绩\n");
    printf("5：修改一个职员的成绩\n");
    printf("6：清空所有职员信息\n");
    printf("7：打印所有职员信息\n");
    printf("8：退出系统\n");
    printf("------------------ 请输入您的选择1-8 -----------------------\n");

    EmployeeData* data = new EmployeeData;
    init_Employee_Data_m_head(data);
    while (1)
    {
        int num;
        cout << "请输入指令（1-8）,按回车确认：";
        cin >> num;
        switch (num)
        {
        case 1:
            //初始化头节点
            init_Employee_Data_m_head(data);
            cout << "当前指令,即将创建一个职员管理系统并初始化\n";
            printf("初始化职员管理系统成功!\n");
            cout << endl;
            break;
        case 2:
            //新增一个职员并初始化
            cout << "当前指令,即将添加一个职员 \n";
            Employee_Link(data, init_Employee());
            cout << endl;
            break;
        case 3:
            //删除一个职员 
            cout << "当前指令,即将删除一个职员 \n";
            Employee_Delete(data);
            cout << endl;
            break;
        case 4:
            //查询某个职员的成绩
            cout << "当前指令,即将查询一个职员 的成绩\n";
            Employee_Select(data);
            cout << endl;
            break;
        case 5:
            //修改某个 的信息
            cout << "当前指令,即将修改一个职员 的成绩\n";
            Employee_Set(data);
            cout << endl;
            break;
        case 6:
            //清空所有职员数据
            cout << "当前指令,即将删除所有数据\n";
            Free_Employee(data);
            cout << endl;
            break;
        case 7:
            //打印所有职员数据
            cout << "当前指令,打印所有 数据\n";
            Employee_Show(data);
            cout << endl;
            break;
        default:
            cout << "输入指令有误，请重新输入！" << endl;
            break;
        }
    }
}