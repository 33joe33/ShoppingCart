//
// Created by josep on 06/06/2022.
//

#include "data.h"
#include<iostream>


data::data(const char * name) {
    database=connectDatabase(name);
    stmt= nullptr;
} ;
 sqlite3* data::connectDatabase(const char *name) {
    sqlite3 *db;
    std::cout<<name;
    auto rs=sqlite3_open(name,&db);
    if (!rs){
        std::cout<<"Connection made to "<< name<<std::endl;
        return db;
    }
    std::cout<<"Connection failed"<< std::endl;
    return db;

}

void data::execute(const char *sql) {
     char* Error;
    auto rs =sqlite3_exec(database,sql,nullptr,nullptr,&Error);
    if (!rs){
        std::cout<<"Successful sql command execution"<<std::endl;
        return;
    }
    std::cout<<"failed execution of\n "<<sql<<std::endl;
}

void data::add_category(const std::string& name, const std::string& description) {
    stmt=Select("CATEGORIES WHERE NAME IS '"+name+"'","ID");
    int rc;
    int cat_id=0;
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW)
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

void data::add_product(const std::string& name, const std::string& category,double price) {
    stmt=Select("CATEGORIES WHERE NAME IS '"+category+"'","ID");
    int rc;
    int cat_id=0;
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int cat =sqlite3_column_int(stmt,0);
        cat_id=cat;
    }
    std::string sq= "INSERT INTO PRODUCT ( NAME, PRICE, CAT_ID) VALUES ('"+name+"',"+ to_string(price)+","+ to_string(cat_id)+")";
    if (cat_id!=0)
        execute(sq.c_str());
    else
        cout<<"no category with that name;"<<endl;
}

sqlite3_stmt* data::Select(const std::string &table, const std::string& columns) {
    std::string sql;
    sql = "SELECT " + columns + "  FROM " + table;




    sqlite3_prepare(database, sql.c_str(), -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, 16);
    return stmt;
}


vector<Category*> data::categoryReturn() const  {
    vector<Category *> toBeReturned;
     int rc;
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        basic_string<unsigned char> uName = sqlite3_column_text(stmt,1);
        basic_string<unsigned char > uDescription = sqlite3_column_text(stmt,2);
        string name (uName.begin(),uName.end())        ;
        string description (uDescription.begin(),uDescription.end()) ;
        auto* cat = new Category(name, description);
        toBeReturned.push_back(cat);



    }
    return toBeReturned;
}






//const char *sql;
//    char* msgError;
//    sql="INSERT INTO CATEGORIES";
//    auto rc =sqlite3_exec(db ,sql,NULL,0,&msgError);
