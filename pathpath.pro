TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR += bin
OBJECTS_DIR = ignore
MOC_DIR = ignore
UI_DIR = ignore
RCC_DIR = ignore

# link static
QMAKE_CFLAGS_RELEASE += /MT
QMAKE_CXXFLAGS_RELEASE += /MT
QMAKE_CFLAGS_DEBUG += /MTd
QMAKE_CXXFLAGS_DEBUG += /MTd
QMAKE_CFLAGS_RELEASE -= -MD
QMAKE_CXXFLAGS_RELEASE -= -MD
QMAKE_CFLAGS_DEBUG -= -MDd
QMAKE_CXXFLAGS_DEBUG -= -MDd

SOURCES += src/main.cpp \
    src/log.cpp \
    src/io.cpp \
    src/win.cpp

INCLUDEPATH += . src

DEFINES += _SCL_SECURE_NO_WARNINGS

HEADERS += \
    src/log.h \
    src/io.h \
    src/win.h
