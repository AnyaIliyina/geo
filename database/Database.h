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
	static void configure();
public:
	static bool open();
	static void close();
	static void connectToDatabase();
};