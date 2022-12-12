#include <iostream>
#include <string>

using namespace std;

class CPrototype
{
public:

    CPrototype() {}

    ~CPrototype() {}

    virtual CPrototype* Clone() = 0;
};

class cperson : CPrototype
{
public:
    cperson() :mID("0000"),mName("李华")
    {

    }
    cperson(cperson* rhs)
    {
        mName = rhs->mName;
        mID = rhs->mID;
    }
    virtual ~cperson() {}
    void SetName(string value) { mName = value; }
    void SetID(string value) { mID = value; }
    string GetName() { return mName; }
    string GetID() { return mID; }
    cperson* Clone()
    {
        return new cperson(*this);
    }

private:
    string mName;
    string mID;
};

static void change_information(cperson* p_person)
{
    p_person->SetName("李小华");
    p_person->SetID("1001");
}

static void show_params(cperson* p_person)
{
    cout << "Name: " << p_person->GetName() << endl;
    cout << "ID: " << p_person->GetID() << endl<< endl; 
}

int Prototype()
{
    cperson* theperson = new cperson();
    //展示原型
    show_params(theperson);

    //复制
    cout << "Clone person:" << endl;
    cperson* theperson2 = theperson->Clone();
    change_information(theperson2);
    show_params(theperson2);

    delete theperson2;
    delete theperson;
    return 0;
}
