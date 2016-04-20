#pragma once
#include "ui_ViewForm.h"
#include <qapplication.h>
#include <QMainWindow>
#include <QSqlTableModel>

/*!
*  \brief  Вывод результатов поиска и работа с ними
*  \author Козырева О.
*  \date   апрель 2016
*/

class ViewForm : public QWidget {
	Q_OBJECT
public:
	/*!
	Конструктор
	*/
	//explicit ViewForm(QWidget *parent = 0);

	/*!
	Конструктор
	*/
	explicit ViewForm(int session_id, QWidget *parent = 0);

	/*!
	Деструктор
	*/
	~ViewForm();

	/*!
	
	\param QString whereQryPart- строка запроса к базе
	*/
	void setupModel(QString& whereQryPart);
private:
	/*!
	
	*/
	void createTable();

	Ui::ViewForm *ui;

	QSqlQueryModel *model;

	int m_session_id = -1;

	/*!
	Удаление выделенной записи
	*/
	void deleteRecord();
private slots:
	/*!
	Слот для вызова setupModel
	\param QString query - строка запроса
	*/
	void refresh(QString query);
	/*!
	Слот вывода сообщения об удалении записи
	*/
	void deleteMessage();
signals:
	/*!
	Сигнал успешного удаления
	*/
	void del();
};