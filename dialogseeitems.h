#ifndef DIALOGSEEITEMS_H
#define DIALOGSEEITEMS_H

#include <QDialog>

namespace Ui {
class Dialogseeitems;
}

class Dialogseeitems : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogseeitems(QWidget *parent = nullptr);
    ~Dialogseeitems();
    void setvalue(QString ID,QString type, QString title, QString author,QString date,QString number);

private:
    Ui::Dialogseeitems *ui;
};

#endif // DIALOGSEEITEMS_H
