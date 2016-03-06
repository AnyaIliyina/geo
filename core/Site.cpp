#include "Site.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "Database.h"

/*!
\file
\brief 
*/


QString  Site::url()
{
	return m_url.toString();
}

/*!
Конструирует объект класса Site из параметров
*/
Site::Site(QUrl url, bool checked, QString comment)
{
	m_url = url;
	m_checked = checked;
	m_modificationDate = QDateTime::currentDateTime();
	m_comment = comment;
}

/*!
Конструирует объект класса Site из данных в базе
\param int site_id - id сайта в базе
*/
Site::Site(int site_id)
{
	Database::open();
	QSqlTableModel model;
	model.setTable("Sites");
	//const QString filter("siteId == " + QString::number(site_id));
	const QString filter = QString("siteId == %1").arg(site_id);
	model.setFilter(filter);
	model.select();
	QString url = model.record(0).value("url").toString();
	bool checked = model.record(0).value("checked").toInt();
	int modificationDate = model.record(0).value("date").toInt();
	qDebug() << QDateTime::fromTime_t(modificationDate).toString("dd-MM-yyyy, HH:mm");
	QString comment = model.record(0).value("comment").toString();
	Database::close();
	
	m_url = QUrl(url);
	m_checked = bool(checked);
	m_modificationDate = QDateTime::fromTime_t(modificationDate);
	m_comment = comment;
}

Site::~Site()
{
}


/*!
Записывает информацию о сайте в базу данных.
\return true - если запись в БД успешно добавлена
*/
bool Site::insertIntoDatabase()
{
	Database::open();
	QSqlQuery query;
	query.prepare("INSERT INTO Sites ( url, checked, date, comment)\
		VALUES (?, ?, ?, ?)");
	query.addBindValue(m_url);
	query.addBindValue(m_checked);
	query.addBindValue(m_modificationDate.toTime_t());
	query.addBindValue(m_comment);
	if (!query.exec()) {
		qDebug() << "URL::insertIntoDatabase():  error inserting into Table URLs";
		qDebug() << query.lastError().text();
		Database::close();
		return false;
	}
	Database::close();
	return true;
}


/*!
Создает таблицу "Sites" в базе данных.
\return true - если таблица успешно создана
*/
bool Site::createTable()
{
	Database::open();
	QSqlQuery query;
	if (!query.exec("CREATE TABLE IF NOT EXISTS  Sites (\
		siteId  INTEGER         PRIMARY KEY AUTOINCREMENT, \
		url    VARCHAR(255)    UNIQUE NOT NULL,\
		checked INTEGER,		\
		date	INTEGER    NOT NULL,\
		comment VARCHAR(255)   \
		 )"
		)) 
	{
		qDebug() << "error creating Sites Table in database.";
		qDebug() << query.lastError().text();
		Database::close();
		return false;
	}
	Database::close();
	return true;
	
}


/*!
Заполняет таблицу "Sites" в БД начальными значениями.
\return true - если таблица успешно заполнена
*/
bool Site::completeTable()
{
	Site *s = new Site(QUrl("http://beryllium.gis-lab.info/project/osmshp"));
	// Site *s = new Site(QUrl("http://www.afanas.ru/mapbase/"));
	Database::open();
	bool succeeded = s->insertIntoDatabase();
	Database::close();
	return succeeded;
}
