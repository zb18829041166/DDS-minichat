#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>
int main(int argc, char *argv[])
{   QTextCodec *codec = QTextCodec::codecForName("System");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
