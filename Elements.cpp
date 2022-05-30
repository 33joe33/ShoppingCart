#include<iostream>
using namespace std;


class Product {
	protected:
		int PID;
		string PName;
		float price;
		int CAT_ID;

	public:
		Product(int id, string name, float prc,int cat_id) {
			PID = id;
			PName = name;
			price = prc;
			CAT_ID = cat_id;
		}

    int getPid() const {
        return PID;
    }

    void setPid(int pid) {
        PID = pid;
    }

    const string &getPName() const {
        return PName;
    }

    void setPName(const string &pName) {
        PName = pName;
    }

    float getPrice() const {
        return price;
    }

    void setPrice(float price) {
        Product::price = price;
    }

    int getCatId() const {
        return CAT_ID;
    }

    void setCatId(int catId) {
        CAT_ID = catId;
    }
};

class Catagory {

	protected:
		int CAT_ID;
		string CAT_NAME;
		string DESCRIPTION;

	public:
		Catagory(int id, string name, string desc) {
			CAT_ID = id;
			CAT_NAME = name;
			DESCRIPTION = desc;
		}

    int getCatId() const {
        return CAT_ID;
    }

    void setCatId(int catId) {
        CAT_ID = catId;
    }

    const string &getCatName() const {
        return CAT_NAME;
    }

    void setCatName(const string &catName) {
        CAT_NAME = catName;
    }

    const string &getDescription() const {
        return DESCRIPTION;
    }

    void setDescription(const string &description) {
        DESCRIPTION = description;
    }

};
