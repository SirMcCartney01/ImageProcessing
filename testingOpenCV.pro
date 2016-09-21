QT += core
QT -= gui

CONFIG += c++11

TARGET = testingOpenCV
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += src/main.cpp

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}

INCLUDEPATH += /usr/local/include/opencv
INCLUDEPATH += /usr/local/include/opencv2

LIBS += -L/usr/local/lib
-lopencv_shape
-lopencv_stitching
-lopencv_objdetect
-lopencv_superres
-lopencv_videostab
-lopencv_calib3d
-lopencv_features2d
-lopencv_highgui
-lopencv_videoio
-lopencv_imgcodecs
-lopencv_video
-lopencv_photo
-lopencv_ml
-lopencv_imgproc
-lopencv_flann
-lopencv_viz
-lippicv
-lopencv_core
