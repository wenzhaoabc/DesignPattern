#include<iostream>
#include"Piece.h"
#include"Decoration.h"
#include"Flyweight.h"
#include"DAO.h"

using namespace std;

void Menu();          //�˵�
void Decoration();    //װ����ģʽ
void Flyweight();     //��Ԫģʽ
void DAO();           //���ݷ��ʶ���ģʽ

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
		cout << "           1.��װ������װ����ģʽ��          " << endl;
		cout << "           2.������������Ԫģʽ��     " << endl;
		cout << "           3.��Ա�������ݷ��ʶ���ģʽ��  " << endl;
		cout << "           0.�˳�                 " << endl;
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
			cout << "����ȷ����ѡ���\n\n";
	}
}

//װ����ģʽ�����ڰ�װ�ɻ��հ���
void Decoration() {
	cout << endl;
	cout << "==========��װ����!========" << endl;
	Piece* plasticPiece = new PlasticPiece();//ʵ����һ���߲˹�ͷ
	Piece* paperPiece = new PaperPiece();//ʵ����һ�����ͷ
	SmallPiece smallPlasticPiece = SmallPiece(plasticPiece);//����С���߲˹�ͷ
	BigPiece bigPaperPiece = BigPiece(paperPiece);//�����������ͷ
	smallPlasticPiece.show();
	bigPaperPiece.show();
	cout << "=======================================\n" << endl;
	cout << "\n\n\n";
}

//װ����ģʽ������������ͬ��С�����ݵİ���
//���в˵�ѡ�񲿷�Ϊ���ģʽ
void Flyweight() {
    cout << "�����ӵİ������ͣ�\n";
	Kind* rigidPlasticKind = new RigidPlasticKind();
	Kind* softPlasticKind = new SoftPlasticKind();
	MiddlePiece* middlePiece = new MiddlePiece(softPlasticKind);   //���������������ϰ���
	middlePiece->make();
	Factory* factory = new Factory();

	//���ģʽ
	cout << " \n\n������Ҫ�����İ������ͣ�����1-4��         " << endl;
	cout << "===============================================" << endl;
	cout << "                                              " << endl;
	cout << "              1.����ֽ�ʰ���          " << endl;
	cout << "              2.С��ֽ�ʰ���          " << endl;
	cout << "              3.�������ϰ���          " << endl;
	cout << "              4.С�����ϰ���          " << endl;
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

//���ݷ��ʶ���ģʽ����ְ��������ɾ�Ĳ�
void DAO()
{
    printf("-------------------ְԱ��Ϣ����ϵͳ-----------------------\n");
    printf("1����ʼ������ϵͳ\n");
    printf("2������һ��ְԱ��Ϣ��¼��\n");
    printf("3��ɾ��һ��ְԱ��Ϣ\n");
    printf("4������һ��ְԱ�ĳɼ�\n");
    printf("5���޸�һ��ְԱ�ĳɼ�\n");
    printf("6���������ְԱ��Ϣ\n");
    printf("7����ӡ����ְԱ��Ϣ\n");
    printf("8���˳�ϵͳ\n");
    printf("------------------ ����������ѡ��1-8 -----------------------\n");

    EmployeeData* data = new EmployeeData;
    init_Employee_Data_m_head(data);
    while (1)
    {
        int num;
        cout << "������ָ�1-8��,���س�ȷ�ϣ�";
        cin >> num;
        switch (num)
        {
        case 1:
            //��ʼ��ͷ�ڵ�
            init_Employee_Data_m_head(data);
            cout << "��ǰָ��,��������һ��ְԱ����ϵͳ����ʼ��\n";
            printf("��ʼ��ְԱ����ϵͳ�ɹ�!\n");
            cout << endl;
            break;
        case 2:
            //����һ��ְԱ����ʼ��
            cout << "��ǰָ��,�������һ��ְԱ \n";
            Employee_Link(data, init_Employee());
            cout << endl;
            break;
        case 3:
            //ɾ��һ��ְԱ 
            cout << "��ǰָ��,����ɾ��һ��ְԱ \n";
            Employee_Delete(data);
            cout << endl;
            break;
        case 4:
            //��ѯĳ��ְԱ�ĳɼ�
            cout << "��ǰָ��,������ѯһ��ְԱ �ĳɼ�\n";
            Employee_Select(data);
            cout << endl;
            break;
        case 5:
            //�޸�ĳ�� ����Ϣ
            cout << "��ǰָ��,�����޸�һ��ְԱ �ĳɼ�\n";
            Employee_Set(data);
            cout << endl;
            break;
        case 6:
            //�������ְԱ����
            cout << "��ǰָ��,����ɾ����������\n";
            Free_Employee(data);
            cout << endl;
            break;
        case 7:
            //��ӡ����ְԱ����
            cout << "��ǰָ��,��ӡ���� ����\n";
            Employee_Show(data);
            cout << endl;
            break;
        default:
            cout << "����ָ���������������룡" << endl;
            break;
        }
    }
}