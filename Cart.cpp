#include<iostream>
#include <map>
#include "Elements.cpp"
using namespace std;
class Cart{
protected:
    map<int ,int > ProductQuantity;
public:




    void setProductQuantity(const map<int, int> &productQuantity) {
        ProductQuantity = productQuantity;
    }

    const map<int, int> &getProductQuantity() const {
        return ProductQuantity;
    }
};


