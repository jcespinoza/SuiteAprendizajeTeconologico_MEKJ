#-------------------------------------------------
#
# Project created by QtCreator 2014-03-01T13:35:12
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProyectoHackathon
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    operaciones.cpp \
    letralabel.cpp \
    oracionlabel.cpp

HEADERS  += mainwindow.h \
    operaciones.h \
    letralabel.h \
    oracionlabel.h

FORMS    += mainwindow.ui

RESOURCES += \
    Imagenes.qrc
