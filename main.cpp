#include <QApplication>
#include <qDebug>
#include "Database.h"
#include "ParserGisLub.h"
#include "MainWindow.h"

/*!
\file
\brief Enterance point
*/
int main(int argc, char* argv[])
{	
	QApplication app(argc, argv);
	Database::restore();
	//ParserGisLub *p = new ParserGisLub(1);
	//p->parse();
	MainWindow *w = new MainWindow();
	return app.exec();
};