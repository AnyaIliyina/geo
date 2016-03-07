#pragma once

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
	int m_formatId;
	QString m_formatName;
	
public:
	QString formatName();
	int formatId();
	Format(int formatId, QString formatName);
	Format(int formatId);
	~Format();
	bool insertIntoDatabase();
	static bool createTable();
	static bool completeTable();

};