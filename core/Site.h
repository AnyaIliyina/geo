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
	Возвращает название сайта
	\return QString& site_name - название сайта
	*/
	const QString& site_name() const;
	
	/*!
	Возвращает комментарий
	\return QString& comment - комментарий
	*/
	const QString& comment() const;

	/*!
	Возвращает id сайта
	\return int site_id - id сайта;
	*/
	int site_id() const;

	/*!
	Возвращает id статуса
	\return int status_id - id статуса;
	*/
	int status_id() const;

	void setStatusId(int status_id);

	/*!
	Конструирует объект класса Site из параметров
	\param const QString& url - адрес(url) сайта;
	\param const QString& site_name - название сайта;
	\param int status;
	\param const QString& comment;
	*/
	Site(const QString& url, const QString& site_name, int status=1, const QString& comment="");
	
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
	static int site_id(QString &url, QString &site_name);

	
	/*!
	Записывает информацию о сайте в базу данных.
	\return site_id
	*/
	 int insertIntoDatabase();

	 /*!
	 Записывает информацию о сайтах из списка в базу
	 \param (QList<Site> sites - список сайтов
	 \return true - информация записана
	 \false -  возникли ошибки
	*/
	 static bool insert(QList<Site> sites);
	
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
