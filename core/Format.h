﻿#pragma once

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUrl>
#include <QDateTime>

/*!
*  \brief     
*  \details
*  \author    
*  \version
*  \date      
*  \pre
*  \bug
*  \warning
*  \copyright
*/

class Format {
private:
	int m_format_id;
	QString m_format_name;
	
public:
	QString format_name();
	int format_id();
	Format( QString format_name);
	Format(int id);
	~Format();
	bool insertIntoDatabase();
	static bool createTable();
	static bool completeTable();

};