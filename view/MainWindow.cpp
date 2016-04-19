#include "MainWindow.h"
#include "SitesView.h"
#include "SitesViewUser.h"
#include "SM_Session.h"
#include <QTextEdit>
#include <QDebug>
#include <QStatusBar>
#include "User.h"


/*!
\file
*/

MainWindow::MainWindow(QMainWindow *parent)
{
	ui = new Ui::MainWindow();
	ui->setupUi(this);

	// Показать диалог с запросом пароля до появления основного окна:
	LoginDialog *ld = new LoginDialog(); 

	QObject::connect(ld, SIGNAL(logedIn(int)),	this, SLOT(configure(int)));	 // авторизация пройдена - отобразить основное окно, 
																				// начать работу модуля поиска
	ld->show();

	//Показать окно авторизации, при нажатии смены пользователя
	QObject::connect(ui->actionUser, SIGNAL(triggered()), ld, SLOT(showLD()));
	QObject::connect(ui->actionUser, SIGNAL(triggered()), this, SLOT(closeMW()));
}


MainWindow::~MainWindow()
{
}


/*!
"Собирает" основное окно из виджетов
\param int type - тип пользователя
*/
void MainWindow::configure(int type)
{
	QTextEdit *txt = new QTextEdit();
	txt->setText("central central");
	setCentralWidget(txt);
	delete sv;
	sv = new SitesView();
	addDockWidget(Qt::LeftDockWidgetArea, sv);
	delete svu;
	svu = new SitesViewUser();
	addDockWidget(Qt::LeftDockWidgetArea, svu);
	if (type!= 3)
	{
		svu->hide();
	}
	else
	{
		sv->hide();
	}
	QStatusBar *status = new QStatusBar();
	setStatusBar(status);
	showMW();
}


/*!
Выводит основное окно и начинает работу модуля поиска
*/
void MainWindow::showMW()
{
	this->showMaximized();
	
	// Начать работу модуля поиска
	SM_Session *session = new SM_Session();
	QObject::connect(session, SIGNAL(newStatusbarText(const QString &)),
		SLOT(showMessage(const QString &)));	// по сигналу от session менять текст в StatusBar
	session->start();
}

/*!
Закрывает основное окно
*/
void MainWindow::closeMW()
{
	this->close();
	
}

/*!
Выводит сообщение на панель StatusBar
\param const QString &str - текст сообщения
*/
void MainWindow::showMessage(const QString &str)
{
	statusBar()->showMessage(str);
}
