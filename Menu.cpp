#include<iostream>
#include <string>
#include<vector>
#include "Menu.h"
using namespace std;
void AddToCart(Cart& cart);
void displayCategories(vector<Category*> c);
bool catExists(int catId, const vector<Category*>& categoryList);
void searchCategories(vector<Category*> c, int cat_id);


void addProduct(vector<Product*>& p, vector<Category*>& c)
{
    if (c.empty()){
        cout << "\n no categories"; return;
    }
    float price;
    int  cat_id;
    string name;
    bool flag = true;

    cout << " Enter Product name = ";
    cin >> name;
    cout << " Enter Product price = ";
    cin >> price;
    while (flag) {
        displayCategories(c);
        cout << " Enter Category ID = ";
        cin >> cat_id;
        if (catExists(cat_id, c)) {
            flag = false;
        }
        else {
            cout << "invalid category \n";
        }
    }
    


    Product* ob = new Product(name, price, cat_id);
    p.push_back(ob);
}

void addCategories(vector<Category*>& c)
{
    string name, description;

    cout << " Enter Category name = ";
    cin >> name;
    cout << " Enter category description = ";
    cin >> description;

    auto* ob = new Category(name, description);
    c.push_back(ob);
}

void DisplayRecords(vector<Product*> p, vector<Category*> c)
{
    for (auto& i : p)
    {
        i->dsply();
        searchCategories(c, (i->getCatId()));
    }
}

void displayCategories(vector<Category*> c)
{
    for (auto& i : c)
    {
        i->display();
    }
}
void searchCategories(vector<Category*> c,int cat_id)
{
    for (auto& i : c)
    {
        if (i->getCatId() == cat_id) 
        {
            i->dsply();
            return;
        }      
    }
}

void userMenu(const string& user,vector<Product*> &ProductList,vector<Category*> &CategoryList)
{
    int  ch;
     Cart* cart = new Cart;
    do
    {

    cout << "\n 1 Add products to cart";
    cout << "\n 2 View cart";
    cout << "\n 5 exit";

    cin >> ch;


        switch (ch)
        {
        case 1:  selectionProduct(cart,ProductList);break;
        case 2:
            viewCart(cart,ProductList); break;
        case 5:  break;
        }

    } while (ch != 5);
}


void adminMenu(const string& user, const string& password,vector<Product*> &ProductList,vector<Category*> &CategoryList)
{
    int ch;



    //	cout<<"Please enter password";
    //	cin>>getline(password,1);

    //	if (User== "admin" && password == "123")
    do
    {
        cout << "\n 1 add product";
        cout << "\n 2 add categories";
        cout << "\n 3 see records";
        cout << "\n 4 see categories";
        cout << "\n 5 exit";
        cin >> ch;

        switch (ch)
        {
        case 1:addProduct(ProductList, CategoryList); break;
        case 2:addCategories(CategoryList); break;
        case 3:DisplayRecords(ProductList, CategoryList); break;
        case 4:displayCategories(CategoryList); break;
        case 5: break;
        }

    } while (ch != 5);
    //	else
    //	{
    //		cout<<"Wrong password or admin";
    //	}
}

void menu()
{   vector<Product*> ProductList;
    vector<Category *> CategoryList;
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
        case 1: adminMenu(user, password,ProductList,CategoryList); break;
        case 2: userMenu(user,ProductList,CategoryList); break;
        case 10:break;
        default:cout << "\n Invalid option" << endl;
        }
    } while (ch != 10);
}

vector<Product*> search(const string& Name, const vector<Product*>& productList) {
    vector<Product*> foundItems;
    for (const auto& item : productList) {
        if (item->getPName().find(Name) != string::npos)
            foundItems.push_back(item);
    }
    return foundItems;
}

vector<Product*> search(double priceLow, double priceHigh, const vector<Product*>& productList) {
    vector<Product*> foundItems;
    for (const auto& item : productList) {
        if (item->getPrice() <= priceHigh && item->getPrice() >= priceLow)
            foundItems.push_back(item);
    }
    return foundItems;
}

vector<Product*> search(int CAT_ID, const vector<Product*>& productList) {
    vector<Product*> foundItems;
    for (const auto& item : productList) {
        if (item->getCatId() == CAT_ID)
            foundItems.push_back(item);
    }
    return foundItems;

}
void selectionProduct(Cart *cart,const vector<Product*>& ProductList)

{
    int ch1;
    do{

    string name;
    double low, high;
    int id;
    cout << "\n 1 Search by name";
    cout << "\n 2 Search by price";
    cout << "\n 3 Search by category";
    cout << "\n 4 Select by ID";
    cout << "\n 5 exit";
    cin>>ch1;
    vector<Product*>subProductList;


        switch (ch1) {
            case 1:
                cout << "Enter name";
                cin >> name;
                subProductList = search(name, ProductList);
                for (const auto &item: subProductList) {
                    item->display();
                }
                break;

            case 2:

                cout << "Enter low = ";
                cin >> low;
                cout << "Enter high = ";
                cin >> high;
                subProductList = search(low, high, ProductList);
                for (const auto &item: subProductList) {
                    item->display();}
                    break;

            case 3:

                cout << "Enter category ID";
                cin >> id;
                subProductList = search(id, ProductList);
                for (const auto &item: subProductList) {
                    item->display();}
                    break;

            case 4:

                select(cart,ProductList);
                break;


            case 5:
                break;
        }
            ;
    } while (ch1 != 5);
    //AddToCart( cart)
}
void AddToCart(Cart& cart) {
    Product* product;
    int quantity;

    // cart.setProductQuantity(product,quantity);
}

void select(Cart *cart, const vector<Product *> &subProductList) {int id;
    int quantity;
    cout<<"give product id of product"  <<endl;
    cin>>id;
    cout<<"give quantity of selected product"<<endl;
    cin>>quantity;
    searchSingle(id,subProductList);

    cart->setProductQuantity(searchSingle(id,subProductList),quantity);
    cart->display();
}

bool catExists(int catId, const vector<Category *> &categoryList) {
    for (const auto& item : categoryList) {
        if (item->getCatId() == catId)
            return true;
    }
    return false;
}

void viewCart(Cart *cart, const vector<Product *> &ProductList) {
    int ch;
    do
    {
        cart->display();

        cout << "\n 1 Remove from cart";
        cout << "\n 2 Clear cart";
        cout << "\n 5 exit";
        cin >> ch;

        switch (ch) {
            case 1:
                int id,quantity ;
                cout<<"please enter product id"<<endl;
                cin>>id;
                cout<<"how many would you like to remove"<<endl;
                cin>>quantity;
                cart->deleteProduct(searchSingle(id,ProductList),quantity);break;
            case 2:
                cart->deleteCart();

            case 5:
                break;
        }
    } while (ch != 5);
}

Product *searchSingle(int productId, const vector<Product *> &productList) {

    for (const auto& item : productList) {

        if (item->getPid() == productId)
        {

            return item;
        }
    }
}






