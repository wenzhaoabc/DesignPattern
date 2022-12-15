#pragma once
//ymy 2022.12.15

class Employee
{
private:
    int id;    //ID
    char* name; //����
    int type;   //���֣�1��director��������2��manager������3��clerk��ְԱ
public:
    Employee();                        //�����Ա
    ~Employee();                        //������Ա
    Employee(int id, char* name, int type);
    void Set_id(int id);            //����id
    void Set_name(char* name);        //��������
    void Set_type(int type);        //����ְλ
    int return_type();                //����ְλ
    int return_id();                //����id
    char* return_name();            //��������
    Employee* next;                    //����һ�����Աָ����һ�����Ա
};

struct EmployeeData
{
    int listsize;                    //��ų�Ա�ĸ���                                                                
    Employee* m_head;                //����һ��Employee��ͷ�ڵ�
};

Employee* Employee_Link(EmployeeData* list, Employee* other);                                         //��Ա���
Employee* Employee_Delete(EmployeeData* list);                                                        //��Աɾ��
Employee* Employee_Select(EmployeeData* list);                                                        //��Ա����
Employee* Employee_Set(EmployeeData* list);                                                           //��Ա�޸�
Employee* Employee_Show(EmployeeData* list);                                                          //��Ա����
void  init_Employee_Data_m_head(EmployeeData* list);                                                  //��ʼ��ͷ���
Employee* init_Employee();                                                                            //��ʼ��һ����
EmployeeData* Free_Employee(EmployeeData*list);                                                       //��Ա���