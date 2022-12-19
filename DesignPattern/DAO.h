#pragma once
//ymy 2022.12.15

class Employee
{
private:
    int id;    //ID
    char* name; //姓名
    int type;   //工种，1：director，厂长；2：manager，经理；3：clerk，职员
public:
    Employee();                        //构造成员
    ~Employee();                        //析构成员
    Employee(int id, char* name, int type);
    void Set_id(int id);            //设置id
    void Set_name(char* name);        //设置姓名
    void Set_type(int type);        //设置职位
    int return_type();                //返回职位
    int return_id();                //返回id
    char* return_name();            //返回姓名
    Employee* next;                    //定义一个类成员指向下一个类成员
};

struct EmployeeData
{
    int listsize;                    //存放成员的个数                                                                
    Employee* m_head;                //定义一个Employee的头节点
};

Employee* Employee_Link(EmployeeData* list, Employee* other);                                         //成员添加
Employee* Employee_Delete(EmployeeData* list);                                                        //成员删除
Employee* Employee_Select(EmployeeData* list);                                                        //成员查找
Employee* Employee_Set(EmployeeData* list);                                                           //成员修改
Employee* Employee_Show(EmployeeData* list);                                                          //成员遍历
void  init_Employee_Data_m_head(EmployeeData* list);                                                  //初始化头结点
Employee* init_Employee();                                                                            //初始化一个类
EmployeeData* Free_Employee(EmployeeData*list);                                                       //成员清空