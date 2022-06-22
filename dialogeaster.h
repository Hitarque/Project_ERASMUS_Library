#ifndef DIALOGEASTER_H
#define DIALOGEASTER_H

#include <QDialog>

namespace Ui {
class Dialogeaster;
}

class Dialogeaster : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogeaster(QWidget *parent = nullptr);
    ~Dialogeaster();
    int returnend();

private:
    Ui::Dialogeaster *ui;
};

#endif // DIALOGEASTER_H
