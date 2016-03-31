#include "Format.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "Database.h"

/*!
\file
\brief  
*/

/*!
Возвращает название формата
\return QString& format_name - название формата
*/
const QString& Format::format_name() const
{
	return m_format_name;
}


/*!
Возвращает id формата
\return int format_id - id формата
*/
int Format::format_id() const 
{
	return m_format_id;
}


/*!
Создает формат с заданным названием
\param const QString &format_name - название создаваемого формата
*/
Format::Format(const QString &format_name)
{
	m_format_name = format_name;
	m_format_id = 0;
}

/*!
Конструирует объект, используя информацию в базе
\param int formatId- id формата
*/
Format::Format(int id)
{
	Database::open();
	QSqlTableModel model;
	model.setTable("formats");
	const QString filter = QString("format_id == %1").arg(id);
	model.setFilter(filter);
	model.select();
	QString format_name = model.record(0).value("format_name").toString();
	Database::close();

	m_format_id = id;
	m_format_name = format_name;
}

Format::~Format()
{
}


/*!
Записывает информацию о формате в таблицу БД "formats"
\return true - если информация записана
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
	Database::close();
	return true;
}

/*!
Создает таблицу "formats" в базе.
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
Заполняет таблицу "formats" начальными значениями
\return true - если записи успешно созданы
*/
bool Format::completeTable()
{
	Format *f = new Format("Shapefile");
	Database::open();
	bool succeeded = f->insertIntoDatabase();
	Database::close();
	return succeeded;
}
