TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    shape.cpp \
    point.cpp \
    circle.cpp \
    rectangle.cpp \
    polygon.cpp \
    shapelist.cpp \
    vertex.cpp \
    node.cpp \
    ../OU2/utility.cpp

HEADERS += \
    shape.h \
    point.h \
    circle.h \
    rectangle.h \
    polygon.h \
    shapelist.h \
    vertex.h \
    node.h \
    ../OU2/utility.h
