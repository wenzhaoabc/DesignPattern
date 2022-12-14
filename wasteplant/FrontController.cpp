#include<iostream>
using namespace std;

class HomeView {
public:
	void show()
	{
		cout << "Displaying Home Page" << endl;
	}
};

class StudentView
{
public:
	void show()
	{
		cout << "Displaying Student Page" << endl;
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
        if ("STUDENT" == request)
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
        cout << "User is authenticated successfully." << endl;
        return true;
    }

    void trackRequest(string request)
    {
        cout << "Page requested: " + request << endl;
    }
};


void FrontControllerPatternDemo() {
	cout << "前端控制器模式展示：" << endl;
	FrontController* frontController = new FrontController();
	frontController->dispatchRequest("HOME");
	cout << endl;
	frontController->dispatchRequest("STUDENT");
	cout << endl;
}