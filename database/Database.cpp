#include "Database.h"
#include "Format.h"
#include "State.h"
#include "Scale.h"
#include "User.h"
#include "Status.h"
#include "Session.h"
#include "Usertype.h"
#include "Geodata_record.h"
#include <QFileInfo>
/*!
\file
*/

QSqlDatabase Database::db;

void Database::connectToDatabase()
{
	// инициализируем статическое поле Database::db
	db = QSqlDatabase::addDatabase("QSQLITE");
	QString pathToDB = QDir::currentPath() + QString("/database/geoDB");
	db.setDatabaseName(pathToDB);
	
	// проверяем, существет ли файл с базой:
	QFileInfo dbFile(pathToDB);	
	if (!dbFile.exists())	
	{
		configure();	// если нет, восстанавливаем базу
						//	(снова создаем все таблицы)
	}
}



bool Database::open()
{
	if (!db.open())
	{
		qDebug() << "Error opening database";
		return false;
	}
	return true;
}

void Database::close()
{
	db.close();
}

void Database::configure()
{
		Site::createTable();
		Site::completeTable();
		Format::createTable();
		Format::completeTable();
		State::createTable();
		State::completeTable();
		Scale::createTable();
		Scale::completeTable();
		User::createTable();
		User::completeTable();
		Status::createTable();
		Status::completeTable();
		Usertype::createTable();
		Usertype::completeTable();
		Geodata_record::createTable();
		Geodata_record::completeTable();
		Session::createTable();
		Session::completeTable();
}
