#-------------------------------------------------
#
# Project created by QtCreator 2017-11-29T08:50:45
#
#-------------------------------------------------

QT       += core gui

TARGET = sub
TEMPLATE = app


SOURCES += \
    testthread.cpp \
    qrtiddslistener.cpp \
    minichatSupport.cxx \
    minichatPlugin.cxx \
    minichat.cxx \
    mainwindow.cpp \
    main.cpp

HEADERS  += \
    testthread.h \
    qrtiddslistener.h \
    minichatSupport.h \
    minichatPlugin.h \
    minichat.h \
    mainwindow.h

FORMS    += \
    mainwindow.ui

OTHER_FILES += \ sub.pro.user \
        minichat.idl


LIBS += ${NDDSHOME}/lib/x64Linux2.6gcc4.1.1/libnddscd.so\
        ${NDDSHOME}/lib/x64Linux2.6gcc4.1.1/libnddscored.so\
        ${NDDSHOME}/lib/x64Linux2.6gcc4.1.1/libnddscppd.so -ldl -lnsl -lm -lpthread -lrt

DEFINES += RTI_UNIX \
    RTI_LINUX \
    RTI_64BIT

INCLUDEPATH += ${NDDSHOME}/include \
               ${NDDSHOME}/include/ndds

