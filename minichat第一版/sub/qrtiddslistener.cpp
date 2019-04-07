#include "qrtiddslistener.h"



QrtiDDSlistener::QrtiDDSlistener(QObject *parent) : QObject(parent)
{

}


void QrtiDDSlistener::on_data_available(DDSDataReader *reader) {
    MiniChatDataReader *MiniChat_reader = NULL;
    MiniChatSeq data_seq;
    DDS_SampleInfoSeq info_seq;
    DDS_ReturnCode_t retcode;
    int i;

    MiniChat_reader = MiniChatDataReader::narrow(reader);
    if (MiniChat_reader == NULL) {
        printf("DataReader narrow error\n");
        return;
    }

    retcode = MiniChat_reader->take(
        data_seq, info_seq, DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);

    if (retcode == DDS_RETCODE_NO_DATA) {
        return;
    } else if (retcode != DDS_RETCODE_OK) {
        printf("take error %d\n", retcode);
        return;
    }

    for (i = 0; i < data_seq.length(); ++i) {
        if (info_seq[i].valid_data) {
            MiniChatTypeSupport::print_data(&data_seq[i]);
            MiniChat *sample=&data_seq[i];
            const char *controlCmd=sample->MiniChat;
            emit newData(controlCmd);
        }
    }

    retcode = MiniChat_reader->return_loan(data_seq, info_seq);
    if (retcode != DDS_RETCODE_OK) {
        printf("return loan error %d\n", retcode);
    }
}

