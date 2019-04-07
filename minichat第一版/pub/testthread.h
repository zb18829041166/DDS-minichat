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

class TestThread:public QThread
{
    Q_OBJECT
public:

    explicit TestThread(QObject *parent);
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
protected:
    void run();

public slots:
    void publishDDS(QString data);
private:
    int setupQrtiDDS();
    int publisher_shutdown(DDSDomainParticipant *participant);
};

#endif // TESTTHREAD_H
