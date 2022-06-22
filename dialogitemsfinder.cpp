#include "dialogitemsfinder.h"
#include "ui_dialogitemsfinder.h"
#include "software.h"

#include<QMessageBox>

//setup UI
Dialogitemsfinder::Dialogitemsfinder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogitemsfinder)
{
    ui->setupUi(this);

    ui->textEdit_5->setEnabled(false);
    connect(ui->pushButton,&QPushButton::clicked,this,&Dialogitemsfinder::createnew);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&Dialogitemsfinder::closes);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Dialogitemsfinder::closes);
    connect(ui->radioButton_4,&QPushButton::clicked,this,&Dialogitemsfinder::changestate);
}

//destructor for UI
Dialogitemsfinder::~Dialogitemsfinder()
{
    delete ui;
}

//if the item is not a classic, allow the user to give it a type
void Dialogitemsfinder::changestate()
{
   ui->textEdit_5->setEnabled(true);
}


//create the new item
void Dialogitemsfinder::createnew()
{
    if((ui->textEdit->toPlainText()=="")||(ui->textEdit_2->toPlainText()=="")||(ui->textEdit_3->toPlainText()=="")){
        QMessageBox msgBox;
        msgBox.setText("Error, please fill all the fields ");
        msgBox.exec();}
    else{
        QString value;
            if(ui->radioButton->isChecked())
            {
                ui->textEdit_5->setText("Book");
                value= ui->textEdit_5->toPlainText()+"|"+ ui->textEdit->toPlainText()+"|"+ui->textEdit_2->toPlainText()+"|"+ui->textEdit_3->toPlainText()+"|"+ui->textEdit_4->toPlainText();
            }
            if(ui->radioButton_2->isChecked())
            {
                ui->textEdit_5->setText("Magazine");
                value= ui->textEdit_5->toPlainText()+"|"+ui->textEdit->toPlainText()+"|"+ui->textEdit_2->toPlainText()+"|"+ui->textEdit_3->toPlainText()+"|"+ui->textEdit_4->toPlainText();
            }
            if(ui->radioButton_3->isChecked())
            {
                ui->textEdit_5->setText("CD");
                value=ui->textEdit_5->toPlainText()+"|"+ ui->textEdit->toPlainText()+"|"+ui->textEdit_2->toPlainText()+"|"+ui->textEdit_3->toPlainText()+"|"+ui->textEdit_4->toPlainText();
            }
            if(ui->radioButton_4->isChecked())
            {

                value= ui->textEdit_5->toPlainText()+"|"+ui->textEdit->toPlainText()+"|"+ui->textEdit_2->toPlainText()+"|"+ui->textEdit_3->toPlainText()+"|"+ui->textEdit_4->toPlainText();
            }
            software::newitem(value);
            ui->pushButton->setEnabled(false);




    }
}

//close dialog
void Dialogitemsfinder::closes()
{
    this->close();
}
