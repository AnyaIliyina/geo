TEMPLATE = app
CONFIG += qt console
QT += core widgets
QT += sql
INCLUDEPATH += core database 
SOURCES += main.cpp core/Site.cpp core/Format.cpp database/Database.cpp core/State.cpp
HEADERS += core/Site.h database/Database.h core/Format.h core/State.h
