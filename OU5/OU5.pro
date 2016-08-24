TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    shapeptr.cpp \
    ../OU3/polygon.cpp \
    ../OU3/shape.cpp \
    ../OU3/vertex.cpp \
    ../OU3/circle.cpp \
    ../OU3/point.cpp \
    ../OU3/rectangle.cpp

HEADERS += \
    shapeptr.h \
    ../OU3/polygon.h \
    ../OU3/shape.h \
    ../OU3/vertex.h \
    ../OU3/circle.h \
    ../OU3/point.h \
    ../OU3/rectangle.h \
    shapefunctors.h
