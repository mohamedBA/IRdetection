#-------------------------------------------------
#
# Project created by QtCreator 2015-07-18T17:31:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app
CONFIG += release

SOURCES += main.cpp\
        mainwindow.cpp \
    labelimage.cpp \
    imageselected.cpp

HEADERS  += mainwindow.h \
    labelimage.h \
    imageselected.h

FORMS    += mainwindow.ui \
    imageselected.ui
INCLUDEPATH += C:/opencv/build/install/include
LIBS += "C:/opencv/build/bin/*.dll"

RESOURCES += \
    appressources.qrc
