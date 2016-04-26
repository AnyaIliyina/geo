#pragma once
#include "ui_ViewWindow.h"
#include <qapplication.h>
#include <QMainWindow>
#include <QSqlTableModel>

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
	//explicit ViewWindow(QWidget *parent = 0);

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
	void setupModel(QString& whereQryPart, const QStringList &headers );
private:
	/*!
	
	*/
	void createTable();

	Ui::ViewWindow *ui;

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
	void slotRefresh(QString query);
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