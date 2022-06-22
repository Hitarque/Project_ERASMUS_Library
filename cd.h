#ifndef CD_H
#define CD_H

#pragma once
#include "items.h"
#include <iostream>

using namespace std;

class CD : public Items
{
public:
    CD(string ids, string types, string titles, string authors, string dates, string numbers);
};

#endif // CD_H
