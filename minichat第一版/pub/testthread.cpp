#include "testthread.h"
QString message;


TestThread::TestThread(QObject *parent) :
    QThread(parent)
{
    DDSDomainParticipant *participant = NULL;
    DDSPublisher *publisher = NULL;
    DDSTopic *topic = NULL;
    DDSDataWriter *writer = NULL;
    MiniChatDataWriter * MiniChat_writer = NULL;
    MiniChat *instance = NULL;
    DDS_ReturnCode_t retcode;
    DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;
    const char *type_name = NULL;
    int count = 0;
    DDS_Duration_t send_period = {1,0};  //延迟1秒
    int success = setupQrtiDDS();
    if (success != 0)
    {
        qDebug()<<__FUNCTION__<<__LINE__  << "Couldn't setup DDS Objects";
    }
}

void TestThread::run()
{
    instance = MiniChatTypeSupport::create_data();

    strncpy(instance->MiniChat,message.toUtf8().constData(),32);

    /* Main loop */
    for (count=0; count<1; ++count) {

        printf("Writing MiniChat, count %d\n", count);

        /* Modify the data to be sent here */
        retcode = MiniChat_writer->write(*instance, instance_handle);
        if (retcode != DDS_RETCODE_OK) {
            printf("write error %d\n", retcode);
        }
        NDDSUtility::sleep(send_period);
    }
   // string_writer->write(message.toUtf8().constData(), DDS_HANDLE_NIL);
}

void TestThread::publishDDS(QString data){
    message=data;
}

int TestThread::setupQrtiDDS()
{
    int domainId=0;
    /* To customize participant QoS, use
       the configuration file USER_QOS_PROFILES.xml */
    participant = DDSTheParticipantFactory->create_participant(
        domainId, DDS_PARTICIPANT_QOS_DEFAULT,
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        printf("create_participant error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* To customize publisher QoS, use
       the configuration file USER_QOS_PROFILES.xml */
    publisher = participant->create_publisher(
        DDS_PUBLISHER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (publisher == NULL) {
        printf("create_publisher error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Register type before creating topic */
    type_name = MiniChatTypeSupport::get_type_name();
    retcode = MiniChatTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        printf("register_type error %d\n", retcode);
        publisher_shutdown(participant);
        return -1;
    }

    /* To customize topic QoS, use
       the configuration file USER_QOS_PROFILES.xml */
    topic = participant->create_topic(
        "Example MiniChat",
        type_name, DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create_topic error\n");
          publisher_shutdown(participant);
        return -1;
    }

    /* To customize data writer QoS, use
       the configuration file USER_QOS_PROFILES.xml */
    writer = publisher->create_datawriter(
        topic, DDS_DATAWRITER_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        printf("create_datawriter error\n");
        publisher_shutdown(participant);
        return -1;
    }
    MiniChat_writer = MiniChatDataWriter::narrow(writer);
    if (MiniChat_writer == NULL) {
        printf("DataWriter narrow error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Create data sample for writing */



/*
    retcode = MiniChat_writer->unregister_instance(
        *instance, instance_handle);
    if (retcode != DDS_RETCODE_OK) {
        printf("unregister instance error %d\n", retcode);
    }
*/

    /* Delete data sample */
    //retcode = MiniChatTypeSupport::delete_data(instance);
    //if (retcode != DDS_RETCODE_OK) {
    //    printf("MiniChatTypeSupport::delete_data error %d\n", retcode);
   // }

    /* Delete all entities */
    //return publisher_shutdown(participant);
    connect(parent(), SIGNAL(newSendDataAvailable(QString)), this, SLOT(publishDDS(QString)),Qt::QueuedConnection);
    return 0;
}


/* Delete all entities */
int TestThread::publisher_shutdown(
    DDSDomainParticipant *participant)
{
    DDS_ReturnCode_t retcode;
    int status = 0;

    if (participant != NULL) {
        retcode = participant->delete_contained_entities();
        if (retcode != DDS_RETCODE_OK) {
            printf("delete_contained_entities error %d\n", retcode);
            status = -1;
        }

        retcode = DDSTheParticipantFactory->delete_participant(participant);
        if (retcode != DDS_RETCODE_OK) {
            printf("delete_participant error %d\n", retcode);
            status = -1;
        }
    }

    /* RTI Connext provides finalize_instance() method on
       domain participant factory for people who want to release memory used
       by the participant factory. Uncomment the following block of code for
       clean destruction of the singleton. */
/*
    retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        printf("finalize_instance error %d\n", retcode);
        status = -1;
    }
*/

    return status;
}
