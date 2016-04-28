#pragma once
#include "ui_ViewWindow.h"
#include <qapplication.h>
#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include "TableModel.h"

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
	\param QString whereQryPart- строка запроса к базе
	*/
	 void setupModel();

private:
	 TableModel* model;
	/*!
	
	*/
	 void createTable();
	
	Ui::ViewWindow *ui;
	
	int m_session_id = -1;
	/*!
	Удаление выделенной записи
	*/
	void deleteRecord();
private slots:
	/*!
	Слот вывода сообщения об удалении записи
	*/
	void slotDeleteMessage();

	/*!

	*/
	 void slotRefresh();
signals:
	/*!
	Сигнал успешного удаления
	*/
	void signalDeleted();
};