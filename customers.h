
#include <iostream>
#include <vector>
#include"customercart.h"

using namespace std;

class Customer
{
public:
    Customer(string id,string name,string adress,string phonenumber );
    string seecustomer();
    void addcart( string ids , string types,  string titles,  string authors,  string dates);

    int nbritems();
    string seeitem(int i);
    void deletcartrow(int i);

    string ID;
    string Name;
    string Adress;
    string Phonenumber;

private:
    vector<customercart*> cart;
};
