#-------------------------------------------------
#
# Project created by QtCreator 2017-11-22T11:07:42
#
#-------------------------------------------------

QT       += core gui

TARGET = sub
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    minichatSupport.cxx \
    minichatPlugin.cxx \
    minichat.cxx \
    qrtiddslistener.cpp \
    qrtidds.cpp

HEADERS  += mainwindow.h \
    minichatSupport.h \
    minichatPlugin.h \
    minichat.h \
    qrtiddslistener.h \
    qrtidds.h

FORMS    += mainwindow.ui

LIBS += ${NDDSHOME}/lib/x64Linux2.6gcc4.1.1/libnddscd.so\
        ${NDDSHOME}/lib/x64Linux2.6gcc4.1.1/libnddscored.so\
        ${NDDSHOME}/lib/x64Linux2.6gcc4.1.1/libnddscppd.so -ldl -lnsl -lm -lpthread -lrt

DEFINES += RTI_UNIX \
    RTI_LINUX \
    RTI_64BIT




INCLUDEPATH += ${NDDSHOME}/include \
               ${NDDSHOME}/include/ndds

OTHER_FILES += \
    minichat.idl

RESOURCES += \
    recieve/image.qrc
