#include <map>
#include "Elements.h"
using namespace std;
class Cart{
protected:
    map<Product* ,int > ProductQuantity;
public:


    void setProductQuantity(Product *product,int quantity);

    const map<Product*, int> &getProductQuantity() const {
        return ProductQuantity;
    }
    void display();
    void deleteProduct(Product* product,int number);;

};




