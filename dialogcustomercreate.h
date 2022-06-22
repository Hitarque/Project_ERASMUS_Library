#ifndef DIALOGCUSTOMERCREATE_H
#define DIALOGCUSTOMERCREATE_H

#include <QDialog>

namespace Ui {
class Dialogcustomercreate;
}

class Dialogcustomercreate : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogcustomercreate(QWidget *parent = nullptr);
    ~Dialogcustomercreate();
   void  createnew();
    void closes();

private:
    Ui::Dialogcustomercreate *ui;
};

#endif // DIALOGCUSTOMERCREATE_H
