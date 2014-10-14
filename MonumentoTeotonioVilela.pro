#-------------------------------------------------
#
# Project created by QtCreator 2014-10-07T11:17:21
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MonumentoTeotonioVilela
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Janela.cpp \
    superficies.cpp \
    coordenadaxyz.cpp

HEADERS  += mainwindow.h \
    Janela.h \
    superficies.h \
    coordenadaxyz.h

LIBS += -lGLU -lSOIL

INCLUDEPATH += /usr/lib/include/

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS  += -std=c++0x
