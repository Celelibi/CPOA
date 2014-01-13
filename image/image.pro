
TARGET = image
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += ../vectorMatrix

SOURCES += #*.cpp

HEADERS += *.h #*.hpp

DESTDIR = ../lib

QMAKE_CXXFLAGS += -DNO_TEMPLATE_IMPLEMENTATION
