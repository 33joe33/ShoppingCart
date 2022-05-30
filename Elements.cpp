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
};

class Catagory {
	protected:
		int CAT_ID;
		string CAT_NAME;
		string DESCRIPTION;

	public:
		Catagory() {

		}
};
