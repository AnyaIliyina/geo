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


/*!
Метод для подготовки БД к работе.
Если базы не существует, она будет создана (файл database/geoDB).
*/
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



/*!
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


/*!
Закрывает базу данных Database::db
*/
void Database::close()
{
	db.close();
}


/*
Создает в базе Database::db таблицы "Sites", "Formats", 
"State", "Scale", "User", "Status", "Session", "Usertype"
*/
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
