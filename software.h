#ifndef SOFTWARE_H
#define SOFTWARE_H

#include "customers.h"
#include "items.h"
#include "book.h"
#include "magazine.h"
#include "cd.h"
#include "diverses.h"

#include "dialogcustomerfinder.h"
#include "dialogcustomercreate.h"
#include "dialogseeitems.h"
#include "dialogitemsfinder.h"
#include "dialogaddtocart.h"


class software
{
public:
    software();

    static QString findcustomer(QString value);
    static QString finditem(QString value);

    //modify customer cart
    static void addtocart(QString customer,QString item );
    static int numbercart(int j);
    static QString seeitemcart(int j,int i);

    //items
    void bddcitems();
    static void newitem(QString value);
    static void dialogueseeitem(int x);
    static void dialogueseeitem(QString y);
    static QString seeitem(int i);
    static int numberofitems();
    static void returnitem(QString value, int customer, int row);

    //customer

    void bddcustomers();
    static void newcustomer(QString value);
    static void dialogseecustomer(int x);
    static void dialogseecustomer(QString y);
    static QString seecustomer(int i);
    static int numberofcustomerss();









};

#endif // SOFTWARE_H

