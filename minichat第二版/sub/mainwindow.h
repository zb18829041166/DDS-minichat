#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <iostream>
#include <ndds/ndds_cpp.h>
#include <string>
#include <QString>
#include <testthread.h>
#include <qrtiddslistener.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    TestThread *t;
    QrtiDDSlistener      * rtiDDSlistener;
signals:
    void newSendDataAvailable(QString content);

public slots://槽
    void changeButtonStateSlot();
    void appendMessageSlot();
    void readListenerData(QString data);
};

#endif // MAINWINDOW_H
