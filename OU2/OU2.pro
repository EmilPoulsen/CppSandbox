TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sortedvector.cpp \
    utility.cpp \
    ../OU1/Polygon.cpp \
    ../OU1/Vertex.cpp

HEADERS += \
    sortedvector.h \
    utility.h \
    ../OU1/Polygon.h \
    ../OU1/Vertex.h
