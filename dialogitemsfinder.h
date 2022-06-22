#ifndef DIALOGITEMSFINDER_H
#define DIALOGITEMSFINDER_H

#include <QDialog>

namespace Ui {
class Dialogitemsfinder;
}

class Dialogitemsfinder : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogitemsfinder(QWidget *parent = nullptr);
    ~Dialogitemsfinder();
    void createnew();
    void closes();
    void changestate();

private:
    Ui::Dialogitemsfinder *ui;
};

#endif // DIALOGITEMSFINDER_H
