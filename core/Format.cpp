#include "Format.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "Database.h"

/*!
\file
\brief  
*/

QString Format::format_name()
{
	return m_format_name;
}

int Format::format_id()
{
	return m_format_id;
}
/*!
Конструирует объект класса Format из параметров
*/
Format::Format(QString format_name)
{
	m_format_name = format_name;
	m_format_id = 0;
}

/*!
Конструирует объект класса Format из данных в базе
\param int formatId- id формата в базе
*/
Format::Format(int id)
{
	Database::open();
	QSqlTableModel model;
	model.setTable("formats");
	const QString filter = QString("format_id == %1");
	model.setFilter(filter);
	model.select();
	QString format_name = model.record(0).value("format_name").toString;
	Database::close();

	m_format_id = id;
	m_format_name = format_name;
}

Format::~Format()
{
}

/*!
Записывает информацию о формате в базу данных.
\return true - если запись в БД успешно добавлена
*/
bool Format::insertIntoDatabase()
{
	Database::open();
	QSqlQuery query;
	query.prepare("INSERT INTO formats(format_name)\
	VALUES (?)");
	query.addBindValue(m_format_name);
	if (!query.exec()) {
		qDebug() << "Format::insertIntoDatabase(): error inserting into Table formats";
		qDebug() << query.lastError().text();
		Database::close();
		return false;
	}
	Database::close;
	return true;
}

/*!
Создает таблицу "formats" в базе данных.
\return true - если таблица успешно создана
*/
bool Format::createTable()
{
	Database::open();
	QSqlQuery query;
	if (!query.exec("CREATE TABLE IF NOT EXISTS formats (\
		format_id INTEGER PRIMARY KEY AUTOINCREMENT, \
		format_name TEXT UNIQUE NOT NULL\
		)"
		))
	{	
		qDebug() << "error creating formats Table in database";
		qDebug() << query.lastError().text();
		Database::close();
		return false;
	}
	Database::close();
	return true;
}

/*!
Заполняет таблицу "formats" в БД начальными значениями.
\return true - если таблица успешно заполнена
*/
bool Format::completeTable()
{
	Format *f = new Format("Shapefile");
	Database::open();
	bool succeeded = f->insertIntoDatabase();
	Database::close();
	return succeeded;
}
