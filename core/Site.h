#pragma once

#include <QObject>
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

class Site
{
private:
	int m_site_id;
	QString m_url;
	int m_status_id;
	QString m_site_name;
	QString m_comment;
public:

	/*!
	Возвращает адрес сайта
	\return QString& url - адрес сайта
	*/
	const QString& url() const;
	
	/*!
	Конструирует объект класса Site из параметров
	\param const QString& url - адрес(url) сайта;
	\param const QString& site_name - название сайта;
	\param int status;
	\param const QString& comment;
	*/
	Site(const QString& url, const QString& site_name, int status = 0, const QString& comment="");
	
	/*!
	Конструирует объект класса Site из данных в базе
	\param int id - id сайта
	*/
	Site(int id);
	
	~Site();
	
	/*!
	Возвращает id сайта
	\return int site_id - id сайта;
	*/
	int site_id() const;
	
	/*!
	Записывает информацию о сайте в базу данных.
	\return true - если запись в БД успешно добавлена
	*/
	bool insertIntoDatabase();
	
	/*!
	Создает таблицу "sites" в базе данных.
	\return true - если таблица успешно создана
	*/
	static bool createTable();
	
	/*!
	Заполняет таблицу "sites" в БД начальными значениями.
	\return true - если таблица успешно заполнена
	*/
	static bool completeTable();
	
	/*!
	\brief Возвращает список сайтов с определенным status_id
	\param int statusId - id статуса
	\return QList<Site> siteList - список сайтов со статусом statusId
	*/
	static QList<Site> sitesByStatus(int statusId);

};
