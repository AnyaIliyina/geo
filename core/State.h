#pragma once
#pragma once

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUrl>
#include <QDateTime>

/*!
*  \brief Представляет сущность Состояние
			(таблица states)
*  \author Козырева О.
*  \date	9 марта 2016
*/

class State {
private:
	int m_state_id;
	QString m_state_name;

public:
	QString state_name();
	
	/*!
	Конструирует объект класса State из параметров
	\param const QString state_name - название создаваемого статуса
	*/
	State(QString state_name);
	
	/*!
	Конструирует объект класса State из данных в базе
	\param int id - id статуса в базе
	*/
	State(int id);
	
	~State();
	
	/*!
	Возвращает id статуса
	\return int state_id - id статуса
	*/
	int state_id();
	
	/*!
	Записывает информацию о статусе в базу данных.
	\return true - если запись в БД успешно добавлена
	*/
	bool insertIntoDatabase();
	
	/*!
	Создает таблицу "states" в базе данных.
	\return true - если таблица успешно создана
	*/
	static bool createTable();
	
	/*!
	Заполняет таблицу "states" в БД начальными значениями.
	\return true - если таблица успешно заполнена
	*/
	static bool completeTable();
	
	QString static coded(QByteArray encodedStr);
};
