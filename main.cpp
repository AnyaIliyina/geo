#include <QApplication>
#include <QMainWindow>
#include <qDebug>
#include "Database.h"


/*!
\file
\brief Enterance point
*/
int main(int argc, char* argv[])
{	
	QApplication app(argc, argv);
	// Database::configure();
	Site *s = new Site(1);
	qDebug() << s->url();
	QMainWindow* w = new QMainWindow();
	w->show();
	
	return app.exec();
};