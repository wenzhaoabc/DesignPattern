#pragma once
#include<iostream>

using namespace std;
class HomeView {
public:
    void show()
    {
        cout << "显示监督员工作手册" << endl;
    }
};

class StudentView
{
public:
    void show()
    {
        cout << "显示工人工作手册" << endl;
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
        if ("工人" == request)
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
        trackRequest(request);  //记录每一个请求

        if (isAuthenticUser())    //对用户进行身份验证
        {
            dispatcher->dispatch(request);
        }
    }

private:
    Dispatcher* dispatcher;

    bool isAuthenticUser()
    {
        cout << "身份认证成功" << endl;
        return true;
    }

    void trackRequest(string request)
    {
        cout << "需要显示的工作手册: " + request << endl;
    }
};

void FrontControllerPatternDemo();
