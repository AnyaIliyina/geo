#include "LoginDialog.h"
#include <QDebug>
#include <QSqlQuery>
#include "Database.h"
#include <QTextCodec>
#include "User.h"
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
	if(User::usersValig(login, password))
		{
		emit logedIn();	// сигнал об успешной авторизации
		this->hide();
		}
		else
		{ 
		ui->lblResult->setText(coded("Пароль неверный"));
		}
}

/*!
Показывает окно авторизации
*/
void LoginDialog::showLD()
{
	this->show();
}


QString LoginDialog::coded(QByteArray encodedStr)
{
	// из QByteArray с кодировкой Windows-1251 
	QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
	// QTextCodec *codec2 = QTextCodec::codecForName("UTF-8"); 
	QString const string = codec->toUnicode(encodedStr);
	return string;
}