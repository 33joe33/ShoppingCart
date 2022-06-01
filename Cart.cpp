#include <map>
#include "Cart.h"
using namespace std;



    Cart::Cart()= default;

     void Cart::setProductQuantity(Product *product,int quantity) {

        ProductQuantity[product]+=quantity;
        cout<<ProductQuantity[product]<<endl;

    }


    void Cart::display(){
        for (auto item = ProductQuantity.begin(); item != ProductQuantity.end(); ++item) {


            cout<<item->second<<" ";

            cout<<item->first->getPName()<<"for $ ";
            cout<<item->second*item->first->getPrice()<<endl;
        }
    }
    void Cart::deleteProduct(Product *product, int number) {
        ProductQuantity[product]-=number;
        if (ProductQuantity[product]<=0)
            ProductQuantity.erase(product);




    };










