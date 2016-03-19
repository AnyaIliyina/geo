#pragma once

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUrl>
#include <QDateTime>

/*! 
 *  \brief     Класс "Сайт"
 *  \details  
 *  \author    Ильина А.
 *  \version   
 *  \date      март 2016
 *  \pre      
 *  \bug      
 *  \warning   
 *  \copyright 
 */

class Site {
private:
	int m_site_id;
	QString m_url;
	int m_status_id;
	QString m_site_name;
	QString m_comment;
public:
	QString url();
	Site(QString url, QString site_name, int status = 0,  QString comment="");
	Site(int id);
	~Site();
	int site_id();
	bool insertIntoDatabase();
	static bool createTable();
	static bool completeTable();
	static QList<Site> sitesByStatus(int statusId);

};