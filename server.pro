QT += core gui webkit network
TEMPLATE = app
QT = core
QT -= gui
QT += network
TARGET = cpp
CONFIG += console
CONFIG -= app_bundle
TARGET = main

SOURCES += \
        main.cpp
