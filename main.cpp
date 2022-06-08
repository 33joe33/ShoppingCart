#include <iostream>
#include<unistd.h>
#include"Menu.h"


void initialiseDatabase(const char * dir){
    //option to get path and for database creation
    //char* cwd [PATH_MAX];
    //getcwd(reinterpret_cast<char *>(cwd), sizeof (cwd));

    //create database and create tables for products and categories
    auto database = data(dir)    ;
    database.execute("CREATE TABLE IF NOT EXISTS CATEGORIES (\n"
                     "    ID INTEGER PRIMARY KEY AUTOINCREMENT,\n"
                     "    NAME TEXT NOT NULL ,\n"
                     "    DESCRIPTION TEXT NOT NULL\n"
                     ")");
    database.execute("CREATE TABLE IF NOT EXISTS PRODUCTS (\n"
                     "    ID INTEGER PRIMARY KEY AUTOINCREMENT,\n"
                     "    NAME TEXT NOT NULL ,\n"
                     "    PRICE FLOAT,\n"
                     "    CATEGORY INTEGER,\n"
                     "    FOREIGN KEY (CATEGORY) REFERENCES CATEGORIES(ID)\n"
                     ")");

database.close();
}

int main() {
    //path to database;
    const char* dir=R"(C:\Users\josep\CLionProjects\ShoppingCart\ShoppingCart.db)";
    initialiseDatabase(dir);
    //initialise database
    menu();
    //open the menu
}
