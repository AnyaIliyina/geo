#include "Site.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "Database.h"

/*!
\file
\brief 
*/

const QString&  Site::url() const
{
	return m_url;
}

Site::Site(const QString& url, const QString& site_name, int status, const QString& comment)
{
	m_site_id = 0;
	m_url = url;
	m_site_name = site_name;
	m_status_id = status;
	m_comment = comment;
}

Site::Site(int id)
{
	QSqlDatabase db = Database::database();
	QSqlTableModel model(nullptr, db);
	model.setTable("sites");
	//const QString filter("siteId == " + QString::number(site_id));
	const QString filter = QString("site_id == %1").arg(id);
	model.setFilter(filter);
	model.select();
	QString url = model.record(0).value("url").toString();
	QString site_name = model.record(0).value("site_name").toString();
	int status_id= model.record(0).value("status_id").toInt();
	QString comment = model.record(0).value("comment").toString();
	db.close();
		
	m_site_id = id;
	m_url = url;
	m_site_name = site_name;
	m_status_id = status_id;
	m_comment = comment;
}

Site::~Site()
{
}


int Site::site_id()
{
	return m_site_id;
}


int Site::site_id(QString & url, QString & site_name) 
{
	qDebug() << "Zashel v -1";
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	
	if (!query.exec("SELECT site_id FROM sites WHERE (url=\'" + url + "\') OR (site_name=\'" + site_name + "\')"))
	{
		qDebug() << "Zapros ne proshel";
	}
	else
	{
		if (query.next())
		{
			int id = query.value(0).toInt();
			return id;
		}

	}

}


int Site::insertIntoDatabase()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare("INSERT INTO sites ( url, site_name, status_id, comment)\
		VALUES (?, ?, ?, ?)");
	query.addBindValue(m_url);
	query.addBindValue(m_site_name);
	query.addBindValue(m_status_id);
	query.addBindValue(m_comment);
	if (!query.exec()) {
		qDebug() << "Site::insertIntoDatabase():  error inserting into Table sites";
		qDebug() << query.lastError().text();
		db.close();
		return -1;
		qDebug() << -1;

	}
	else {
		int id = query.lastInsertId().toInt();
		db.close();
		return id;
	}
	
}

bool Site::createTable()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.exec("PRAGMA foreign_keys = ON");
	if ((!query.exec("CREATE TABLE IF NOT EXISTS  sites (\
		site_id  INTEGER         PRIMARY KEY AUTOINCREMENT, \
		url     TEXT    UNIQUE NOT NULL,\
		site_name TEXT UNIQUE NOT NULL,\
		status_id INTEGER,		\
		comment TEXT,   \
		FOREIGN KEY(status_id) REFERENCES statuses(status_id)\
		)"
		)) )
	{
		qDebug() << "error creating sites Table in database.";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
	
}

bool Site::completeTable()
{
	Site *s = new Site("http://beryllium.gis-lab.info/project/osmshp", "gis-lab");
	// Site *s = new Site(QUrl("http://www.afanas.ru/mapbase/"));
	bool succeeded = s->insertIntoDatabase();
	delete s;
	return succeeded;
}

QList<Site> Site::sitesByStatus(int statusId)
{
	QList<Site> siteList;
	QSqlDatabase db = Database::database();
	QSqlTableModel model(nullptr, db);
	model.setTable("sites");
	const QString filter = QString("status_id == %1").arg(statusId);
	model.setFilter(filter);
	model.select();
	for (int i = 0; i < model.rowCount(); i++)
	{
		Site *s = new Site(model.record(i).value("site_id").toInt());
		siteList.append(*s);
		delete s;
	}
	db.close();
	return siteList;
}
