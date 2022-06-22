#include "mainwindow.h"
#include "software.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Finalprojectv2_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    new software();
    qDebug()<<"Software load";
    MainWindow w;
    qDebug()<<"Main window load";
    qDebug()<<"Enjoy your use:D";
    w.show();


    return a.exec();
}

