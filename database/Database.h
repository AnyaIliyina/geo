#pragma once
/*!
\file
*/

#include "Site.h"
#include <QDir>

/*! 
 *  \brief     Класс для работы с БД
 *  \details   
 *  \author    Ильина А.
 *  \author    
 *  \version   
 *  \date     март 2016
 *  \pre      
 *  \bug      
 *  \warning   
 *  \copyright 
 */
 
class Database {
private:
	static QSqlDatabase db;
	static QSqlDatabase createDatabase();
public:
	static bool open();
	static void close();
	static void configure();
};