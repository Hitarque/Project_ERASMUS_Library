#ifndef DIVERSES_H
#define DIVERSES_H

#pragma once
#include "items.h"
#include <iostream>

class diverses :public Items
{ public:
    diverses(string ids, string types, string titles, string authors, string dates, string numbers);
};

#endif // DIVERSES_H
