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
	Database::connectToDatabase();
	
	//QMainWindow* w = new QMainWindow();
	//QTextEdit *txt = new QTextEdit();
	QList <Site> myList = Site::sitesByStatus(0);
	qDebug() << myList.isEmpty();
	for (int i = 0; i < myList.count(); i++)
	{
		Site s = myList.at(i);
		qDebug() << s.site_id() + s.url();
	}
	//txt->setText(user->login());
	//txt->show();
	
	SiteView Table;
	Table.show();
	return app.exec();
};