TEMPLATE = app
CONFIG += qt console
QT += core widgets
QT += sql
INCLUDEPATH += core database 
SOURCES += main.cpp core/Site.cpp core/Format.cpp database/Database.cpp core/State.cpp core/Scale.cpp core/User.cpp core/Status.cpp core/Usertype.cpp core/Session.cpp core/Geodata_record.cpp
HEADERS += core/Site.h database/Database.h core/Format.h core/State.h core/Scale.h core/User.h core/Status.h core/Usertype.h core/Session.h core/Geodata_record.h
