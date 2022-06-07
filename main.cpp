#include <iostream>
#include"Menu.h"

int  callback(void *NotUsed, int argc ,char **argv,char**azColName){

    for (int i = 0; i < argc; i++) {
        cout<<azColName[i]<<":"<<argv[i]<<endl;


    }
    return 0;
}
int main() {
    //sqlite3* dd;
    //const char* dir = R"(C:\Users\josep\Documents\Programing\STUDENTS.db)";
//    //cout<<sqlite3_open(dir,&dd);
  //   auto dat=data(dir) ;
//
//dat.Select("ss","");
//     dat.add_category("baked goods","stale");
//    //sqlite3_exec(dat.database,"SELECT* FROM 'Categories';",callback,0,&err);
    //dat.execute("INSERT INTO categories(id, name, description) VALUES (2,'fodod','tastsy')");

    menu();
}
