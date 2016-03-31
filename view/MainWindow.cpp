#include "MainWindow.h"
#include "SiteView.h"
#include "SM_Session.h"
#include <QTextEdit>
#include <QDebug>
#include <QStatusBar>
/*!
\file
*/

MainWindow::MainWindow(QMainWindow *parent)
{
	// Показать диалог с запросом пароля до появления основного окна:
	LoginDialog *ld = new LoginDialog();   		
	QObject::connect(ld, SIGNAL(logedIn()),
		this, SLOT(showMW()));	 // авторизация пройдена - отобразить основное окно 
	ld->show();
	
	// "Собрать" окно из виджетов:				
	configure();

	// Начать работу модуля поиска
	SM_Session *session = new SM_Session();
	QObject::connect(session, SIGNAL(newStatusbarText(const QString &)),
		SLOT(showMessage(const QString &)));	// по сигналу от session менять текст в StatusBar
	session->start();
}


MainWindow::~MainWindow()
{
}



/*!
"Собирает" основное окно из виджетов
*/
void MainWindow::configure()
{
	QTextEdit *txt = new QTextEdit();
	txt->setText("central central");
	setCentralWidget(txt);				
	QDockWidget *sv = new SiteView();
	addDockWidget(Qt::LeftDockWidgetArea, sv);
	QStatusBar *status = new QStatusBar();
	setStatusBar(status);
}


/*!
Выводит основное окно
*/
void MainWindow::showMW()
{
	this->show();
}


/*!
Выводит сообщение на панель StatusBar
\param const QString &str - текст сообщения
*/
void MainWindow::showMessage(const QString &str)
{
	statusBar()->showMessage(str);
}
