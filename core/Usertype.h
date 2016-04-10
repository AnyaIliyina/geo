﻿#pragma once
#pragma once

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUrl>
#include <QDateTime>

/*!
*  \brief Представляет сущность Тип пользователя
			(таблица usertypes)
*  \author Козырева О.
*  \date		15 марта 2016
*/

class Usertype {
private:
	int m_type_id;
	QString m_type_name;

public:
	QString type_name();
	
	/*!
	Конструирует объект класса Usertype из параметров
	\param QString type_name - название создаваемого типа
	*/
	Usertype(QString type_name);
	
	/*!
	Конструирует объект класса Usertype из данных в базе
	\param int id - id статуса в базе
	*/
	Usertype(int id);
	
	~Usertype();
	
	/*!
	Возвращает id типа пользователя
	\return int type_id - id типа пользователя
	*/
	int type_id();
	
	/*!
	Записывает информацию о типе пользователя в базу данных.
	\return true - если запись в БД успешно добавлена
	*/
	bool insertIntoDatabase();
	
	/*!
	Создает таблицу "usertypes" в базе данных.
	\return true - если таблица успешно создана
	*/
	static bool createTable();
	
	/*!
	Заполняет таблицу "usertypes" в БД начальными значениями.
	\return true - если таблица успешно заполнена
	*/
	static bool completeTable();
	
	QString static coded(QByteArray encodedStr);
};

