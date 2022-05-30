#include<iostream>
#include <string>
using namespace std;


void adminMenu(string user,string password)
{
    int ch;

//	cout<<"Please enter password";
//	cin>>getline(password,1);

//	if (User== "admin" && password == "123")
    do
    {
        cout<<"\n 1 add product";
        cout<<"\n 2 add categories";
        cout<<"\n 3 see records";
        cout<<"\n 5 exit";
        cin>>ch;

        switch(ch)
        {
            case 1: break;
            case 2: break;
            case 3: break;
            case 5: break;
        }

    }while(ch!=5);
//	else
//	{
//		cout<<"Wrong password or admin";
//	}
}

void userMenu(string user)
{
    int  ch;
    cout<<"\n 1 View products";
    cout<<"\n 2 View";
    cout<<"\n 5 exit";
    cin>>ch;
    do
    {


        switch(ch)
        {
            case 1: break;
            case 2: break;
            case 5: break;
        }

    }while(ch!=5);
}

int main()
{
    string user, password;
    int ch;
    do
    {
        cout<<"\n 1 Admin - 2 User ";
        cout<<"\n 10 Exit \n";
        cout<<"\n Enter choice: \n";
        cin>>ch;

        if(ch >= 1 && ch<2)
        {
            cout<<"\n Enter Name ";
            getline(cin,user);
        }
        switch(ch)
        {
            case 1: adminMenu(user, password);break;
            case 2: userMenu(user);break;
            case 10:break;
            default:cout<<"\n Invalid option"<<endl;
        }
    }while(ch!=10);
}