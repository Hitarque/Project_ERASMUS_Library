#pragma once
#include "book.h"
#include <iostream>

using namespace std;

//abstract of item


Book::Book(string ids, string types, string titles, string authors, string dates, string numbers):Items(ids, types, titles, authors,dates,numbers)
{

}
