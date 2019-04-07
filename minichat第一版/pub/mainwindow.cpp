#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <testthread.h>
#include <QMovie>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    t = new TestThread(this);
    connect(ui->writeMessageEdit,SIGNAL(textChanged()),this,SLOT(changeButtonStateSlot()));//输入信息时候按钮变为可用状态
    connect(ui->sendButton,SIGNAL(clicked()),this,SLOT(appendMessageSlot()));//点击发送按钮，调用该槽函数

    QMovie *a = new QMovie(":\send.gif");
    a->start();
    ui->gif->setMovie(a);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeButtonStateSlot()
{
    bool boo_dis=ui->writeMessageEdit->toPlainText().isEmpty();
    ui->sendButton->setDisabled(boo_dis);
}

void MainWindow::appendMessageSlot(){
    QString content=ui->writeMessageEdit->toPlainText();
    ui->showMessageEdit->append(QString("%1").arg(content));
    ui->writeMessageEdit->clear();  
    emit newSendDataAvailable(content);
    t->start();
}
