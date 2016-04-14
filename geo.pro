TEMPLATE = app
CONFIG += qt console
QT += core widgets network
QT += sql gui
INCLUDEPATH += core database view search_module 

SOURCES += main.cpp database/Database.cpp \
	search_module/SM_Session.cpp search_module/Parser.cpp search_module/ParserGisLub.cpp\
	core/State.cpp core/Scale.cpp core/User.cpp core/Status.cpp core/Session.cpp \
	core/Site.cpp core/Format.cpp core/Geodata_record.cpp core/Usertype.cpp \
	view/MainWindow.cpp view/LoginDialog.cpp view/SiteView.cpp view/SitesView.cpp view/NewDockWidget.cpp

HEADERS += database/Database.h \
	search_module/SM_Session.h search_module/Parser.h search_module/ParserGisLub.h\
	core/Site.h core/Format.h core/State.h core/Scale.h core/User.h core/Status.h \
	core/Usertype.h core/Session.h core/Geodata_record.h \
	view/SiteView.h view/MainWindow.h view/LoginDialog.h view/SitesView.h view/NewDockWidget.h

FORMS += view/SiteView.ui view/LoginDialog.ui view/MainWindow.ui view/SitesView.ui view/NewDockWidget.ui