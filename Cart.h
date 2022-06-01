#include <map>
#include "Elements.h"
using namespace std;
class Cart{


public:
    map<Product* ,int > ProductQuantity;
    Cart();

    void setProductQuantity(Product *product,int quantity) ;



    void display();
    void deleteProduct(Product *product, int number);


    void deleteCart();
};








