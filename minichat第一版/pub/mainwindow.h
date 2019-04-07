#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <iostream>
#include <ndds/ndds_cpp.h>
#include <string>
#include <QString>
#include <testthread.h>
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
signals:
    void newSendDataAvailable(QString content);

public slots://槽
    void changeButtonStateSlot();
    void appendMessageSlot();

};

#endif // MAINWINDOW_H
