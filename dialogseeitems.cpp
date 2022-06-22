#include "dialogseeitems.h"
#include "ui_dialogseeitems.h"

//setup UI
Dialogseeitems::Dialogseeitems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogseeitems)
{
    ui->setupUi(this);
}

//destructor for UI
Dialogseeitems::~Dialogseeitems()
{
    delete ui;
}

//initialize value
void Dialogseeitems::setvalue(QString ID,QString type, QString title, QString author,QString date,QString number)
{
    ui->textEdit_6->setText(ID);
    ui->textEdit_6->setEnabled(false);
    ui->textEdit->setText(type);
    ui->textEdit_2->setText(title);
    ui->textEdit_3->setText(author);
    ui->textEdit_4->setText(date);
    ui->textEdit_5->setText(number);
}
