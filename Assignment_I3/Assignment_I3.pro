QT += core gui opengl

LIBS += -lOpengl32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SandBoxWithMainWindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphics.cpp

HEADERS  += mainwindow.h \
    graphics.h


