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
Êîíñòðóèðóåò îáúåêò êëàññà Format èç ïàðàìåòðîâ
*/
Format::Format(QString format_name)
{
	m_format_name = format_name;
	m_format_id = 0;
}

/*!
Êîíñòðóèðóåò îáúåêò êëàññà Format èç äàííûõ â áàçå
\param int formatId- id ôîðìàòà â áàçå
*/
Format::Format(int id)
{
	Database::open();
	QSqlTableModel model;
	model.setTable("formats");
	const QString filter = QString("format_id == %1");
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
Çàïèñûâàåò èíôîðìàöèþ î ôîðìàòå â áàçó äàííûõ.
\return true - åñëè çàïèñü â ÁÄ óñïåøíî äîáàâëåíà
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
Ñîçäàåò òàáëèöó "formats" â áàçå äàííûõ.
\return true - åñëè òàáëèöà óñïåøíî ñîçäàíà
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
Çàïîëíÿåò òàáëèöó "formats" â ÁÄ íà÷àëüíûìè çíà÷åíèÿìè.
\return true - åñëè òàáëèöà óñïåøíî çàïîëíåíà
*/
bool Format::completeTable()
{
	Format *f = new Format("Shapefile");
	Database::open();
	bool succeeded = f->insertIntoDatabase();
	Database::close();
	return succeeded;
}
