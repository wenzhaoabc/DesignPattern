//ymy 2022.12.15
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include "DAO.h"
using namespace std;

Employee::Employee()                        //�����Ա
{
    id = 0;
    name = new char[50 + 1];
    name = NULL;
}

Employee::~Employee()                        //������Ա
{
    delete[]name;

}

Employee::Employee(int m_id, char* m_name, int m_type)
{
    this->id = m_id;
    name = new char[50];
    type = m_type;
    strcpy(this->name, m_name);
    printf("ְ����Ϣ�����ɹ���\n");
}

void Employee::Set_id(int m_id)            //����id
{
    this->id = m_id;
}

void Employee::Set_name(char* m_name)        //��������
{
    strcpy(this->name, m_name);
}

void Employee::Set_type(int m_type)            //����ְλ
{
    this->type = m_type;
}

int Employee::return_id()                //����id
{
    return id;
}

char* Employee::return_name()            //��������
{
    return name;
}

int Employee::return_type()                //����ְλ
{
    return type;
}


//��Ա���
Employee* Employee_Link(EmployeeData* list, Employee* other)      //��Ա��� ��ͷ�����
{
    //Employee* temp = list->m_head;
    other->next = list->m_head->next;
    list->m_head->next = other;
    list->listsize++;
    return list->m_head;
}

//��Աɾ��
Employee* Employee_Delete(EmployeeData* list)
{
    if (list->listsize == 0) {
        printf("������\n");
        return list->m_head;
    }
    Employee* cur = list->m_head->next;   //����һ��ָ��ָ����һ����Ա
    Employee* pre = list->m_head;        //����һ��ָ��ָ����һ����Ա

    int id;
    cout << "������Ҫɾ����ְ��id��";
    cin >> id;
    while (cur != NULL)
    {
        if (cur->return_id() == id) {
            pre->next = cur->next;             //����һ���ڵ����һ���ڵ�����  
            delete cur;                       //���ڵ��ͷ�
            list->listsize--;                    //�洢�����ݸ�����1
            cur = NULL;                            //��ָ��ָ��գ���ֹҰָ��
            cout << "ɾ���ɹ�\n";
            return list->m_head;
        }
        pre = cur;
        cur = cur->next;
    }
    printf("�Ҳ�����ְ��!\n");
    return list->m_head;
}

//��Ա����
Employee* Employee_Select(EmployeeData* list)
{
    if (list->listsize == 0)  //�жϴ�����ݵĸ����Ƿ�Ϊ0
    {
        printf("�ձ�\n");
        return list->m_head;
    }
    Employee* temp = list->m_head->next;     //����һ����ʱָ��ָ��ͷ�ڵ����һ���ڵ㲢��������Ĭ�ϵ�һ��ͷ�ڵ㲻��ӡ

    int id;
    cout << "������Ҫ���ҵ�ְ��id��";
    cin >> id;
    while (temp != NULL)
    {
        if (temp->return_id() == id)
        {
            cout << "���ҵ�\n " << "��ְ��������Ϊ��" << temp->return_name() << "\nְλ�ǣ�";
            if (temp->return_type() == 1)
                cout << "����\n";
            else if (temp->return_type() == 2)
                cout << "����\n";
            else if (temp->return_type() == 3)
                cout << "ְԱ\n";
            return list->m_head;
        }
        temp = temp->next;

    }
    printf("�Ҳ�����ְ��!\n");
    return list->m_head;

}

