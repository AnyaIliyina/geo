#pragma once
#include <QDockWidget>
#include "ui_NewDockWidget.h"
/*!
\brief 
\author Козырева О.
\date апрель 2016г.
*/

class NewDockWidget : public QDockWidget {
	Q_OBJECT
private:
	Ui::NewDockWidget *ui;
	QString m_place_name;
	QString m_url;
	QString m_site_name;
	QString m_format_name;
	int m_format_id;
	int m_site_id;
	int m_session_id = -1;
public:
	/*!
	Конструктор
	\param QDockWidget *ptr - указатель на родительский виджет
	*/
	explicit NewDockWidget(QDockWidget *ptr = 0);

	/*!
	Конструктор
	\param QDockWidget *ptr - указатель на родительский виджет
	*/
	explicit NewDockWidget(int session_id, QDockWidget *ptr = 0);
	
	
	/*!
	Деструктор
	*/
	~NewDockWidget();
private:
	/*!
	Получение данных из формы
	*/
	void textRead();
	/*!
	Получает id сайта
	*/
	void getSiteId();
	/*!
	Получает id формата
	*/
	void getFormatId();
	/*!
	Создает новую запись в таблицу geodata_records
	*/
	void addNewRecord();
	/*!
	Проверка на заполнение ячеек
	*/
	bool emptyLine();
	/*!
	Выводит сообщение о создании новой записи
	*/
	void addMessage();
private slots:
	

	void check();
public slots:
	/*!
	Показывает виджет
	*/
	void showNDW();
	
};