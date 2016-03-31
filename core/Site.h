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
 *  \brief     Представляет сущность Сайт
			(таблица sites)
 *  \author    Ильина А.
 *  \date      март 2016
 */

class Site {
private:
	int m_site_id;
	QString m_url;
	int m_status_id;
	QString m_site_name;
	QString m_comment;
public:
	const QString& url() const;
	Site(const QString& url, const QString& site_name, int status = 0, const QString& comment="");
	Site(int id);
	~Site();
	int site_id() const;
	bool insertIntoDatabase();
	static bool createTable();
	static bool completeTable();
	static QList<Site> sitesByStatus(int statusId);

};