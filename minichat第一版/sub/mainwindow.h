#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <iostream>
#include <ndds/ndds_cpp.h>
#include <string>
#include <QString>
#include <qrtiddslistener.h>
#include <qrtidds.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
     void setUp_rtiDDS_handler();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void readListenerData(QString data);

private:
    QrtiDDS              * rtiDDS;
    QrtiDDSlistener      * rtiDDSlistener;
};

#endif // MAINWINDOW_H
