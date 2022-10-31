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
        main.cpp \
        multiprocess/sharemem.cpp

HEADERS += \
    Controller/datamanager.h \
    multiprocess/sharemem.h \
    utils/sharememdef.h

DISTFILES += \
    data/data.json \
    data/employee.json
