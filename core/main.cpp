#include <QApplication>
#include <qDebug>
#include "Database.h"
#include "ParserGisLub.h"
#include "ParserGeofabrik.h"
#include "Site.h"
#include "MainWindow.h"

/*!
\file
\brief Enterance point
*/
int main(int argc, char* argv[])
{	
	QApplication app(argc, argv);
	Database::restore();
	/*ParserGeofabrik *p = new ParserGeofabrik();
	p->parse(1, 3);
	ParserGisLub *pgl = new ParserGisLub();
	pgl->parse(1, 1);
	qDebug() << Site::uncheckedSitesFound();*/
	
	MainWindow *w = new MainWindow();
	return app.exec();
};