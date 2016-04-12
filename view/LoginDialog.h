#pragma once 
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
	explicit LoginDialog(QDialog *ptr = 0);
	~LoginDialog();
	QString coded(QByteArray encodedStr);
signals:
	void logedIn();
private slots:
	void authorize();
public slots:
	void showLD();
};