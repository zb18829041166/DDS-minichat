#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUp_rtiDDS_handler();

    QMovie *b = new QMovie(":\/recieve.gif");
    b->start();
    ui->gif->setMovie(b);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUp_rtiDDS_handler()
{
    rtiDDSlistener = new QrtiDDSlistener(this);
    rtiDDS = new QrtiDDS(this, rtiDDSlistener);
    connect(rtiDDSlistener, SIGNAL(newData(QString)),
            this, SLOT(readListenerData(QString)),
            Qt::QueuedConnection);
}

void MainWindow::readListenerData(QString data){
    qDebug()<<data;
    ui->showMessage->append(data);
}
