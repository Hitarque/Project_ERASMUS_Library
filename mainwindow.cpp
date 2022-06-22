#include "mainwindow.h"
#include "software.h"

#include "./ui_mainwindow.h"

#include<QMessageBox>

//constructor of the mainwindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    refresh1();
    refresh2();
    //additem button
    connect(ui->pushButtonsitems_3,&QPushButton::clicked,this,&MainWindow::addbuttonclicked);
    //tab 1 customer
    connect(ui->pushButtoncustomers,&QPushButton::clicked,this,&MainWindow::linkdialogcustomerfinder);
    connect(ui->buttonrefresh,&QPushButton::clicked,this,&MainWindow::refresh1);
    connect(ui->pushButtonsnewcustomers,&QPushButton::clicked,this,&MainWindow::newcustomers);
    connect(ui->listWidgetcustomers,&QListWidget::itemSelectionChanged,this,&MainWindow::linkdialogcustomerselecteditem);
    //tab2 items
    connect(ui->pushButtonsitems,&QPushButton::clicked,this,&MainWindow::linkdialogitemfinder);
    connect(ui->buttonrefresh_2,&QPushButton::clicked,this,&MainWindow::refresh2);
    connect(ui->pushButtonsitems_2,&QPushButton::clicked,this,&MainWindow::newitems);
    connect(ui->listWidget_2,&QListWidget::itemSelectionChanged,this,&MainWindow::linkdialogitemsrselecteditem);
    connect(ui->pushButtonsitems_4,&QPushButton::clicked,this,&MainWindow::closeall);
}

//close button
void MainWindow::closeall()
{
        this->close();
}

//destructor of the UI
MainWindow::~MainWindow()
{
        delete ui;
}
//=========================================================================add item button======================================================
//================================================================================================================================================
//action for addbutton
void MainWindow::addbuttonclicked()
{
    dialogaddtocart* dialog= new dialogaddtocart();
    dialog->show();

}



//=========================================================================///tab 1 customer======================================================
//================================================================================================================================================
//refresh the tab for tab1 customer
void MainWindow::refresh1()
{
    ui->listWidgetcustomers->clear();
    int x= software::numberofcustomerss();
    for(int i=0;i<x;i++)
    {
         ui->listWidgetcustomers->addItem( software::seecustomer(i));
    }
}
//add new customer
void MainWindow::newcustomers()
{
    Dialogcustomercreate* dialog= new Dialogcustomercreate();
    dialog->show();
}
//give data for see dialog
void MainWindow::linkdialogcustomerselecteditem()
{
    int x=(ui->listWidgetcustomers->currentRow());
    software::dialogseecustomer(x);
}

//give data for see dialog
void MainWindow::linkdialogcustomerfinder()
{
    QString y=ui->plainTextEditcustomer->toPlainText();
    software::dialogseecustomer(y);
}
//=========================================================================///tab 2 Items======================================================
//================================================================================================================================================
//refresh the tab for tab2 item
void MainWindow::refresh2()
{
    ui->listWidget_2->clear();

    int x= software::numberofitems();

    for(int i=0;i<x;i++)
    {
         ui->listWidget_2->addItem( software::seeitem(i));
    }
    qDebug()<<"Items loaded";
}

//add a new item
void MainWindow::newitems()
{
    Dialogitemsfinder* dialog= new Dialogitemsfinder();
    dialog->show();
}
//give data for see dialog
void MainWindow::linkdialogitemsrselecteditem()
{
    int x=(ui->listWidget_2->currentRow());
    software::dialogueseeitem(x);
}
//give data for see dialog
void MainWindow::linkdialogitemfinder()
{
    QString y=ui->plainTextEdititems->toPlainText();
    software::dialogueseeitem(y);
}
