#ifndef QRTIDDS_H
#define QRTIDDS_H
#include <QDebug>
#include <QObject>
#include <string>
#include <ndds/ndds_cpp.h>
#include <ndds/ndds_namespace_cpp.h>
#include <QString>
#include "qrtiddslistener.h"
#include <stdio.h>
#include <stdlib.h>
#ifdef RTI_VX653
#include <vThreadsData.h>
#endif
#include "minichat.h"
#include "minichatSupport.h"
#include "ndds/ndds_cpp.h"

class QrtiDDS : public QObject
{
    Q_OBJECT
public:
    explicit QrtiDDS(QObject *parent = 0);
    QrtiDDS(QObject *parent, QrtiDDSlistener *rtiDDSlistener);
    ~QrtiDDS();

    DDSDomainParticipant *participant ;
    DDSSubscriber *subscriber ;
    DDSTopic *topic;
    QrtiDDSlistener *rtiDDSlistener ;
    DDSDataReader *reader ;
    DDS_ReturnCode_t retcode;
    const char *type_name ;
    //int count = 0;
    DDS_Duration_t receive_period ;
    int status ;


private:
    int setupQrtiDDS();
    int subscriber_shutdown(DDSDomainParticipant *participant);
};

#endif // QRTIDDS_H
