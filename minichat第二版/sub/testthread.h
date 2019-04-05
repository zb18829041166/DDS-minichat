#ifndef TESTTHREAD_H
#define TESTTHREAD_H

#include <QThread>
#include <QString>
#include <ndds/ndds_cpp.h>
#include <ndds/ndds_namespace_cpp.h>
#include <QObject>
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#ifdef RTI_VX653
#include <vThreadsData.h>
#endif
#include "minichat.h"
#include "minichatSupport.h"
#include "ndds/ndds_cpp.h"
#include "qrtiddslistener.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>

class TestThread:public QThread
{
    Q_OBJECT
public:

    explicit TestThread(QObject *parent);
    void readtxt();
    TestThread(QObject *parent, QrtiDDSlistener *rtiDDSlistener);
    QrtiDDSlistener *rtiDDSlistener ;
    DDSSubscriber *subscriber ;
    DDSDomainParticipant *participant ;
    DDSPublisher *publisher ;
    DDSTopic *topic ;
    DDSDataWriter *writer ;
    MiniChatDataWriter * MiniChat_writer ;
    MiniChat *instance ;
    DDS_ReturnCode_t retcode;
    DDS_InstanceHandle_t instance_handle ;
    const char *type_name ;
    int count ;
    DDS_Duration_t send_period ;
    int    main_result;
    DDSDataReader *reader ;
    DDS_Duration_t receive_period ;
    int status ;
protected:
    void run();

public slots:
    void publishDDS(QString data);
private:
    int setupQrtiDDS();
    int publisher_shutdown(DDSDomainParticipant *participant);
};

#endif // TESTTHREAD_H
