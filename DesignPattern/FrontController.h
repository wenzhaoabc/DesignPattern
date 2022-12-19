#pragma once
#include<iostream>

using namespace std;
class HomeView {
public:
    void show()
    {
        cout << "��ʾ�ලԱ�����ֲ�" << endl;
    }
};

class StudentView
{
public:
    void show()
    {
        cout << "��ʾ���˹����ֲ�" << endl;
    }
};
class Dispatcher
{
public:
    Dispatcher()
    {
        studentView = new StudentView();
        homeView = new HomeView();
    }

    void dispatch(string request)
    {
        if ("����" == request)
        {
            studentView->show();
        }
        else
        {
            homeView->show();
        }
    }

private:
    StudentView* studentView;
    HomeView* homeView;
};

class FrontController
{
public:
    FrontController()
    {
        dispatcher = new Dispatcher();
    }

    void dispatchRequest(string request)
    {
        trackRequest(request);  //��¼ÿһ������

        if (isAuthenticUser())    //���û����������֤
        {
            dispatcher->dispatch(request);
        }
    }

private:
    Dispatcher* dispatcher;

    bool isAuthenticUser()
    {
        cout << "�����֤�ɹ�" << endl;
        return true;
    }

    void trackRequest(string request)
    {
        cout << "��Ҫ��ʾ�Ĺ����ֲ�: " + request << endl;
    }
};

void FrontControllerPatternDemo();
