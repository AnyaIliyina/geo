﻿#include "LoginDialog.h"
#include <QDebug>
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
	connect(ui->btn_login, SIGNAL(clicked()), SLOT(authorize()));
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
	// TODO: соединиться с базой, проверить правильность пароля,
	//		сообщить о неверном пароле пользователю
	
	emit logedIn();	// сигнал об успешной авторизации
	this->hide();
}