#pragma once 
#include <QMainWindow>
#include <QWidget>
#include <QString>
#include "LoginDialog.h"
#include "ui_MainWindow.h"
#include "SearchForm.h"
#include "ViewForm.h"
/*
\file
*/

/*!
\brief Описывает конфигурацию основного окна приложения
\author Ильина А., Козырева О.
\date март 2016г.
*/
class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	explicit MainWindow(QMainWindow *parent = 0);
	~MainWindow();
private:
	Ui::MainWindow *ui;
	void showMW();
	QString m_log;
	
private slots:
	
	void showMessage(const QString &message);
	void closeMW();
	void configure(int);
};


