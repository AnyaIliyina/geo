#include "Log.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "Database.h"
#include "Log.h"

/*!
\file
\brief  
*/

bool Log::createTable()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	if (!query.exec("CREATE TABLE IF NOT EXISTS logs (\
		log_id INTEGER PRIMARY KEY AUTOINCREMENT, \
		format_name TEXT UNIQUE NOT NULL\
		)"
		))
	{
		qDebug() << "error creating formats Table in database";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}
