TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lendingitem.cpp \
    book.cpp \
    journal.cpp \
    compactdisc.cpp \
    libraryapp.cpp \
    libraryhandler.cpp

HEADERS += \
    lendingitem.h \
    book.h \
    journal.h \
    compactdisc.h \
    libraryapp.h \
    libraryhandler.h
