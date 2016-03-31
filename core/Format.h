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
*  \brief    Представляет сущность Формат
(таблица formats)
*  \author   Козырева О.
*  \date     15 март 2016
*/


class Format {
private:
	int m_format_id;
	QString m_format_name;
	
public:
	const QString& format_name() const;
	int format_id() const;
	Format(const QString& format_name);
	Format(int id);
	~Format();
	bool insertIntoDatabase();
	static bool createTable();
	static bool completeTable();

};