#include "data.h"
#include<iostream>


data::data(const char * name)
    {
        database=connectDatabase(name);
        stmt= nullptr;
    }
sqlite3* data::connectDatabase(const char *name)
    {
    sqlite3 *db;
    //std::cout<<name;
    auto rs=sqlite3_open(name,&db);
    if (!rs)
        {
            //std::cout<<"Connection made to "<< name<<std::endl;
            return db;
        }
    std::cout<<"Connection failed"<< std::endl;
    return db;

}

void data::execute(const char *sql) const
    {
        char* Error;
        auto rs =sqlite3_exec(database,sql,nullptr,nullptr,&Error);
        if (!rs)
        {
            //std::cout<<"Successful sql command execution"<<std::endl;
            return;
        }
        std::cout<<"failed execution of\n "<<sql<<std::endl;
    }

void data::add_category(const std::string& name, const std::string& description)
    {
        stmt=Select("CATEGORIES WHERE NAME IS '"+name+"'","ID");
        int cat_id=0;
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            int cat =sqlite3_column_int(stmt,0);
            cat_id=cat;
        }

        std::string sq= "INSERT INTO CATEGORIES(name, description) VALUES ('" + name + "','" + description + "')";
        if (cat_id==0)
            execute(sq.c_str());
        else
            cout<<"that category already exists"<<endl;
    }

void data::add_product(const std::string& name, const std::string& category,double price)
    {
        stmt=Select("CATEGORIES WHERE NAME IS '"+category+"'","ID");

        int cat_id=0;
        while ( sqlite3_step(stmt) == SQLITE_ROW)
        {
            int cat =sqlite3_column_int(stmt,0);
            cat_id=cat;
        }
        std::string sq= "INSERT INTO PRODUCTS ( NAME, PRICE, CATEGORY) VALUES ('"+name+"',"+ to_string(price)+","+ to_string(cat_id)+")";
        if (cat_id!=0)
            execute(sq.c_str());
        else
            cout<<"no category with that name;"<<endl;
    }

sqlite3_stmt* data::Select(const std::string &table, const std::string& columns)
    {
        std::string sql;
        sql = "SELECT " + columns + "  FROM " + table;
        sqlite3_prepare(database, sql.c_str(), -1, &stmt, nullptr);
        sqlite3_bind_int(stmt, 1, 16);
        return stmt;
    }


vector<Category*> data::categoryReturn() const
    {
        vector<Category *> toBeReturned;

        while ( sqlite3_step(stmt) == SQLITE_ROW)
        {
            basic_string<unsigned char> uName = sqlite3_column_text(stmt,1);
            basic_string<unsigned char > uDescription = sqlite3_column_text(stmt,2);
            string name (uName.begin(),uName.end())        ;
            string description (uDescription.begin(),uDescription.end()) ;
            auto* cat = new Category(name, description);
            toBeReturned.push_back(cat);
        }
    return toBeReturned;
    }
vector<Product *> data::productReturn() const
    {
        vector<Product *> toBeReturned;

        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            basic_string<unsigned char> uName = sqlite3_column_text(stmt, 1);
            float price = sqlite3_column_double(stmt, 2);
            int category = sqlite3_column_int(stmt ,3);
            string name(uName.begin(), uName.end());
            auto *product=  new Product(name, price,category);
            toBeReturned.push_back(product);
        }
        return toBeReturned;
    }

void data::close() const
    {
        sqlite3_close(database);

    }

void data::displayRecords()
    {
        std::string sql;
        sql = "SELECT PRODUCTS.ID, PRODUCTS.NAME, PRICE, C.NAME, DESCRIPTION FROM PRODUCTS INNER JOIN CATEGORIES C on C.ID = PRODUCTS.CATEGORY";



        sqlite3_prepare(database, sql.c_str(), -1, &stmt, nullptr);
        sqlite3_bind_int(stmt, 1, 16);
        printf(" \nID\tName\tprice\tcategory\tdescription\n");
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            printf("\n%s\t%s\t%s\t%s\t\t%s",sqlite3_column_text(stmt,0),sqlite3_column_text(stmt,1),sqlite3_column_text(stmt,2),sqlite3_column_text(stmt,3),sqlite3_column_text(stmt,4));
        }

    }

void data::displayCategories()
{
    std::string sql;
    sql = "SELECT *FROM CATEGORIES ";

    sqlite3_prepare(database, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, 16);
    printf(" \nID\tName\t\tDescription\n");
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        printf("\n%s\t%s\t\t%s",sqlite3_column_text(stmt,0),sqlite3_column_text(stmt,1), sqlite3_column_text(stmt,2));
    }

}

void data::deleteCategory() {
    string id;
    cout<<"\nPlease enter the Category id"<<endl;
    cin>>id;
    string sql="DELETE  FROM CATEGORIES WHERE ID IS "+id;
    data::execute(sql.c_str());
}

void data::deleteProduct() {
    string id;
    cout<<"\nPlease enter the Product id"<<endl;
    cin>>id;
    string sql="DELETE  FROM PRODUCTS WHERE ID IS "+id;
    data::execute(sql.c_str());
}
