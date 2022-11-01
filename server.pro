QT += core gui webkit network
TEMPLATE = app
QT = core
QT -= gui
QT += network
TARGET = cpp
CONFIG += console
CONFIG -= app_bundle
TARGET = main

LIBS += -lrt

SOURCES += \
        Controller/datamanager.cpp \
        Controller/servicecontroller.cpp \
        main.cpp \
        multiprocess/msgqueue.cpp \
        multiprocess/sharemem.cpp

HEADERS += \
    Controller/datamanager.h \
    Controller/servicecontroller.h \
    multiprocess/connection.h \
    multiprocess/message.h \
    multiprocess/msgqueue.h \
    multiprocess/sharemem.h \
    utils/sharememdef.h

DISTFILES += \
    data/data.json \
    data/employee.json
