#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <qDebug>
#include "Database.h"
#include "State.h"


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
	State *state = new State(1);
	qDebug() << state->state_name();
	txt->setText(state->state_name());
	txt->show();
	
	return app.exec();
};