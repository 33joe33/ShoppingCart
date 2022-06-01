#include<iostream>
#include <string>
#include <vector>
#include "Cart.h"
using namespace std;


void adminMenu(const string& user, const string& password,vector<Product*> &ProductList,vector<Category*> &CategoryList);
void userMenu(const string& user,vector<Product*> &ProductList,vector<Category*> &CategoryList);
void menu();
void addProduct(vector<Product*> &p);
void addCategories(vector<Category*> &c);
void DisplayRecords(vector<Product*> p);
vector<Product*> search(double priceLow,double priceHigh,const vector<Product*>&productList);
vector<Product*> search(const string& Name,const vector<Product*>&productList);
vector<Product*> search(int CAT_ID,const vector<Product*>&productList);
void selectionProduct(Cart*cart,const vector<Product*>& ProductList);
Product* searchSingle(int productId, const vector<Product*>& productList);
bool catExists(int catId, const vector<Category*>& categoryList);
void select(Cart *cart,const vector<Product*>&subProductList);
void viewCart(Cart *cart,const vector<Product*>& ProductList);
