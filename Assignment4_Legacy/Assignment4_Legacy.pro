QT += core gui opengl

LIBS += -lOpengl32 -lGLU32

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

SOURCES += \
    assg4.cpp \
    graphics.cpp \
    graphics2.cpp \
    graphics3.cpp \
    graphics4.cpp \
    mainwindow.cpp

HEADERS += \
    graphics.h \
    graphics2.h \
    graphics3.h \
    graphics4.h \
    mainwindow.h