//��Ա�޸�
Employee* Employee_Set(EmployeeData* list)
{
    if (list->listsize == 0)  //�жϴ�����ݵĸ����Ƿ�Ϊ0
    {
        printf("������\n");
        return list->m_head;
    }
    Employee* temp = list->m_head->next;     //����һ����ʱָ��ָ��ͷ�ڵ����һ���ڵ㲢��������Ĭ�ϵ�һ��ͷ�ڵ㲻��ӡ

    int m_id;
    cout << "������Ҫ�޸ĵ�ְ��id��";
    cin >> m_id;
    while (temp != NULL)
    {
        if (temp->return_id() == m_id)
        {
            int mode;
            cout << "������Ҫ�޸ĵ����ݣ�1���޸�������2���޸�ְλ����\n";
            cin >> mode;
            if (mode == 1) {
                char* new_name = new char[50];
                cout << "������޸ĺ��������\n";
                cin >> new_name;
                if (new_name == temp->return_name()) {
                    cout << "��ǰ�Ѿ��Ǹ�������";
                    break;
                }
                else {
                    temp->Set_name(new_name);
                    cout << "�޸ĳɹ���\n";
                    return list->m_head;
                }
            }
            else if (mode == 2) {
                int position;
                while (true) {
                    cout << "������޸ĺ��ְλ��1��������2������3����ְ������\n";
                    cin >> position;
                    if (position == temp->return_type()) {
                        cout << "��ǰ�Ѿ��Ǹ�ְλ��";
                        break;
                    }
                    if (position == 1) {
                        temp->Set_type(1);
                        cout << "�޸ĳɹ���\n";
                        return list->m_head;
                    }
                    else if (position == 2) {
                        temp->Set_type(2);
                        cout << "�޸ĳɹ���\n";
                        return list->m_head;
                    }
                    else if (position == 3) {
                        temp->Set_type(3);
                        cout << "�޸ĳɹ���\n";
                        return list->m_head;
                    }
                    else {
                        cout << "���Ϸ������룡���������룡\n";
                    }
                }
                temp = temp->next;
            }
        }
        cout << "δ�ҵ�Ҫ�޸ĵ�����\n";
        return list->m_head;
    }
}

//��Ա����
Employee* Employee_Show(EmployeeData* list)
{
    if (list == NULL || list->listsize == 0)  //�жϴ�����ݵĸ����Ƿ�Ϊ0
    {
        printf("�ձ�\n");
        return list->m_head;
    }
    Employee* temp = list->m_head->next;     //����һ����ʱָ��ָ��ͷ�ڵ����һ���ڵ㲢��������Ĭ�ϵ�һ��ͷ�ڵ㲻��ӡ
    cout << "  ְ��ID  " << "   ����   " << "   ְλ   " << endl;
    while (temp != NULL)
    {
        //��ӡ��Ա��������ǰ��Աָ��ָ����һ����Ա�ڵ�
        cout << "  " << std::left << setw(9) << temp->return_id() << "  " << setw(7) << temp->return_name() << "   ";
        if (temp->return_type() == 1)
            cout << "����\n";
        else if (temp->return_type() == 2)
            cout << "����\n";
        else if (temp->return_type() == 3)
            cout << "ְԱ\n";
        return list->m_head;
        temp = temp->next;
    }
    return list->m_head;
}

//��ʼ��ͷ�ڵ�
void  init_Employee_Data_m_head(EmployeeData* list)
{
    //��̬����һ��ͷ�ڵ㣬����ʼ������ʼ����ͷ�ڵ��nextָ��NULL, ���ݳ�Ա�ĸ�������Ϊ0
    list->m_head = new Employee;
    list->listsize = 0;
    list->m_head->next = NULL;
}

//��Ա���
EmployeeData* Free_Employee(EmployeeData* list)
{
    if (list->listsize == 0)  //�жϴ�����ݵĸ����Ƿ�Ϊ0
    {
        printf("�ձ�\n");
        return list;
    }
    Employee* temp = list->m_head->next;     //����һ����ʱָ��ָ��ͷ�ڵ����һ���ڵ㲢��������Ĭ�ϵ�һ��ͷ�ڵ㲻��ӡ


    while (temp != NULL)
    {
        //��¼һ��ָ��, ��������Ա����ͷţ����ָ����ΪNULL ��ֹҰָ�� ����ͷ�ڵ㣬ͷ�ڵ㲻���ͷ�
        Employee* pre = temp;
        *pre = *temp;
        temp = temp->next;
        delete pre;
        pre = NULL;
        list->listsize--; //�ռ��С��һ
    }
    list->m_head->next = NULL;
    printf("����������ɣ����������\n");
    return list;
}

//��ʼ��һ����
Employee* init_Employee()
{
    int id;
    char  name[50];
    int type;
    cout << "�밴˳������ ѧ�š�������ְλ,ÿ����һ�ΰ��س�ȷ��\n";
    cout << "ѧ��(ֻ����������)��";
    cin >> id;
    cout << "������";
    cin >> name;
    cout << "ְλ(ֻ����������1��2��3)��";
    cin >> type;
    Employee* temp = new Employee(id, name, type);
    return temp;
}