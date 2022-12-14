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
        cout << "User is authenticated successfully." << endl;
        return true;
    }

    void trackRequest(string request)
    {
        cout << "Page requested: " + request << endl;
    }
};


void FrontControllerPatternDemo() {
	cout << "ǰ�˿�����ģʽչʾ��" << endl;
	FrontController* frontController = new FrontController();
	frontController->dispatchRequest("HOME");
	cout << endl;
	frontController->dispatchRequest("STUDENT");
	cout << endl;
}