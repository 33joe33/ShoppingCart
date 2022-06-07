#include <map>
#include "Cart.h"
#include<string>
using namespace std;
Cart::Cart()= default;

void Cart::setProductQuantity(int id ,int quantity)
    {
        ProductQuantity[id]+=quantity;
    }

void Cart::display()
    {
         double totalPrice=0;
         const char* dir = R"(C:\Users\josep\CLionProjects\ShoppingCart\ShoppingCart.db)";
         data dataConnection(dir);
         for (auto & item : ProductQuantity)
         {
             dataConnection.Select("PRODUCTS WHERE ID IS '"+to_string(item.first)+"'","*");
             Product*product =dataConnection.productReturn()[0];
             cout<<item.second<<" ";
             cout<<product->getPName()<<" for $ ";
             double Price=item.second*product->getPrice();
             cout<<Price<<endl;
             totalPrice+=Price;
         }
         dataConnection.close();
         cout<<"Total Cart Price is $"<<totalPrice<<endl;
    }
void Cart::deleteProduct(Product *product, int number)
    {
        int id=product->getPid();
        ProductQuantity[id]-=number;
        if (ProductQuantity[id]<=0)
            ProductQuantity.erase(id);
    }

void Cart::deleteCart()
    {
    for (auto productIterator = ProductQuantity.begin(); productIterator != ProductQuantity.end(); ++productIterator)
        ProductQuantity.erase(productIterator->first);
    }











