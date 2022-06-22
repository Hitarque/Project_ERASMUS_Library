#include "software.h"

#include<QDebug>
#include<QDialog>
#include<QMessageBox>
#include <vector>

Customer* customers[100];

std::vector<Items*> items;

int numberofcustomers=4;

int numberofbook=4;
int numberofmagazine=1;
int numberofcd=1;
int numberofother=1;


//constructor of the main class software class is a link for all the other classes
software::software()
{
bddcustomers();
bddcitems();
qDebug()<<"initialization succed";
}

//function to find customer and return is info
QString software::findcustomer(QString value)
{
    bool test=true;
    for(int i=0;i<numberofcustomers;i++){
         if ((value==QString::fromStdString(customers[i]->ID))^(value==QString::fromStdString(customers[i]->Name))^(value==QString::fromStdString(customers[i]->Adress))^(value==QString::fromStdString(customers[i]->Phonenumber)))
         {
            test=false;
            return seecustomer(i);
         }
    }
    if (test==true)
    {
        QMessageBox msgBox;
        msgBox.setText("Error this customer dont exist");
        msgBox.exec();
        return 0;
    }

}


//function to find item and return is info
QString software::finditem(QString value)
{
    bool test=true;
    for(int i=0;i<numberofitems();i++){
         if ((value==QString::fromStdString(items[i]->ID))^(value==QString::fromStdString(items[i]->title))^(value==QString::fromStdString(items[i]->author))^(value==QString::fromStdString(items[i]->date_of_creation)))
         {
            test=false;
            return seeitem(i);
         }
    }
    if (test==true)
    {
        QMessageBox msgBox;
        msgBox.setText("Error this item dont exist");
        msgBox.exec();
        return 0;
    }

}
//=========================================================================modify cart Customer======================================================
//================================================================================================================================================
//add a new item to the customer cart
void software::addtocart(QString  customer,QString item )
{
    for(int i=0;i<numberofcustomers;i++)
    {
        if(customer==QString::fromStdString(customers[i]->seecustomer()))
        {
            QStringList list = item.split('|');
            customers[i]->addcart((list[0]).toStdString(),(list[1]).toStdString(),(list[2]).toStdString(),(list[3]).toStdString(),(list[4]).toStdString());
            qDebug()<<"Items added";
        }
    }
    for(int i=0;i<numberofitems();i++ )
    {
        if(item==QString::fromStdString(items[i]->seeitems()))
        {
            int x=stoi(items[i]->number_of_this_item)-1;
            items[i]->number_of_this_item=to_string(x);
            qDebug()<<"stock updated";
                if(items[i]->number_of_this_item=="0")
                    {

                        items.erase(items.begin()+i);
                        qDebug()<<"this item is destroyed, out of stock";
                    }
        }
    }
}

//return number of item in a cart for all classes who need it
int software::numbercart(int j)
{
    return customers[j]->nbritems();
}

//return value of an item for a customer j=customer row, i=cart row for all the classes
QString software::seeitemcart(int j,int i)
{
    return QString::fromStdString(customers[j]->seeitem(i));
}

//=========================================================================Customer======================================================
//================================================================================================================================================
//initialize some customers
void software::bddcustomers()
{

    customers[0]=new Customer("1001","Pierrick","7 rue du hareng","0647554613");
    customers[1]=new Customer("1002","Jean","Seinajoki plage","0745898541");
    customers[2]=new Customer("1003","Michel","7 lama street","0647554613");
    customers[3]=new Customer("1004","Patrick","becker street","009-8975");


}

//return number of customer for all classes who need it
int software::numberofcustomerss()
{
    return numberofcustomers;
}

//return info of a customer for all classes who need it
QString software::seecustomer(int i)
{
    return QString::fromStdString( customers[i]->seecustomer());
}

//create a new customer
void software::newcustomer(QString value)
{
    QStringList list = value.split('|');
    customers[numberofcustomers++]=new Customer(to_string(1001+numberofcustomers),(list[0]).toStdString(),(list[1]).toStdString(),(list[2]).toStdString());

}

//display seecustomer with good data
void software::dialogseecustomer(int x)
{
    Dialogcustomerfinder* dialog= new Dialogcustomerfinder();
    dialog->setvalue( QString::fromStdString( customers[x]->ID), QString::fromStdString( customers[x]->Name), QString::fromStdString(customers[x]->Adress), QString::fromStdString( customers[x]->Phonenumber) );
    if(customers[x]->nbritems()!=0){
        dialog->setcart(x, customers[x]->nbritems());
    }
    dialog->show();

}

