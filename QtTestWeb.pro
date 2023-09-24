QT += core network
QT -= gui

TARGET = QtTestWeb

CONFIG += c++11 console
CONFIG -= app_bundle

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += src/main.cpp \
    src/helloworldcontroller.cpp \
    src/requestermapper.cpp \
    src/listdatacontroller.cpp \
    src/logincontroller.cpp \
    src/global.cpp \
    src/cookietestcontroller.cpp \
    src/unicodecontroller.cpp \
    src/datatemplatecontroller.cpp

include(../QtWebApp/QtWebApp/httpserver/httpserver.pri)
include(../QtWebApp/QtWebApp/templateengine/templateengine.pri)
include(../QtWebApp/QtWebApp/logging/logging.pri)

OTHER_FILES += etc/webapp1.ini

HEADERS += \
    src/helloworldcontroller.h \
    src/requestermapper.h \
    src/listdatacontroller.h \
    src/logincontroller.h \
    src/global.h \
    src/cookietestcontroller.h \
    src/unicodecontroller.h \
    src/datatemplatecontroller.h
