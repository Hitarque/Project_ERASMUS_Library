#ifndef MAGAZINE_H
#define MAGAZINE_H
#pragma once
#include "items.h"
#include <iostream>

using namespace std;

class Magazine: public Items
{
public:
    Magazine(string ids, string types, string titles, string authors, string dates, string numbers);
};

#endif // MAGAZINE_H
