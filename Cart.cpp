#include<iostream>
#include <map>
#include "Elements.cpp"
using namespace std;
class Cart{
protected:
    map<int ,int > ProductQuantity;
public:


    void setProductQuantity(int PID,int quantity) {
        ProductQuantity[PID]+=quantity;
    }

    const map<int, int> &getProductQuantity() const {
        return ProductQuantity;
    }
};


