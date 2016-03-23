﻿#pragma once 
#include <QDialog>
#include "ui_LoginDialog.h"
/*
\file
*/

/*!
\brief Класс LoginDialog
\details Диалог для аутентификации пользователя 
\author 
\date март 2016г.
*/
class LoginDialog : public QDialog {
	Q_OBJECT
private:
	Ui::LoginDialog *ui;
public:
	explicit LoginDialog(QDialog *ptr = 0);
	~LoginDialog();
signals:
	void logedIn();
private slots:
	void authorize();
};