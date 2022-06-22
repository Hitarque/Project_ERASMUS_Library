#include "dialogcustomerfinder.h"
#include "ui_dialogcustomerfinder.h"

int line;

//setup UI
Dialogcustomerfinder::Dialogcustomerfinder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogcustomerfinder)
{
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Dialogcustomerfinder::returnitem);

}

//destructor for ui
Dialogcustomerfinder::~Dialogcustomerfinder()
{
    delete ui;
}


//setvalue in the customerfinder dialog
void Dialogcustomerfinder::setvalue(QString ID,QString name, QString adress, QString phonenumber)
{
    ui->label_4->setText("ID:"+ID);
    ui->textEdit->setText(name);
    ui->textEdit_2->setText(adress);
    ui->textEdit_3->setText(phonenumber);
}

//set value in the cart
void Dialogcustomerfinder::setcart(int j, int numbercart)
{

    line =j;
    if(numbercart!=0){
    for(int i=0;i<numbercart;i++)
        {
        ui->listWidget->addItem(software::seeitemcart(j,i));
        ui->pushButton_2->setEnabled(true);
        }
    }
    else
    {
        ui->listWidget->addItem("");
    }

    ui->listWidget->setCurrentRow(0);

}

//returnitem to database
void Dialogcustomerfinder::returnitem()
{
        software::returnitem(ui->listWidget->currentItem()->text(),line,ui->listWidget->currentRow());
        ui->listWidget->takeItem(ui->listWidget->currentRow());
}
