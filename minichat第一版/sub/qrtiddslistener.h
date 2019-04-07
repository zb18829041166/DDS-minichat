#ifndef QRTIDDSLISTENER_H
#define QRTIDDSLISTENER_H

#include <stdio.h>
#include <stdlib.h>
#ifdef RTI_VX653
#include <vThreadsData.h>
#endif
#include "minichat.h"
#include "minichatSupport.h"
#include "ndds/ndds_cpp.h"
#include <QObject>
#include <QDebug>
#include <QString>
#include <QTimer>
#include "ndds/ndds_cpp.h"

class QrtiDDSlistener : public QObject, public DDSDataReaderListener
{
    Q_OBJECT
public:
    QrtiDDSlistener(QObject *parent);

signals:
    void newData(QString data);

public slots:

private:
    void on_data_available(DDSDataReader *reader);
};

#endif // QRTIDDSLISTENER_H
