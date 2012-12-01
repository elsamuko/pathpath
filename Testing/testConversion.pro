
QT       += core testlib

TARGET = testConversion
CONFIG   += console


# locations
DESTDIR += bin
OBJECTS_DIR = ignore
MOC_DIR = ignore
UI_DIR = ignore
RCC_DIR = ignore


# sources
INCLUDEPATH += .. . ../src/

HEADERS += ../src/win.h \
            ../src/log.h
SOURCES += ../src/win.cpp \
            ../src/log.cpp
SOURCES += testConversion.cpp

		
# defines
DEFINES += SRCDIR=\\\"$$PWD/\\\"
DEFINES += _SCL_SECURE_NO_WARNINGS


