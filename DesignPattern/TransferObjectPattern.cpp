#include <iostream>
#include <string>
#include <vector>
using namespace std;
//�����������StaffVO��
class StaffVO {
public:
   
    StaffVO(string names, int salarys,int numbers,string posts) {
        name = names;
        salary = salarys;
        number = numbers;
        post = posts;
    }
    string getName() {
        return name;
    }
    void setName(string names) {
        name = names;
    }
    int getSalary() {
        return salary;
    }

    void setSalary(int salarys) {
        salary = salarys;
    }
    int getNumber() {
        return number;
    }

    void setNumber(int numbers) {
        number = numbers;
    }
    string getPost() {
        return post;
    }
    void setPost(string posts) {
        post = posts;
    }
private:
    string name;//Ա������
    int salary;//Ա��н��
    int number;//Ա������
    string post;//Ա��ְλ

};
//����ҵ�����StaffBO��
class StaffBO {
public:
    //�½����ݿ�
    StaffBO() {
        StaffVO* staff1 = new StaffVO("Robert",10000,123,"��ͨ����");
        StaffVO* staff2 = new StaffVO("John",15000,456,"��������");
        staffs.push_back(staff1);
        staffs.push_back(staff2);
    }
    //�����ݿ���ɾ��ĳλԱ��,����Ա������
    void deleteStaff(int number) {
        int i = 0;
        for (; i < staffs.size(); i++)
        {
            if (staffs[i]->getNumber() == number)
            {
                staffs.erase(staffs.begin() + i, staffs.begin() + i + 1);
            }
        }
        if (i = staffs.size())
        {
            cout << "�����ڸ�ͬѧ��ɾ��ʧ�ܣ�" << endl;
        }
    }

    //�����ݿ��м���Ա������
    vector<StaffVO*> getAllStaffs() {
        return staffs;
    }
    //���ض�Ӧ���ŵ�Ա��
    StaffVO* getStaff(int number) {
        int i = 0;
        for (; i < staffs.size(); i++)
        {
            if (staffs[i]->getNumber() == number)
            {
                return staffs[i];
            }
        }
        if (i = staffs.size())
        {
            cout << "�����ڸ�Ա��������ʧ�ܣ�" << endl;
            return NULL;
        }
    }
    //�����ݿ��и���Ա����Ϣ�����ݹ����޸�Ա��������Ϣ
    void updateStaff(string names, int salarys, int numbers, string posts) {
        if (getStaff(numbers) == NULL)
        {
            return;
        }
        StaffVO* staff = getStaff(numbers);
        staff->setName(names);
        staff->setPost(posts);
        staff->setSalary(salarys);
        cout << "�ɹ�����Ա����Ϣ�� ������" <<staff->getName()<<"���ţ�" << staff->getNumber() <<"нˮ�� " << staff->getSalary()<<"ְλ�� " << staff->getPost() << endl;
    }
private:
    //�����ǵ���һ�����ݿ�
    vector<StaffVO*> staffs;


};
//ʹ�� StaffBO ����ʾ����������ģʽ��
//����TransferObjectPatternDemo������ʾ�������ģʽ
void TransferObjectPatternDemo() 
{
   
    StaffBO* staffBusinessObject = new StaffBO();

       
    cout << "������е�Ա��" << endl;
     vector<StaffVO*> staffs = staffBusinessObject->getAllStaffs();
    
     for (int i = 0; i < staffs.size(); i++)
     {
         cout << "Ա����Ϣ�� ������" << staffs[i]->getName() << "���ţ�" << staffs[i]->getNumber() << "нˮ�� " << staffs[i]->getSalary() << "ְλ�� " << staffs[i]->getPost() << endl;
     }
       

        
     cout << "����Ա��,������Ϊ123��Ա����������ΪJenny,нˮ����Ϊ12000��ְλ����" << endl;
      staffBusinessObject->updateStaff("Jenny",12000,123, staffBusinessObject->getStaff(123)->getPost());
      cout << "��ȡѧ��,������Ϊ123��Ա����Ϣ��ӡ����" << endl;
       
      StaffVO* staff = staffBusinessObject->getStaff(123);
      if (staff != NULL) {
          cout << "Ա��������" << staff->getName() << "���ţ�" << staff->getNumber() << "нˮ�� " << staff->getSalary() << "ְλ�� " << staff->getPost() << endl;
      }
      
    
}
