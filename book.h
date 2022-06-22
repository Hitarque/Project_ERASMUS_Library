#ifndef BOOK_H
#define BOOK_H


#pragma once
#include "items.h"
#include <iostream>

using namespace std;

class Book : public Items
{
public:
    Book(string ids, string types, string titles, string authors, string dates, string numbers);
};

#endif // BOOK_H
