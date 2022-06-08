#include<iostream>
#include <string>
#include<vector>
#include "Menu.h"

using namespace std;


const char* dir = R"(C:\Users\josep\CLionProjects\ShoppingCart\ShoppingCart.db)";


void addProduct() {   //add product to product database
    float price;
    string name;
    string category;

    cout << " Enter Product name = ";
    cin >> name;
    cout << " Enter Product price = ";
    cin >> price;
    cout<<"Enter category Name";
    cin.ignore();
    std::getline(cin,category);

    data dataConnection = data(dir) ;
    dataConnection.add_product(name ,category,price);

}

void addCategories()
{
    //add categories to the category table
    data dataConnection = data(dir);
    string name, description;

    cout << " Enter Category name = ";
    cin >> name;
    cout << " Enter category description = ";
    cin >> description;
    dataConnection.add_category(name, description);
    sqlite3_close(dataConnection.database);
}


void DisplayRecords() {
    data dataConnection(dir);
    dataConnection.displayRecords();
    dataConnection.close();
}


void displayCategories() {
    data dataConnection(dir);
    dataConnection.Select("CATEGORIES","*");

    for (auto& i : dataConnection.categoryReturn())
    {
        i->display();
    }
    dataConnection.close();
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

void userMenu(const string& user)
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
        case 1:  selectionProduct(cart);break;
        case 2:
            viewCart(cart); break;
        case 5:  break;
        }

    } while (ch != 5);
}


void adminMenu(const string& user)
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
        case 1:addProduct(); break;
        case 2:addCategories(); break;
        case 3:DisplayRecords(); break;
        case 4:displayCategories(); break;
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
        case 1: adminMenu(user); break;
        case 2: userMenu(user); break;
        case 10:break;
        default:cout << "\n Invalid option" << endl;
        }
    } while (ch != 10);
}

vector<Product*> search(const string& Name) {
    vector<Product*> foundItems;
    string sql;
    data dataConnection(dir);
    dataConnection.Select("PRODUCTS WHERE NAME LIKE '%"+Name+"%'","*");
    foundItems =dataConnection.productReturn();
    dataConnection.close();
    return foundItems;
}

vector<Product*> search(double priceLow, double priceHigh) {
    vector<Product*> foundItems;
    data dataConnection(dir);
    string sql="PRODUCTS WHERE PRICE BETWEEN "+to_string(priceLow)+" AND "+ to_string(priceHigh)+"";
    dataConnection.Select(sql.c_str(),"*");
    foundItems =dataConnection.productReturn();
    dataConnection.close();
    return foundItems;
}

vector<Product*> searchCategory(const string&  catName) {
    vector<Product*> foundItems;
    data dataConnection (dir);
    string sql= " PRODUCTS INNER JOIN CATEGORIES C on PRODUCTS.CATEGORY = C.ID WHERE C.NAME LIKE '%"+catName+"%'";
    dataConnection.Select(sql," PRODUCTS.ID, PRODUCTS.NAME,PRICE ");

    foundItems =dataConnection.productReturn();
    dataConnection.close();
    return foundItems;

}
void selectionProduct(Cart *cart)

{
    int ch1;
    do{
    string name;
    double low, high;
    string catName;
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
                for (const auto &item: search(name)) {
                    item->display();
                }
                break;

            case 2:

                cout << "Enter low = ";
                cin >> low;
                cout << "Enter high = ";
                cin >> high;
                for (const auto &item: search(low,high)) {
                    item->display();}
                    break;

            case 3:

                cout << "Enter category Name";
                cin >> catName;
                for (const auto &item: searchCategory(catName)) {
                    item->display();}
                    break;

            case 4:

                select(cart);
                break;


            case 5:
                break;
        }
            ;
    } while (ch1 != 5);
}
void select(Cart *cart) {int id;
    int quantity;

    cout<<"give product id of product"  <<endl;
    cin>>id;
    cout<<"give quantity of selected product"<<endl;
    cin>>quantity;

    cart->setProductQuantity(id,quantity);
    cart->display();
}

bool catExists(int catId, const vector<Category *> &categoryList) {
    for (const auto& item : categoryList) {
        if (item->getCatId() == catId)
            return true;
    }
    return false;
}

void viewCart(Cart *cart) {
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
                searchSingle(id)->display();
                cart->deleteProduct(searchSingle(id),quantity);break;
            case 2:
                cart->deleteCart();

            case 5:
                break;
        }
    } while (ch != 5);
    cout<<" why";
}

Product *searchSingle(int productId) {
    data dataConnection(dir);
    dataConnection.Select("PRODUCTS WHERE ID IS '"+to_string(productId)+"'","*");
    return dataConnection.productReturn()[0];

}





