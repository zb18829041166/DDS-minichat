#-------------------------------------------------
#
# Project created by QtCreator 2017-11-22T11:07:23
#
#-------------------------------------------------

QT       += core gui

TARGET = pub
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    minichatSupport.cxx \
    minichatPlugin.cxx \
    minichat.cxx \
    testthread.cpp

HEADERS  += mainwindow.h \
    minichatSupport.h \
    minichatPlugin.h \
    minichat.h \
    testthread.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    pub.pro.user \
    minichat.idl



LIBS += ${NDDSHOME}/lib/x64Linux2.6gcc4.1.1/libnddscd.so\
        ${NDDSHOME}/lib/x64Linux2.6gcc4.1.1/libnddscored.so\
        ${NDDSHOME}/lib/x64Linux2.6gcc4.1.1/libnddscppd.so -ldl -lnsl -lm -lpthread -lrt

DEFINES += RTI_UNIX \
    RTI_LINUX \
    RTI_64BIT

INCLUDEPATH += ${NDDSHOME}/include \
               ${NDDSHOME}/include/ndds

RESOURCES += \
    send/SEND.qrc
