#include "dialogcustomercreate.h"
#include "software.h"

#include<QMessageBox>

#include "ui_dialogcustomercreate.h"


//setup UI
Dialogcustomercreate::Dialogcustomercreate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogcustomercreate)
{
    ui->setupUi(this);

    connect(ui->pushButton_3,&QPushButton::clicked,this,&Dialogcustomercreate::createnew);
    connect(ui->pushButton,&QPushButton::clicked,this,&Dialogcustomercreate::closes);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Dialogcustomercreate::closes);
}

//destructor for ui
Dialogcustomercreate::~Dialogcustomercreate()
{
    delete ui;
}

//create a new customer
void Dialogcustomercreate::createnew()
{
    if((ui->textEdit->toPlainText()=="")||(ui->textEdit_2->toPlainText()=="")||(ui->textEdit_3->toPlainText()=="")){
        QMessageBox msgBox;
        msgBox.setText("Error, please fill all the fields ");
        msgBox.exec();}
    else{
        QString value= ui->textEdit->toPlainText()+"|"+ui->textEdit_2->toPlainText()+"|"+ui->textEdit_3->toPlainText();
        software::newcustomer(value);
        ui->pushButton_3->setEnabled(false);
    }
}

//close dialog
void Dialogcustomercreate::closes()
{
    this->close();
}

