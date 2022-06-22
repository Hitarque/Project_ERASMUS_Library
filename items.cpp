#include <iostream>
#include <string>
#include "items.h"
using namespace std;

//main class to describe parameter for book, cd, magazine and diverses

Items::Items(string ids, string types, string titles, string authors, string dates, string numbers)
{
    ID = ids;
    type = types;
    title = titles;
    author = authors;
    date_of_creation = dates;
    number_of_this_item = numbers;
}

//return value for show
string Items::seeitems()
{
    string value= ID +" | "+ type +" | "+ title +" | "+ author+" | "+ date_of_creation+" | "+ number_of_this_item;
    return value;
}

//change number of item
int Items::changenumberofthisitem(int value)
{
    number_of_this_item=stoi(number_of_this_item) + value;
    return stoi(number_of_this_item);
}

//destructor
Items::~Items() {}


