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
	connect(ui->btn_login, SIGNAL(clicked()), SLOT(authorize()));
	
	// Прошли авторизацию - диалог может быть удален:
	connect(this, SIGNAL(logedIn()), this, SLOT(deleteLater()));

}


/*!
Деструктор
*/
LoginDialog::~LoginDialog()
{
	delete ui;
}


/*!
Проводит авторизоцию: ищет введеную пользователем
пару Логин-Пароль в базе, испускает сигнал logedIn(), 
если пара найдена.
*/
void LoginDialog::authorize()
{
	QString login, password;
	login = ui->line_Login->text();
	password = ui->line_Pass->text();
	if (User::userIsValid(login, password))
	{
		emit logedIn();	// сигнал об успешной авторизации
		this->hide();
		}
	else
		{ 
		ui->lblResult->setText(State::coded("Пароль неверный"));
		}
}

/*!
Показывает диалог аутентификации
*/
void LoginDialog::showLD()
{
	this->show();
}
