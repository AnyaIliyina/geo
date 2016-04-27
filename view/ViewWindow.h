#pragma once
#include "ui_ViewWindow.h"
#include <qapplication.h>
#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>

/*!
*  \brief  Вывод результатов поиска и работа с ними
*  \author Козырева О.
*  \date   апрель 2016
*/

class ViewWindow : public QMainWindow {
	Q_OBJECT
public:
	/*!
	Конструктор
	*/
	explicit ViewWindow(int session_id, QWidget *parent = 0);

	/*!
	Деструктор
	*/
	~ViewWindow();

	/*!
		*/
	//void setupModel(const QStringList &headers);
		
	/*!
	\param QString whereQryPart- строка запроса к базе
	*/
	void setupModel( const QStringList &headers, QString whereQryPart = "" );
private:
	/*!
	
	*/
	void createTable();
	/*!

	*/
	void Refresh();
	Ui::ViewWindow *ui;
	//SqlRelationalTableModel *model;
	int m_session_id = -1;
	QSqlQueryModel *model; 
	/*!
	Удаление выделенной записи
	*/
	void deleteRecord();
private slots:
	/*!
	Слот для вызова setupModel
	\param QString query - строка запроса
	*/
	//void slotRefresh(QString query);
	/*!
	Слот вывода сообщения об удалении записи
	*/
	void slotDeleteMessage();
signals:
	/*!
	Сигнал успешного удаления
	*/
	void signalDeleted();
};