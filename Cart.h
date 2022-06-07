#include <map>
#include "data.h"
using namespace std;
class Cart{
public:
    map<int ,int > ProductQuantity;
    Cart();
    void setProductQuantity(int id,int quantity) ;
    void display();
    void deleteProduct(Product *product, int number);
    void deleteCart();
};