//display seecustomer with good data from rsh
void software::dialogseecustomer(QString y)
{
    Dialogcustomerfinder* dialog= new Dialogcustomerfinder();
    for(int i=0;i<numberofcustomers;i++)
    {
        if((y==QString::fromStdString(customers[i]->Name))^(y==QString::fromStdString( customers[i]->Adress))^(y==QString::fromStdString( customers[i]->ID)))
        {
           dialog->setvalue( QString::fromStdString( customers[i]->ID), QString::fromStdString(customers[i]->Name), QString::fromStdString( customers[i]->Adress), QString::fromStdString( customers[i]->Phonenumber) );
           dialog->setcart(i,customers[i]->nbritems());
           dialog->show();
        }
    }
}

//========================================================================= Items======================================================
//================================================================================================================================================

//initialize data from items
void software::bddcitems()
{
       items.push_back( new Book("1001", "Book", "The_c++_Bible", "Meee", "10/10/2020", "5"));
       items.push_back(new Book("1002", "Book", "The_life_of_Mc_arthur", "Jhonny_Monnay", "05/05/2020", "1"));
       items.push_back(new Book("1003", "Book", "Hola_Chicos", "Meee", "07/08/1900", "9"));
       items.push_back(new Book("1004", "Book", "The life", "Michel", "07/08/1900", "89"));
       items.push_back ( new Magazine("2001", "Magazine", "Bumblebee", "lapin", "10/10/2020", "2"));
       items.push_back ( new CD("3001", "CD", "HammerJack", "AlbertDeMontJean", "10/10/2050", "1"));
       items.push_back ( new diverses("9001", "Figurine", "Starcraft1", "Marines", "01/01/1999", "6"));

}


//return the number of item for all classes who need it
int software::numberofitems()
{
    int x= items.size();
    return x;
}

//return info from an item for all classes who neeed it
QString software::seeitem(int i)
{
    return QString::fromStdString(items[i]->seeitems());
}

//function for customer return item
void software::returnitem(QString value, int customer, int row)
{
    bool test=true;

    QStringList list = value.split('|');
    for(int i=0;i<items.size();i++)
    {
        if((list[0].toStdString())==(items[i]->seeitems()).substr(0,5)+" "){
            int x=stoi(items[i]->number_of_this_item)+1;
            items[i]->number_of_this_item=to_string(x);
            test=false;
        }
    }
    if(test==true){
        qDebug()<<list[1]+"|"+list[2]+"|"+list[3]+"|"+list[4]+"| 1";
        newitem(list[1]+"|"+list[2]+"|"+list[3]+"|"+list[4]+"| 1" );

     }

    customers[customer]->deletcartrow(row);
}

//function to add new item
void software::newitem(QString value)
{
    QStringList list = value.split('|');
    list[0].replace(" ","");
    list[1].replace(" ","");
    list[2].replace(" ","");
    list[3].replace(" ","");
    list[4].replace(" ","");

    string list0=list[0].toStdString();
    string list1=list[1].toStdString();
    string list2=list[2].toStdString();
    string list3=list[3].toStdString();
    string list4=list[4].toStdString();



    if(list0=="Book"){
     items.push_back ( new Book((to_string(1001+numberofbook)),"Book",list1,list2,list3,list4));
     numberofbook++;
    }
    if(list0=="Magazine"){
     items.push_back ( new Magazine((to_string(2001+numberofmagazine)),"Magazine",list1,list2,list3,list4));
     numberofmagazine++;
    }
    if(list0=="CD"){
      items.push_back ( new CD((to_string(3001+numberofcd)),"CD",list1,list2,list3,list4));
      numberofcd++;
    }
    if((list0!="CD")^(list0!="Magazine")^(list0!="Book"))
    {
      items.push_back ( new diverses((to_string(9001+numberofother)),list0,list1,list2,list3,list4));
      numberofother++;
    }

}


//function to set and show dialog seeitem
void software::dialogueseeitem(int x)
{
    Dialogseeitems* dialog= new Dialogseeitems();
    dialog->setvalue(QString::fromStdString(items[x]->ID),QString::fromStdString(items[x]->type),QString::fromStdString(items[x]->title),QString::fromStdString(items[x]->author),QString::fromStdString(items[x]->date_of_creation),QString::fromStdString(items[x]->number_of_this_item));
    dialog->show();
}
//function to set and show dialog seeitem with rsh button
void software::dialogueseeitem(QString y)
{
    Dialogseeitems* dialog= new Dialogseeitems();
    for(int i=0;i<numberofcustomers;i++)
    {
        if((y==QString::fromStdString(items[i]->ID))^(y==QString::fromStdString( items[i]->title))^(y==QString::fromStdString( items[i]->author)))
        {
            dialog->setvalue(QString::fromStdString(items[i]->ID),QString::fromStdString(items[i]->type),QString::fromStdString(items[i]->title),QString::fromStdString(items[i]->author),QString::fromStdString(items[i]->date_of_creation),QString::fromStdString(items[i]->number_of_this_item));
            dialog->show();
        }
    }
}
