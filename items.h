#ifndef ITEMS_H
#define ITEMS_H


#pragma once
#include <iostream>

using namespace std;

class Items {

public:

    Items(string ids, string types, string titles, string authors, string dates, string numbers);
    virtual ~Items();
    string seeitems();
    int changenumberofthisitem(int value);

    string ID;
    string type;
    string title;
    string author;
    string date_of_creation;
    string number_of_this_item;

};

#endif // BOOK_H
