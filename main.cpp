#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <qDebug>
#include "Database.h"
#include "State.h"
#include "User.h"
#include <QList>
#include "SiteView.h"

/*!
\file
\brief Enterance point
*/
int main(int argc, char* argv[])
{	
	QApplication app(argc, argv);
	Database::configure();
	//qDebug() << s->url();
	//QMainWindow* w = new QMainWindow();
	//QTextEdit *txt = new QTextEdit();
	//QList <Site> myList = Site::sitesByStatus(0);
	//qDebug() << myList.isEmpty();
	//txt->setText(user->login());
	//txt->show();
	
	SiteView Table;
	Table.show();
	return app.exec();
};