#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <testthread.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    rtiDDSlistener = new QrtiDDSlistener(this);
    t = new TestThread(this,rtiDDSlistener);
    connect(ui->writeMessageEdit,SIGNAL(textChanged()),this,SLOT(changeButtonStateSlot()));//输入信息时候按钮变为可用状态
    connect(ui->sendButton,SIGNAL(clicked()),this,SLOT(appendMessageSlot()));//点击发送按钮，调用该槽函数
    connect(rtiDDSlistener, SIGNAL(newData(QString)),
            this, SLOT(readListenerData(QString)),
            Qt::QueuedConnection);
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
   // DDS_Duration_t send_period = {1,0};
    //for(int i=0;i<100;i++){
   // content=QString::number(i,10);
    qDebug()<<"write data"<<content;
    emit newSendDataAvailable(content);
    ui->showMessageEdit->append(QString("%1").arg(content));
    ui->writeMessageEdit->clear();  
    t->start();
 //   NDDSUtility::sleep(send_period);
 // }
}

void MainWindow::readListenerData(QString data){
    qDebug()<<"show data"<<data;
    ui->showMessageEdit->append(data);
}
