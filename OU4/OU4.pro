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
    enums.cpp \
    guilibrary.cpp \
    fictionbook.cpp \
    nonfictionbook.cpp

HEADERS += \
    lendingitem.h \
    book.h \
    journal.h \
    compactdisc.h \
    libraryapp.h \
    enums.h \
    guilibrary.h \
    fictionbook.h \
    nonfictionbook.h
