#pragma once
#include <iostream>
#include <qdebug.h>
#include "customercart.h"
using namespace std;

//class to create cart, it's item without abstract


//create a line of item
customercart::customercart(string ids, string types, string titles, string authors, string dates) {
    ID = ids;
    title = titles;
    author = authors;
    date_of_creation = dates;
}


//show line of a cart
string customercart::seecart()
{
    string value;
    if(ID.substr(0,1)=="1")
    {
        if(number_of_this_item!="0"){
            value= ID +" | Book | "+ title +" | "+ author +" | "+ date_of_creation+" | "+ number_of_this_item;
        }
        else{
            value= ID +" | Book | "+ title +" | "+ author +" | "+ date_of_creation;
        }
    }
    if(ID.substr(0,1)=="2")
    {
        if(number_of_this_item!="0"){
            value= ID +" | Magazine | "+ title +" | "+ author +" | "+ date_of_creation+" | "+ number_of_this_item;
        }
        else{
            value= ID +" | Magazine | "+ title +" | "+ author +" | "+ date_of_creation;
        }
    }
    if(ID.substr(0,1)=="3")
    {
        if(number_of_this_item!="0"){
            value= ID +" | CD | "+ title +" | "+ author +" | "+ date_of_creation+" | "+ number_of_this_item;
        }
        else{
            value= ID +" | CD | "+ title +" | "+ author +" | "+ date_of_creation;
        }
    }
    if(ID.substr(0,1)=="9")
    {
        if(number_of_this_item!="0"){
            value= ID +" | Other | "+ title +" | "+ author +" | "+ date_of_creation+" | "+ number_of_this_item;
        }
        else{
            value= ID +" | Other | "+ title +" | "+ author +" | "+ date_of_creation;
        }
    }
    return value;
}
