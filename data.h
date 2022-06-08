//
// Created by josep on 06/06/2022.
//

#ifndef SHOPPINGCART_DATA_H
#define SHOPPINGCART_DATA_H

#include <string>
#include"sqlite3.h"
#include<vector>
#include"Elements.h"
class data {

public:
    sqlite3* database;
    sqlite3_stmt *stmt;
    explicit data(const char* name);
    static sqlite3 * connectDatabase(const char* name);
     void execute(const char* sql) const;
    void add_category(const std::string& name ,const std::string& description);
    sqlite3_stmt * Select(const std::string& table, const std::string& columns);
    vector<Category *> categoryReturn() const;
    vector<Product*> productReturn()const;
    void displayRecords();
    void close() const;
    void deleteProduct();
    void deleteCategory();

    void add_product(const string &name, const string &category, double price);

    void displayCategories();
};


#endif //SHOPPINGCART_DATA_H
