#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <qDebug>
#include "Database.h"
#include "State.h"
#include "User.h"


/*!
\file
\brief Enterance point
*/
int main(int argc, char* argv[])
{	
	QApplication app(argc, argv);
	Database::configure();
	//Site *s = new Site(1);
	//qDebug() << s->url();
	//QMainWindow* w = new QMainWindow();
	QTextEdit *txt = new QTextEdit();
	User *user = new User(1);
	qDebug() << user->login();
	txt->setText(user->login());
	txt->show();
	
	return app.exec();
};