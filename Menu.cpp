#include<iostream>
#include <string>
#include<vector>
#include "Menu.h"
using namespace std;

void addProduct(vector<Product*> &p)
{
    float price;
    int id=1, cat_id;
    string name;

    cout << " Enter Product name = ";
    cin>>name;
    cout << " Enter Product price = ";
    cin >> price;
        cout << " Enter Category ID = ";
    cin >> cat_id;

    Product* ob = new Product(id, name, price, cat_id);
    p.push_back(ob);
}

void addCategories(vector<Category*> &c)
{
    int id=1;
    string name, description;

    cout << " Enter Cateogry ID =  ";
    cin >> id;
    cout << " Enter Category name = ";
    cin>>name;
    cout << " Enter cateogory descrptin = ";
    cin>>description;

    auto* ob = new Category(id, name, description);
    c.push_back(ob);
}

void DisplayRecords(vector<Product*> p) {

    for (auto & i : p) {
        i->display();


    }
}





void userMenu(string user)
{
    int  ch;
    cout << "\n 1 Add products to cart";
    cout << "\n 2 View cart";
    cout << "\n 5 exit";
    cin >> ch;
    do
    {


        switch (ch)
        {
        case 1: break;
        case 2: break;
        case 5: break;
        }

    } while (ch != 5);
}

void adminMenu(string user, string password)
{
    int ch;

    vector<Product*> ProductList;
    vector<Category*> CategoryList;
    //	cout<<"Please enter password";
    //	cin>>getline(password,1);

    //	if (User== "admin" && password == "123")
    do
    {
        cout << "\n 1 add product";
        cout << "\n 2 add categories";
        cout << "\n 3 see records";
        cout << "\n 5 exit";
        cin >> ch;

        switch (ch)
        {
        case 1:addProduct(ProductList); break;
        case 2:addCategories(CategoryList); break;
        case 3:DisplayRecords(ProductList); break;
        case 5: break;
        }

    } while (ch != 5);
    //	else
    //	{
    //		cout<<"Wrong password or admin";
    //	}
}

void menu()
{
    string user, password;
    int ch;
    do
    {
        cout << "\n 1 Admin - 2 User ";
        cout << "\n 10 Exit \n";
        cout << "\n Enter choice: \n";
        cin >> ch;

        if (ch >= 1 && ch < 2)
        {
            cout << "\n Enter Name ";
            getline(cin, user);
        }
        switch (ch)
        {
        case 1: adminMenu(user, password); break;
        case 2: userMenu(user); break;
        case 10:break;
        default:cout << "\n Invalid option" << endl;
        }
    } while (ch != 10);
}
