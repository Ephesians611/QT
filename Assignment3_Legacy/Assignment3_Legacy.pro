QT += core gui opengl

LIBS += -lOpengl32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    assg3.cpp \
    graphics.cpp \
    mainwindow.cpp

HEADERS += \
    graphics.h \
    mainwindow.h
