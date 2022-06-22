#include "dialogeaster.h"
#include "ui_dialogeaster.h"


#include <QPixmap>
#include<QDebug>
#include<QDialog>

Dialogeaster::Dialogeaster(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogeaster)
{
    ui->setupUi(this);


        QString filename = ":/image/pic2.png";
        /** set content to show center in label */
        ui->label_pic->setAlignment(Qt::AlignCenter);
        QPixmap pix;

        /** to check wether load ok */
        if(pix.load(filename)){
            qDebug("loaded");
            /** scale pixmap to fit in label'size and keep ratio of pixmap */
            pix = pix.scaled(ui->label_pic->size(),Qt::KeepAspectRatio);
            ui->label_pic->setPixmap(pix);
        }
}

Dialogeaster::~Dialogeaster()
{
    delete ui;
}

int Dialogeaster::returnend()
{
    return 1;
}
