#pragma once 
#include <QMainWindow>
#include <QWidget>
#include <QString>
#include "LoginDialog.h"
/*
\file
*/

/*!
\brief Описывает конфигурацию основного окна приложения
\author Ильина А.
\date март 2016г.
*/
class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	explicit MainWindow(QMainWindow *parent = 0);
	~MainWindow();
private:
	void configure();
private slots:
	void showMW();
	void showMessage(const QString &message);
};


