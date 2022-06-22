#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogeaster.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addbuttonclicked();
    void closeall();
    //=========================================================================///tab 1 customer======================================================
    //================================================================================================================================================
    void linkdialogcustomerfinder();
    void linkdialogcustomerselecteditem();
    void refresh1();
    void newcustomers();
    //=========================================================================///tab 2 Items========================================================
    //================================================================================================================================================
    void refresh2();
    void newitems();
    void linkdialogitemsrselecteditem();
    void linkdialogitemfinder();



private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
