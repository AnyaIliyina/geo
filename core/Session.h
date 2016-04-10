﻿#pragma once
#pragma once

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUrl>
#include <QDateTime>

/*!
\file
*/

/*!
*  \brief Представляет сущность Сессия
			(таблица sessions)
*  \author Козырева О.
*  \date	15 марта 2016
*/

class Session {
private:
	int m_session_id;
	int m_user_id;
	QDateTime m_date;

public:
	
	Session(int user_id, QDateTime date);
	
	/*!
	Конструирует объект, используя информацию в базе
	\param int id- id сессии
	*/
	Session(int id);
	
	~Session();
	
	/*!
	Возвращает id сессии
	\return int session_id - id сессии
	*/
	int session_id();
	
	/*!
	Записывает информацию о сессии в базу данных.
	\return true - если запись в БД успешно добавлена
	*/
	bool insertIntoDatabase();
	
	/*!
	Создает таблицу "sessions" в базе данных.
	\return true - если таблица успешно создана
	*/
	static bool createTable();
	
	/*!
	Заполняет таблицу "sessions" начальными значениями
	\return true - если записи успешно созданы
	*/
	static bool completeTable();

};


