#include "dialogaddtocart.h"
#include "ui_dialogaddtocart.h"

#include<QMessageBox>



//setup UI
dialogaddtocart::dialogaddtocart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogaddtocart)
{
    ui->setupUi(this);
    initializes();
    initializess();
    ui->listWidget->addItem("");
    ui->comboBox_2->setEnabled(false);
    ui->listWidget->setEnabled(false);
    ui->textEdit_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);

    connect(ui->pushButton,&QPushButton::clicked,this,&dialogaddtocart::rshcustomer);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&dialogaddtocart::rshitem);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&dialogaddtocart::validatecustomerbutton);
    connect(ui->pushButton_4,&QPushButton::clicked,this,&dialogaddtocart::addtomemorie);
    connect(ui->pushButton_6,&QPushButton::clicked,this,&dialogaddtocart::removetomemorie);
     connect(ui->pushButton_5,&QPushButton::clicked,this,&dialogaddtocart::addtocart);

}

//destructor of UI
dialogaddtocart::~dialogaddtocart()
{
    delete ui;
}

//button add evenement, return to software class
void dialogaddtocart::addtocart()
{
    for(int i=1;i<(ui->listWidget->count());i++)
    {
        qDebug() << i;
        ui->listWidget->setCurrentRow(i);
        software::addtocart(ui->comboBox->currentText(),(ui->listWidget->currentItem()->text()));

    }
ui->listWidget->clear();
this->close();
}


//add in memory
void dialogaddtocart::addtomemorie()
{
   if(ui->comboBox_2->currentText()!=""){
       ui->listWidget->addItem(ui->comboBox_2->currentText());
       int i= ui->comboBox_2->currentIndex();
       ui->comboBox_2->removeItem(i);
   }
   else
   {
       QMessageBox msgBox;
       msgBox.setText("It's impossible to add nothing in the cart");
       msgBox.exec();
   }


}

//remove from memory
void dialogaddtocart::removetomemorie()
{
   ui->comboBox_2->addItem(ui->listWidget->item(ui->listWidget->currentRow())->text());
   ui->listWidget->takeItem(ui->listWidget->currentRow());

}


//set enabled true/false part of the qDialog to allow user to use part
void dialogaddtocart::validatecustomerbutton()
{
    ui->comboBox->setEnabled(false);
    ui->textEdit->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);

    ui->comboBox_2->setEnabled(true);
    ui->listWidget->setEnabled(true);
    ui->textEdit_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
}



//find customer
void dialogaddtocart::rshcustomer()
{
    QString value=software::findcustomer(ui->textEdit->toPlainText());
    ui->comboBox->setCurrentText(value);
}


//find item
void dialogaddtocart::rshitem()
{
    QString value=software::finditem(ui->textEdit_2->toPlainText());
    ui->comboBox_2->setCurrentText(value);
}

//intializes data in combobox customer
void dialogaddtocart::initializes()
{
    for(int i=0;i<software::numberofcustomerss();i++)
    {
        ui->comboBox->addItem(software::seecustomer(i));

    }
}


//intializes data in combobox items
void dialogaddtocart::initializess()
{
    for(int i=0;i<software::numberofitems();i++)
        {

        ui->comboBox_2->addItem(software::seeitem(i));
        }

}
