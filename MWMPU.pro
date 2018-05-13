#-------------------------------------------------
#
# Project created by QtCreator 2018-05-05T14:34:40
#
#-------------------------------------------------

QT       += core gui opengl printsupport serialport
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MWMPU
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

OBJECTS_DIR += gen/obj
MOC_DIR += gen/moc
UI_DIR += gen/ui_c

INCLUDEPATH += $$PWD/h

FORMS += \
    ui/mainwindow.ui

HEADERS += \
    h/mainwindow.h \
    h/measurementhandler.h \
    h/openglwidget.h \
    h/qcustomplot.h \
    h/serialportreader.h \
    h/wireframemodel.h

SOURCES += \
    cpp/main.cpp \
    cpp/mainwindow.cpp \
    cpp/measurementhandler.cpp \
    cpp/openglwidget.cpp \
    cpp/qcustomplot.cpp \
    cpp/serialportreader.cpp \
    cpp/wireframemodel.cpp

RESOURCES += \
    MWMPU.qrc
