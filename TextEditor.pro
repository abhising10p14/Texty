#-------------------------------------------------
#
# Project created by QtCreator 2017-04-13T14:06:38
#
#-------------------------------------------------

QT       += core gui printsupport concurrent widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TextEditor
TEMPLATE = app


SOURCES += main.cpp\
    dialog.cpp \
    font.cpp \
    mainwindow.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    font.h

FORMS    += mainwindow.ui \
    dialog.ui \
    font.ui
