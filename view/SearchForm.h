#pragma once
#include "ui_SearchForm.h"
#include <qapplication.h>
#include <QMainWindow>
#include <QSqlTableModel>


namespace Ui {
	class SearchForm;
}

/*!
*  \brief  Форма для поиска
*  \author Козырева О.
*  \date   апрель 2016
*/
class  SearchForm:public QDockWidget {
	Q_OBJECT
public:
	explicit SearchForm(QDockWidget *parent = 0);
	~SearchForm();

	/*!
	Метод для создания строки запроса
	\param QList<QString> args - список, содержащий строки, для составления запроса
	\return QString qry - строка запроса к базе
	*/
	QString ParseWhereArgs(QList<QString>& args);
signals:
	/*!
	Сигнал, содержащий строку запроса
	\param QString - полная строка запроса на создание записи
	*/
	 void signalQueryCreated(QString);
	
private:
	Ui::SearchForm *ui;
	
public slots:
	/*!
	Слот для создания строки запроса
	*/
	void slotCreateQuery();
	/*!
	Слот нажатия кнопки поиска
	*/
	void slotClickSearch();

};