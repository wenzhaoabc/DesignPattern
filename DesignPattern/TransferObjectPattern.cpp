#include <iostream>
#include <string>
#include <vector>
using namespace std;
//创建传输对象StaffVO类
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
    string name;//员工姓名
    int salary;//员工薪资
    int number;//员工工号
    string post;//员工职位

};
//创建业务对象StaffBO类
class StaffBO {
public:
    //新建数据库
    StaffBO() {
        StaffVO* staff1 = new StaffVO("Robert",10000,123,"普通工人");
        StaffVO* staff2 = new StaffVO("John",15000,456,"车间主任");
        staffs.push_back(staff1);
        staffs.push_back(staff2);
    }
    //从数据库中删除某位员工,根据员工工号
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
            cout << "不存在该同学，删除失败！" << endl;
        }
    }

    //从数据库中检索员工名单
    vector<StaffVO*> getAllStaffs() {
        return staffs;
    }
    //返回对应工号的员工
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
            cout << "不存在该员工，查找失败！" << endl;
            return NULL;
        }
    }
    //向数据库中更新员工信息，根据工号修改员工其他信息
    void updateStaff(string names, int salarys, int numbers, string posts) {
        if (getStaff(numbers) == NULL)
        {
            return;
        }
        StaffVO* staff = getStaff(numbers);
        staff->setName(names);
        staff->setPost(posts);
        staff->setSalary(salarys);
        cout << "成功更新员工信息： 姓名：" <<staff->getName()<<"工号：" << staff->getNumber() <<"薪水： " << staff->getSalary()<<"职位： " << staff->getPost() << endl;
    }
private:
    //向量是当作一个数据库
    vector<StaffVO*> staffs;


};
//使用 StaffBO 来演示传输对象设计模式。
//创建TransferObjectPatternDemo函数演示传输对象模式
void TransferObjectPatternDemo() 
{
   
    StaffBO* staffBusinessObject = new StaffBO();

       
    cout << "输出所有的员工" << endl;
     vector<StaffVO*> staffs = staffBusinessObject->getAllStaffs();
    
     for (int i = 0; i < staffs.size(); i++)
     {
         cout << "员工信息： 姓名：" << staffs[i]->getName() << "工号：" << staffs[i]->getNumber() << "薪水： " << staffs[i]->getSalary() << "职位： " << staffs[i]->getPost() << endl;
     }
       

        
     cout << "更新员工,将工号为123的员工姓名更改为Jenny,薪水更新为12000，职位不变" << endl;
      staffBusinessObject->updateStaff("Jenny",12000,123, staffBusinessObject->getStaff(123)->getPost());
      cout << "获取学生,将工号为123的员工信息打印出来" << endl;
       
      StaffVO* staff = staffBusinessObject->getStaff(123);
      if (staff != NULL) {
          cout << "员工姓名：" << staff->getName() << "工号：" << staff->getNumber() << "薪水： " << staff->getSalary() << "职位： " << staff->getPost() << endl;
      }
      
    
}
