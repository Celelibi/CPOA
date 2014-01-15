#-------------------------------------------------
#
# Project created by QtCreator 2013-07-24T14:27:30
#
#-------------------------------------------------

QT       += core gui opengl widgets

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += debug
TARGET = InterfaceCSG
TEMPLATE = app

QMAKE_CXXFLAGS += -Wall
QMAKE_CXXFLAGS_DEBUG -= -g
QMAKE_CXXFLAGS_DEBUG += -ggdb

INCLUDEPATH += ../vectorMatrix ../image ../csg ../particle

LIBS +=  -L ../lib \
	-lcsg   \
	-limage \
	-lvectorMatrix \
#	-lparticle \
	-lboost_thread

#PRE_TARGETDEPS = ../lib/*

DESTDIR = ../bin

SOURCES += main.cpp\
		   mainwindow.cpp \
		   renderImg.cpp

HEADERS  += mainwindow.h \
			renderImg.h

FORMS    += mainwindow.ui
QMAKE_CXXFLAGS += -DNO_TEMPLATE_IMPLEMENTATION
