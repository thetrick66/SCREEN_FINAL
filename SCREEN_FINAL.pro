#-------------------------------------------------
#
# Project created by QtCreator 2014-12-08T21:18:08
#
#-------------------------------------------------

QT       += core gui
#QT       += multimediakit
#QT       += widgets
#QT       += mobility

QT       += multimedia
QT       += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Screen_final
TEMPLATE = app


SOURCES += main.cpp \
    screen.cpp \
    sec.cpp \
    modp.cpp \
    modb.cpp \
    recb.cpp \
    cmp.cpp \
    form.cpp \
    binary.cpp \
    video.cpp \
    dada.cpp


HEADERS  += \
    screen.h \
    sec.h \
    modp.h \
    modb.h \
    recb.h \
    cmp.h \
    form.h \
    binary.h \
    video.h \
    dada.h
FORMS    += \
    screen.ui \
    form.ui \
    binary.ui \
    video.ui \
    dada.ui
INCLUDEPATH += C:\\OpenCV2.4.10\\install\\include
LIBS += -LC:\\OpenCV2.4.10\\install\\x64\\mingw\\lib \
-lopencv_core2410.dll \
-lopencv_highgui2410.dll \
-lopencv_imgproc2410.dll \
-lopencv_features2d2410.dll \
-lopencv_calib3d2410.dll
