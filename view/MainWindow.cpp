#include "MainWindow.h"
#include "SiteView.h"
#include <QTextEdit>
#include <QDebug>
#include <QStatusBar>
/*!
\file
*/

MainWindow::~MainWindow()
{
}

MainWindow::MainWindow(QMainWindow *parent)
{
	// Показать диалог с запросом пароля (до появления основного окна):
	LoginDialog *ld = new LoginDialog();
	QObject::connect(ld, SIGNAL(logedIn()), this, SLOT(showMW()));	// по сигналу logedIn() 
																//  отображать основное окно 
	ld->show();
	
	// "Собрать" окно из виджетов:				
	QTextEdit *txt = new QTextEdit();
	txt->setText("central central");
	setCentralWidget(txt);				// ? ? ? ? ? удалять ли *txt, *sv, *status, и когда ?
	QDockWidget *sv = new SiteView();
	addDockWidget(Qt::LeftDockWidgetArea, sv);
	QStatusBar *status = new QStatusBar();
	setStatusBar(status);
	status->showMessage("What's next?");
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