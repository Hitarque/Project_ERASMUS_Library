#include <qdebug.h>
#include<qdialog.h>
#include <string>
#include "customers.h"

using namespace std;


//describe customer + function
//================================


//create customer
Customer::Customer( string id, string name, string adress, string phonenumber)
{
    ID=id;
    Name=name;
    Adress=adress;
    Phonenumber=phonenumber;
}

//return customer info
string Customer::seecustomer(){
    string value= ID +" | "+ Name +" | "+ Adress +" | "+ Phonenumber;
    return value;
}


//add item in the customer cart vector
void Customer::addcart(string ids,string types, string titles, string authors, string dates)
{
    bool test= true;
        if(test==true)
            {
                 cart.push_back(new customercart(ids,types,titles,authors,dates));
            }
}


//delete item in customercart vector
void Customer::deletcartrow(int i)
{
 cart.erase(cart.begin()+i);
}


//return number of item in customer cart vector
int Customer::nbritems()
{
    return cart.size();
}


//return value of a customercart row
string Customer::seeitem(int i)
{
    return cart[i]->seecart();
}
