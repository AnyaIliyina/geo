﻿	#pragma once 
#include <QDialog>
#include "ui_LoginDialog.h"
/*
\file
*/

/*!
\brief Описывает диалог аутентификации пользователя
\author Ильина А.
\date март 2016г.
*/
class LoginDialog : public QDialog {
	Q_OBJECT
private:
	Ui::LoginDialog *ui;
	
public:
	QString m_login;
	 QString getLogin();
	/*!	Конструктор
	\param QDialog * ptr - указатель на родительский диалог	*/
	explicit LoginDialog(QDialog *ptr = 0);

	/*!	Деструктор	*/
	~LoginDialog();
	
	
signals:
	/*!
	
	*/
	void signalLogedIn(int);			// сигнал об учпешной авторизации

private slots:
	/*!Проводит авторизоцию: 
	ищет введеную пользователем пару Логин-Пароль в базе, 
	испускает сигнал logedIn(), если пара найдена.*/
	void slotAuthenticate();
	/*!
	
	*/
	void slotClose(int);

public slots:
	/*!	Показывает диалог	*/
	void slotShowLD();
};