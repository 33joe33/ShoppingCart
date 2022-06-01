#include <map>
#include "Cart.h"
using namespace std;



    Cart::Cart()= default;

     void Cart::setProductQuantity(Product *product,int quantity) {

        ProductQuantity[product]+=quantity;


    }


    void Cart::display(){
         double totalPrice=0;
        for (auto item = ProductQuantity.begin(); item != ProductQuantity.end(); ++item) {


            cout<<item->second<<" ";

            cout<<item->first->getPName()<<" for $ ";

            double Price=item->second*item->first->getPrice();
            cout<<Price<<endl;
            totalPrice+=Price;
        }
        cout<<"Total Cart Price is $"<<totalPrice<<endl;
    }
    void Cart::deleteProduct(Product *product, int number) {
        ProductQuantity[product]=number;

        if (ProductQuantity[product]<=0)
            ProductQuantity.erase(product);




    }

void Cart::deleteCart(){
    for (auto productIterator = ProductQuantity.begin(); productIterator != ProductQuantity.end(); ++productIterator) {
        ProductQuantity.erase(productIterator->first);
    }
}
    ;










