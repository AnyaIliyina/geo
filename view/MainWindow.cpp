#include "MainWindow.h"
#include "SearchForm.h"
#include "SM_Session.h"
#include "Session.h"
#include "Site.h"
#include <QTextEdit>
#include <QDebug>
#include <QStatusBar>
#include "User.h"
#include "NewSource.h"
#include "ViewWindow.h"
#include "State.h"
#include "Database.h"

/*!
\file
*/

MainWindow::MainWindow(QMainWindow *parent)
{
	ui = new Ui::MainWindow();
	ui->setupUi(this);
	
	// Показать диалог с запросом пароля до появления основного окна:
	LoginDialog *ld = new LoginDialog(); 
	NewSource *ns = new NewSource();
	QObject::connect(ld, SIGNAL(signalLogedIn(int)),	this, SLOT(slotStartSession(int)));	 // авторизация пройдена - отобразить основное окно, 
																				// начать работу модуля поиска
	ld->show();

	//Показать окно авторизации, при нажатии смены пользователя
	QObject::connect(ui->actionUser, SIGNAL(triggered()), ld, SLOT(slotShowLD()));
	QObject::connect(ui->actionUser, SIGNAL(triggered()), this, SLOT(slotCloseMW()));
	
	QObject::connect(ui->actionNewSource, SIGNAL(triggered()), ns, SLOT(slotShowNS()));
}


MainWindow::~MainWindow()
{
}


/*!
"Собирает" основное окно из виджетов
*/
void MainWindow::slotConfigure()
{
	
	ViewWindow *vw = new ViewWindow();
	QDockWidget *viewDockWidget = new QDockWidget("Список записей");
	viewDockWidget->setWidget(vw);
	viewDockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
	setCentralWidget(viewDockWidget);
	sf=new SearchForm();
	addDockWidget(Qt::LeftDockWidgetArea, sf);
	QStatusBar *status = new QStatusBar();
	setStatusBar(status);
	showMW();
}


void MainWindow::slotStartSession(int user_id)
{
	Session::createSession(user_id);
	qDebug() << "SEEEEEEEEEE" << Database::currentSessionId();
	slotConfigure();
}


/*!
Выводит основное окно и начинает работу модуля поиска
*/
void MainWindow::showMW()
{
	this->show();
	
	// Начать работу модуля поиска
	if (Site::uncheckedSitesFound()) 
	{
		SM_Session *session = new SM_Session();
		qDebug() << QObject::connect(session, SIGNAL(signalStatusOffered(const QString &)),
			SLOT(slotShowStatus(const QString &)));	// по сигналу от session менять текст в StatusBar
		session->start();
	}
	else statusBar()->showMessage("Модуль поиска: не найдено сайтов для проверки");
}

/*!
Закрывает основное окно
*/
void MainWindow::slotCloseMW()
{
	this->close();
	
}

/*!
Выводит сообщение на панель StatusBar
\param const QString &str - текст сообщения
*/
void MainWindow::slotShowStatus(const QString &str)
{
	statusBar()->showMessage(str);
}
