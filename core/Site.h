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
	QUrl m_url;
	bool m_checked;
	QDateTime m_modificationDate;
	QString m_comment;
public:
	QString url();
	Site(QUrl url, bool checked = false, QString comment="");
	Site(int site_id);
	~Site();
	bool insertIntoDatabase();
	static bool createTable();
	static bool completeTable();

};