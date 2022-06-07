#include <map>
#include "Cart.h"
#include<string>
using namespace std;



    Cart::Cart()= default;

     void Cart::setProductQuantity(int id ,int quantity) {


            ProductQuantity[id]+=quantity;
    cout<<"passed";
    }


    void Cart::display(){
         double totalPrice=0;
        const char* dir = R"(C:\Users\josep\CLionProjects\ShoppingCart\ShoppingCart.db)";
         data dataConnection(dir);
        for (auto item = ProductQuantity.begin(); item != ProductQuantity.end(); ++item) {

            dataConnection.Select("PRODUCTS WHERE ID IS '"+to_string(item->first)+"'","*");

            vector<Product*>P =dataConnection.productReturn();
            cout<<item->second<<" ";

            cout<<P[0]->getPName()<<" for $ ";

            double Price=item->second*P[0]->getPrice();
            cout<<Price<<endl;
            totalPrice+=Price;
        }
        cout<<"Total Cart Price is $"<<totalPrice<<endl;
    }
    void Cart::deleteProduct(Product *product, int number) {
         int id=1;
        ProductQuantity[id]-=number;

        if (ProductQuantity[id]<=0)
            ProductQuantity.erase(id);




    }

void Cart::deleteCart(){
    for (auto productIterator = ProductQuantity.begin(); productIterator != ProductQuantity.end(); ++productIterator) {
        ProductQuantity.erase(productIterator->first);
    }
}
    ;










