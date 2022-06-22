#ifndef DIALOGCUSTOMERFINDER_H
#define DIALOGCUSTOMERFINDER_H

#include"software.h"

#include <QDialog>
using namespace std;

namespace Ui {
class Dialogcustomerfinder;
}

class Dialogcustomerfinder : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogcustomerfinder(QWidget *parent = nullptr);
    ~Dialogcustomerfinder();
    void setvalue(QString ID,QString name, QString adress, QString phonenumber);

    void setcart(int j,int numbercart);
    void returnitem();

private:
    Ui::Dialogcustomerfinder *ui;
};

#endif // DIALOGCUSTOMERFINDER_H
