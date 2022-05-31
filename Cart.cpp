#include <map>
#include "Elements.h"
using namespace std;
class Cart{
protected:
    map<Product* ,int > ProductQuantity;
public:
    Cart(){

    }

    void setProductQuantity(Product *product,int quantity) {
        ProductQuantity[product]+=quantity;
    }

    const map<Product*, int> &getProductQuantity() const {
        return ProductQuantity;
    }
    void display(){
        for (auto productIterator = ProductQuantity.begin(); productIterator != ProductQuantity.end(); ++productIterator) {
            cout<<productIterator->first->getPName();
            cout<<productIterator->second*productIterator->first->getPrice()<<endl;
        }
    }
    void deleteProduct(Product *product, int number) {
        ProductQuantity[product]-=number;
        if (ProductQuantity[product]<=0)
            ProductQuantity.erase(product);




    };


}l;







