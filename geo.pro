TEMPLATE = app
CONFIG += qt console
QT += core widgets network
QT += sql gui
INCLUDEPATH += core database view search_module 

SOURCES += database/Database.cpp \
	search_module/SM_Session.cpp search_module/Parser.cpp search_module/ParserGisLub.cpp\
	search_module/ParserGeofabrik.cpp \
	core/main.cpp core/State.cpp core/Scale.cpp core/User.cpp core/Status.cpp core/Session.cpp \
	core/Site.cpp core/Format.cpp core/Geodata_record.cpp core/Usertype.cpp \
	view/MainWindow.cpp view/LoginDialog.cpp view/NewDockWidget.cpp\
	view/SearchForm.cpp view/ViewForm.cpp view/NewSource.cpp

HEADERS += database/Database.h \
	search_module/SM_Session.h search_module/Parser.h search_module/ParserGisLub.h\
	search_module/ParserGeofabrik.h \
	core/Site.h core/Format.h core/State.h core/Scale.h core/User.h core/Status.h \
	core/Usertype.h core/Session.h core/Geodata_record.h \ 
	view/MainWindow.h view/LoginDialog.h view/NewDockWidget.h\
	view/ViewForm.h view/SearchForm.h view/NewSource.h

FORMS +=  view/LoginDialog.ui view/MainWindow.ui view/NewDockWidget.ui \
	view/ViewForm.ui view/SearchForm.ui view/NewSource.ui