//ymy 2022.12.15
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include "DAO.h"
using namespace std;

Employee::Employee()                        //构造成员
{
    id = 0;
    name = new char[50 + 1];
    name = NULL;
}

Employee::~Employee()                        //析构成员
{
    delete[]name;

}

Employee::Employee(int m_id, char* m_name, int m_type)
{
    this->id = m_id;
    name = new char[50];
    type = m_type;
    strcpy(this->name, m_name);
    printf("职工信息创建成功！\n");
}

void Employee::Set_id(int m_id)            //设置id
{
    this->id = m_id;
}

void Employee::Set_name(char* m_name)        //设置姓名
{
    strcpy(this->name, m_name);
}

void Employee::Set_type(int m_type)            //设置职位
{
    this->type = m_type;
}

int Employee::return_id()                //返回id
{
    return id;
}

char* Employee::return_name()            //返回姓名
{
    return name;
}

int Employee::return_type()                //返回职位
{
    return type;
}


//成员添加
Employee* Employee_Link(EmployeeData* list, Employee* other)      //成员添加 从头部添加
{
    //Employee* temp = list->m_head;
    other->next = list->m_head->next;
    list->m_head->next = other;
    list->listsize++;
    return list->m_head;
}

//成员删除
Employee* Employee_Delete(EmployeeData* list)
{
    if (list->listsize == 0) {
        printf("空数据\n");
        return list->m_head;
    }
    Employee* cur = list->m_head->next;   //定义一个指针指向下一个成员
    Employee* pre = list->m_head;        //定义一个指针指向上一个成员

    int id;
    cout << "请输入要删除的职工id：";
    cin >> id;
    while (cur != NULL)
    {
        if (cur->return_id() == id) {
            pre->next = cur->next;             //将上一个节点和下一个节点连接  
            delete cur;                       //将节点释放
            list->listsize--;                    //存储的数据个数减1
            cur = NULL;                            //将指针指向空，防止野指针
            cout << "删除成功\n";
            return list->m_head;
        }
        pre = cur;
        cur = cur->next;
    }
    printf("找不到该职工!\n");
    return list->m_head;
}

//成员查找
Employee* Employee_Select(EmployeeData* list)
{
    if (list->listsize == 0)  //判断存放数据的个数是否为0
    {
        printf("空表\n");
        return list->m_head;
    }
    Employee* temp = list->m_head->next;     //定义一个临时指针指向头节点的下一个节点并遍历链表，默认第一个头节点不打印

    int id;
    cout << "请输入要查找的职工id：";
    cin >> id;
    while (temp != NULL)
    {
        if (temp->return_id() == id)
        {
            cout << "已找到\n " << "该职工的姓名为：" << temp->return_name() << "\n职位是：";
            if (temp->return_type() == 1)
                cout << "厂长\n";
            else if (temp->return_type() == 2)
                cout << "经理\n";
            else if (temp->return_type() == 3)
                cout << "职员\n";
            return list->m_head;
        }
        temp = temp->next;

    }
    printf("找不到该职工!\n");
    return list->m_head;

}

//成员修改
Employee* Employee_Set(EmployeeData* list)
{
    if (list->listsize == 0)  //判断存放数据的个数是否为0
    {
        printf("空数据\n");
        return list->m_head;
    }
    Employee* temp = list->m_head->next;     //定义一个临时指针指向头节点的下一个节点并遍历链表，默认第一个头节点不打印

    int m_id;
    cout << "请输入要修改的职工id：";
    cin >> m_id;
    while (temp != NULL)
    {
        if (temp->return_id() == m_id)
        {
            int mode;
            cout << "请输入要修改的内容（1：修改姓名；2：修改职位）：\n";
            cin >> mode;
            if (mode == 1) {
                char* new_name = new char[50];
                cout << "请输出修改后的姓名：\n";
                cin >> new_name;
                if (new_name == temp->return_name()) {
                    cout << "当前已经是该姓名！";
                    break;
                }
                else {
                    temp->Set_name(new_name);
                    cout << "修改成功！\n";
                    return list->m_head;
                }
            }
            else if (mode == 2) {
                int position;
                while (true) {
                    cout << "请输出修改后的职位（1代表厂长，2代表经理，3代表职工）：\n";
                    cin >> position;
                    if (position == temp->return_type()) {
                        cout << "当前已经是该职位！";
                        break;
                    }
                    if (position == 1) {
                        temp->Set_type(1);
                        cout << "修改成功！\n";
                        return list->m_head;
                    }
                    else if (position == 2) {
                        temp->Set_type(2);
                        cout << "修改成功！\n";
                        return list->m_head;
                    }
                    else if (position == 3) {
                        temp->Set_type(3);
                        cout << "修改成功！\n";
                        return list->m_head;
                    }
                    else {
                        cout << "不合法的输入！请重新输入！\n";
                    }
                }
                temp = temp->next;
            }
        }
        cout << "未找到要修改的数据\n";
        return list->m_head;
    }
}

//成员遍历
Employee* Employee_Show(EmployeeData* list)
{
    if (list == NULL || list->listsize == 0)  //判断存放数据的个数是否为0
    {
        printf("空表\n");
        return list->m_head;
    }
    Employee* temp = list->m_head->next;     //定义一个临时指针指向头节点的下一个节点并遍历链表，默认第一个头节点不打印
    cout << "  职工ID  " << "   姓名   " << "   职位   " << endl;
    while (temp != NULL)
    {
        //打印成员，并将当前成员指针指向下一个成员节点
        cout << "  " << std::left << setw(9) << temp->return_id() << "  " << setw(7) << temp->return_name() << "   ";
        if (temp->return_type() == 1)
            cout << "厂长\n";
        else if (temp->return_type() == 2)
            cout << "经理\n";
        else if (temp->return_type() == 3)
            cout << "职员\n";
        return list->m_head;
        temp = temp->next;
    }
    return list->m_head;
}

//初始化头节点
void  init_Employee_Data_m_head(EmployeeData* list)
{
    //动态申请一个头节点，并初始化，初始化后将头节点的next指向NULL, 数据成员的个数设置为0
    list->m_head = new Employee;
    list->listsize = 0;
    list->m_head->next = NULL;
}

//成员清空
EmployeeData* Free_Employee(EmployeeData* list)
{
    if (list->listsize == 0)  //判断存放数据的个数是否为0
    {
        printf("空表\n");
        return list;
    }
    Employee* temp = list->m_head->next;     //定义一个临时指针指向头节点的下一个节点并遍历链表，默认第一个头节点不打印


    while (temp != NULL)
    {
        //记录一个指针, 并遍历成员逐个释放，最后将指针置为NULL 防止野指针 保留头节点，头节点不用释放
        Employee* pre = temp;
        *pre = *temp;
        temp = temp->next;
        delete pre;
        pre = NULL;
        list->listsize--; //空间大小减一
    }
    list->m_head->next = NULL;
    printf("数据清理完成，数据已清空\n");
    return list;
}

//初始化一个类
Employee* init_Employee()
{
    int id;
    char  name[50];
    int type;
    cout << "请按顺序输入 学号、姓名、职位,每输入一次按回车确认\n";
    cout << "学号(只能输入整数)：";
    cin >> id;
    cout << "姓名：";
    cin >> name;
    cout << "职位(只能输入整数1、2、3)：";
    cin >> type;
    Employee* temp = new Employee(id, name, type);
    return temp;
}