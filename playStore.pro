#-------------------------------------------------
#
# Project created by QtCreator 2018-12-23T17:17:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = playStore
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    notepad.cpp \
    shapes.cpp \
    renderarea.cpp \
    gamewindow.cpp \
    myplayer.cpp \
    bullet.cpp \
    enemy.cpp \
    gamebase.cpp \
    score.cpp \
    health.cpp

HEADERS += \
        mainwindow.h \
    notepad.h \
    shapes.h \
    renderarea.h \
    gamewindow.h \
    myplayer.h \
    bullet.h \
    enemy.h \
    gamebase.h \
    score.h \
    health.h

FORMS += \
        mainwindow.ui \
    notepad.ui \
    shapes.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
