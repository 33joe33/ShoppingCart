#include<iostream>
using namespace std;


class Product {
protected:
    int PID;
    string PName;
    float price;
    int CAT_ID;

public:
    Product(int id, string name, float prc, int cat_id);
    int getPid();

    void setPid(int pid);

    const string& getPName();

    void setPName(const string& pName);

    float getPrice();

    void setPrice(float price);

    int getCatId();

    void setCatId(int catId);

    void display();
};
// 111 LUX  40  SOAP  Some desc


class Catagory {

protected:
    int CAT_ID;
    string CAT_NAME;
    string DESCRIPTION;

public:
    Catagory(int id, string name, string desc);

    int getCatId();

    void setCatId(int catId);

    const string& getCatName();

    void setCatName(const string& catName);

    const string& getDescription();

    void setDescription(const string& description);


};
// 111 LUX  40  SOAP  Some desc
