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
	connect(this, SIGNAL(logedIn(int)), this, SLOT(closed(int)));

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
void LoginDialog::authorize()
{
	QString login, password;
	login = ui->line_Login->text();
	password = ui->line_Pass->text();
	
	if (User::userIsValid(login, password))
	{	
		int type = User::type_id(login);
		emit logedIn(type);	// сигнал об успешной авторизации
		//this->hide();
		}
	else
		{ 
		ui->lblResult->setText(State::coded("Пароль неверный"));
		}
}

void LoginDialog::closed(int)
{
	this->close();
}

/*!
Показывает диалог аутентификации
*/
void LoginDialog::showLD()
{
	this->show();
}

QString LoginDialog::getLogin() 
{
	//qDebug() << "Vot:" << m_login;
	return m_login;
}




