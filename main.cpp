#include <iostream>
#include <filesystem>
#include<unistd.h>
#include"Menu.h"


void initialiseDatabase(const char * dir){
    char* cwd [PATH_MAX];
    getcwd(reinterpret_cast<char *>(cwd), sizeof (cwd));


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
    database.execute("CREATE TABLE IF NOT EXISTS CART(\n"
                     "    ID,INTEGER,\n"
                     "    QUANTITY INTEGER,\n"
                     "    FOREIGN KEY (ID) REFERENCES PRODUCTS(ID)\n"
                     ")");
database.close();
}

int main() {

    const char* dir=R"(C:\Users\josep\CLionProjects\ShoppingCart\ShoppingCart.db)";
    initialiseDatabase(dir);

    menu();
}
