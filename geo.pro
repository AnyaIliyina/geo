TEMPLATE = app
CONFIG += qt console
QT += core widgets
QT += sql
INCLUDEPATH += core database
SOURCES += main.cpp core/Site.cpp database/Database.cpp
HEADERS += core/Site.h database/Database.h