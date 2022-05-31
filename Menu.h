#include<iostream>
#include <string>
#include <vector>
#include "Cart.h"
using namespace std;


void adminMenu(string user, string password);
void userMenu(string user);
void menu();
void addProduct(vector<Product*> &p);
void addCategories(vector<Category*> &c);
void DisplayRecords(vector<Product*> p);
vector<Product*> search(double priceLow,double priceHigh,const vector<Product*>&productList);
vector<Product*> search(const string& Name,const vector<Product*>&productList);
vector<Product*> search(int CAT_ID,const vector<Product*>&productList);

