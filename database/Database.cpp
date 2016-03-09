#include "Database.h"
#include "Format.h"
#include "State.h"
#include <QFileInfo>
/*!
\file
*/

QSqlDatabase Database::db = Database::createDatabase();


/*!
Создает файл database/geoDB, если его еще не существует
\return QSqlDatabase dbase 
*/
QSqlDatabase Database::createDatabase()
{
	QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
	QString pathToDB = QDir::currentPath() + QString("/database/geoDB");
	dbase.setDatabaseName(pathToDB);
	QFileInfo dbFile(pathToDB);
	if (!dbFile.exists())
	{
	//	Site::createTable();
	//	Site::completeTable();
	}
		
	return dbase;
}


/*
Пытается открыть базу данных Database::db
\return true - если база открыта
*/
bool Database::open()
{
	if (!db.open())
	{
		qDebug() << "Error opening database";
		return false;
	}
	return true;
}


/* 
Закрывает базу данных Database::db
*/
void Database::close()
{
	db.close();
}


/*
Создает в базе Database::db таблицы "Sites", "Formats"
*/
void Database::configure()
{
	Site::createTable();
	Site::completeTable();
	Format::createTable();
	Format::completeTable();
	State::createTable();
	State::completeTable();
}
