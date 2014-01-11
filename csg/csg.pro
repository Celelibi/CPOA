
TARGET = csg
TEMPLATE = lib
CONFIG += staticlib

QMAKE_CXXFLAGS += -Wall
QMAKE_CXXFLAGS += -DNO_TEMPLATE_IMPLEMENTATION

INCLUDEPATH += ../vectorMatrix ../image

SOURCES += *.cpp

HEADERS += *.h

DESTDIR = ../lib
