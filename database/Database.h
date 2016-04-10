#pragma once
/*!
\file
*/

#include "Site.h"
#include <QDir>

/*! 
 *  \brief     Класс для работы с БД
 *  \author    Ильина А.
 *  \date     март 2016
*/
 
class Database {
private:
	static QSqlDatabase db;
	
	/*
	Создает в базе Database::db таблицы "Sites", "Formats", 
	"State", "Scale", "User", "Status", "Session", "Usertype"
	*/
	static void configure();
public:

	/*!
	Пытается открыть базу данных Database::db
	\return true - если база открыта
	*/
	static bool open();
	
	/*!
	Закрывает базу данных Database::db
	*/
	static void close();
	
	/*!
	Метод для подготовки БД к работе.
	Если базы не существует, она будет создана (файл database/geoDB).
	*/
	static void connectToDatabase();
};
