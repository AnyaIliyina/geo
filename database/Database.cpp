#include "Database.h"
#include "Format.h"
#include "State.h"
#include "Scale.h"
#include "User.h"
#include "Status.h"
#include "Session.h"
#include "Usertype.h"
#include "Site.h"
#include "Geodata_record.h"
#include <QFileInfo>
/*!
\file
*/

const QString Database::pathToDb = QDir::currentPath() + QString("/database/geoDB"); // путь к базе

const QString Database::connectionName = "geoDb_connection";	// название подключения


																/*!
Создает подключение connectionName к базе.
Если необходимо, заново создает таблицы базы pathToDb 
*/
void Database::restore()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
	db.setDatabaseName(pathToDb);

	// Если файла pathToDb не существует, создать все таблицы:
	QFileInfo dbFile(pathToDb);
	if (!dbFile.exists()) {
		configure();
	}
}


/*!
Возвращает открытое подключение к базе.
\return QSqlDatabase db - подключение к базе
*/
QSqlDatabase Database::database()
{
	return QSqlDatabase::database(connectionName, true);;
}



/*!
Создает в базе таблицы "Sites", "Formats", 
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
