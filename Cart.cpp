#include <map>
#include "Cart.h"
using namespace std;



    Cart::Cart()= default;

     void Cart::setProductQuantity(Product *product,int quantity) {
        ProductQuantity[product]+=quantity;
    }

    const map<Product*, int> &Cart::getProductQuantity()  {
        return ProductQuantity;
    }
    void Cart::display(){
        for (auto productIterator = ProductQuantity.begin(); productIterator != ProductQuantity.end(); ++productIterator) {
            cout<<productIterator->first->getPName();
            cout<<productIterator->second*productIterator->first->getPrice()<<endl;
        }
    }
    void Cart::deleteProduct(Product *product, int number) {
        ProductQuantity[product]-=number;
        if (ProductQuantity[product]<=0)
            ProductQuantity.erase(product);




    };










