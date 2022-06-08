#include<iostream>
#include <string>
#include <vector>
#include "Cart.h"
using namespace std;
void addProduct();
void addCategories();
void adminMenu(const string& user);
void userMenu(const string& user);
void menu();
void DisplayRecords();
void displayCategories();
vector<Product*> search(double priceLow,double priceHigh);
vector<Product*> search(const string& Name);
vector<Product*> searchCategory(const string &catName);
void selectionProduct(Cart*cart);
Product* searchSingle(int productId);
void select(Cart *cart);
void viewCart(Cart *cart);
void deleteProduct();
void deleteCategory();
