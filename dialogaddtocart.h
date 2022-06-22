#ifndef DIALOGADDTOCART_H
#define DIALOGADDTOCART_H

#include <QDialog>
#include "software.h"


namespace Ui {
class dialogaddtocart;
}

class dialogaddtocart : public QDialog
{
    Q_OBJECT

public:
    explicit dialogaddtocart(QWidget *parent = nullptr);
    ~dialogaddtocart();

    //initialize the dialog windows
    void initializes();
    void initializess();

    void rshcustomer();
    void validatecustomerbutton();
    void rshitem();
    void addtomemorie();
    void removetomemorie();
    void addtocart();
    void sort();

private:
    Ui::dialogaddtocart *ui;
    int test=0;
    QString valued;
    int numberofrow=0;
};

#endif // DIALOGADDTOCART_H
