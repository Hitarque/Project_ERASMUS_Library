#ifndef CUSTOMERCART_H
#define CUSTOMERCART_H

#include <iostream>
using namespace std;

class customercart
{
public:
    customercart(string ids, string types, string titles, string authors, string dates);
    string seecart();

    string ID;
    string type;
    string title;
    string author;
    string date_of_creation;
    string number_of_this_item;
};

#endif // CUSTOMERCART_H
