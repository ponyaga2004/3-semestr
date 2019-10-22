TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += date.hpp \
    time.hpp \
    record.hpp \
    commands.hpp
SOURCES += main.cpp date.cpp \
    time.cpp \
    record.cpp \
    commands.cpp
