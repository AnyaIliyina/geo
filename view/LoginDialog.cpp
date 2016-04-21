#include "LoginDialog.h"
#include <QDebug>
#include <QSqlQuery>
#include "Database.h"
#include <QTextCodec>
#include "User.h"
#include "State.h"
/*!
\file
*/

/*!
Конструктор
\param QDialog * ptr - указатель на родительский диалог
*/
LoginDialog::LoginDialog(QDialog * ptr)
{
	ui = new Ui::LoginDialog();
	ui->setupUi(this);

	// По нажатию Ok пытаемся авторизоваться:
	connect(ui->btn_login, SIGNAL(clicked()), SLOT(slotAuthenticate()));
	
	// Прошли авторизацию - диалог может быть удален:
	connect(this, SIGNAL(signalLogedIn(int)), this, SLOT(slotClose(int)));

}


/*!
Деструктор
*/
LoginDialog::~LoginDialog()
{
	delete ui;
}


/*!
Проводит авторизацию: ищет введеную пользователем
пару Логин-Пароль в базе, испускает сигнал logedIn(), 
если пара найдена.
*/
void LoginDialog::slotAuthenticate()
{
	QString login, password;
	login = ui->line_Login->text();
	password = ui->line_Pass->text();
	
	if (User::userIsValid(login, password))
	{	
		int user_id = User::user_id(login);
		emit signalLogedIn(user_id);	// сигнал об успешной авторизации
		//this->hide();
		}
	else
		{ 
		ui->lblResult->setText(State::coded("Пароль неверный"));
		}
}

void LoginDialog::slotClose(int)
{
	this->close();
}

/*!
Показывает диалог аутентификации
*/
void LoginDialog::slotShowLD()
{
	this->show();
}

QString LoginDialog::getLogin() 
{
	//qDebug() << "Vot:" << m_login;
	return m_login;
}




