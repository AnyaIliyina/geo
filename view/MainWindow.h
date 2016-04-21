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
	/*! 
	Конструктор 
	\param QMainWindow *parent - родительский виджет
	*/
	explicit MainWindow(QMainWindow *parent = 0);
	
	/*! Деструктор*/
	~MainWindow();

private:
	/*!
	Выводит основное окно и начинает работу модуля поиска
	*/
	void showMW();
	
	Ui::MainWindow *ui;
//	QString m_log;
	int m_session_id = -1;
	
private slots:
	/*!
	Выводит сообщение на панель StatusBar
	\param const QString &str - текст сообщения
	*/
	void slotShowStatus(const QString &status);
	
	/*!
	Закрывает основное окно
	*/
	void slotCloseMW();
	
	/*!
	"Собирает" основное окно из виджетов
	\param int type - тип пользователя
	*/
	void slotConfigure();

	/*!
	Начинает сессию для пользователя user_id
	\param  user_id - идентификатор пользователя */
	void slotStartSession(int user_id);
};


