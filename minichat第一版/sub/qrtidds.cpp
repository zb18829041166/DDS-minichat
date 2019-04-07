#include "qrtidds.h"

QrtiDDS::QrtiDDS(QObject *parent, QrtiDDSlistener *listener) : QObject(parent)
{
    DDSDomainParticipant *participant = NULL;
    DDSSubscriber *subscriber = NULL;
    DDSTopic *topic = NULL;
    QrtiDDSlistener *reader_listener = NULL;
    DDSDataReader *reader = NULL;
    DDS_ReturnCode_t retcode;
    const char *type_name = NULL;
    int status = 0;
    rtiDDSlistener = listener;
    DDS_Duration_t receive_period = {1,0};
    int success = setupQrtiDDS();
    if (success != 0)
    {
        qDebug()<< "Couldn't setup DDS Objects";
    }
}
QrtiDDS::~QrtiDDS()
{

}

int QrtiDDS::setupQrtiDDS()
{
    int domainId=0;
    /* To customize the participant QoS, use
       the configuration file USER_QOS_PROFILES.xml */
    participant = DDSTheParticipantFactory->create_participant(
        domainId, DDS_PARTICIPANT_QOS_DEFAULT,
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        printf("create_participant error\n");
        subscriber_shutdown(participant);
        return -1;
    }

    /* To customize the subscriber QoS, use
       the configuration file USER_QOS_PROFILES.xml */
    subscriber = participant->create_subscriber(
        DDS_SUBSCRIBER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (subscriber == NULL) {
        printf("create_subscriber error\n");
      subscriber_shutdown(participant);
        return -1;
    }

    /* Register the type before creating the topic */
    type_name = MiniChatTypeSupport::get_type_name();
    retcode = MiniChatTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        printf("register_type error %d\n", retcode);
       subscriber_shutdown(participant);
        return -1;
    }

    /* To customize the topic QoS, use
       the configuration file USER_QOS_PROFILES.xml */
    topic = participant->create_topic(
        "Example MiniChat",
        type_name, DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create_topic error\n");
   subscriber_shutdown(participant);
        return -1;
    }

    /* Create a data reader listener */
    //reader_listener = new QrtiDDSlistener();

    /* To customize the data reader QoS, use
       the configuration file USER_QOS_PROFILES.xml */
    reader = subscriber->create_datareader(
        topic, DDS_DATAREADER_QOS_DEFAULT, rtiDDSlistener,
        DDS_STATUS_MASK_ALL);
    if (reader == NULL) {
        printf("create_datareader error\n");
        subscriber_shutdown(participant);
        delete rtiDDSlistener;
        return -1;
    }

    return status;
}




int QrtiDDS :: subscriber_shutdown(
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

    /* RTI Connext provides the finalize_instance() method on
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
