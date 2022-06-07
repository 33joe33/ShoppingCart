//
// Created by josep on 06/06/2022.
//

#ifndef SHOPPINGCART_DATA_H
#define SHOPPINGCART_DATA_H

#include <string>
#include"sqlite3.h"
#include"Cart.h"
#include<vector>
class data {

public:
    sqlite3* database;
    sqlite3_stmt *stmt;
    explicit data(const char* name);
    sqlite3 * connectDatabase(const char* name);
     void execute(const char* sql);
    void add_category(const std::string& name ,const std::string& description);
    sqlite3_stmt * Select(const std::string& table, const std::string& columns);
    vector<Category *> categoryReturn() const;
    void add_product(const string &name, const string &description);


    void add_product(const string &name, const string &category, double price);
};


#endif //SHOPPINGCART_DATA_H
