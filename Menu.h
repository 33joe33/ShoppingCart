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
