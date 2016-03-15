#include "Session.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "Database.h"
#include <QTextCodec>

Session::Session(int user_id, QDateTime date)
{
	m_session_id = 0;
	m_user_id = user_id;
	m_date = date;
}

Session::Session(int id)
{
	Database::open();
	QSqlTableModel model;
	model.setTable("sessions");
	const QString filter = QString("session_id == %1").arg(id);
	model.setFilter(filter);
	model.select();
	int user_id = model.record(0).value("user_id").toInt();
	int date = model.record(0).value("date").toInt();
	Database::close();

	m_session_id = id;
	m_user_id = user_id;
	m_date = QDateTime::fromTime_t(date);
	
}

Session::~Session()
{
}

int Session::session_id()
{
	return m_session_id;
}

/*!
Записывает информацию о сессии в базу данных.
\return true - если запись в БД успешно добавлена
*/
bool Session::insertIntoDatabase()
{
	Database::open();
	QSqlQuery query;
	query.prepare("INSERT INTO sessions ( user_id, date)\
		VALUES (?, ?)");
	query.addBindValue(m_user_id);
	query.addBindValue(m_date.toTime_t());
	
	if (!query.exec()) {
		qDebug() << "Session::insertIntoDatabase():  error inserting into Table sessions";
		qDebug() << query.lastError().text();
		Database::close();
		return false;
	}
	Database::close();
	return true;
}

/*!
Создает таблицу "sessions" в базе данных.
\return true - если таблица успешно создана
*/
bool Session::createTable()
{
	Database::open();
	QSqlQuery query;
	if ((!query.exec("CREATE TABLE IF NOT EXISTS  sessions (\
		session_id  INTEGER         PRIMARY KEY AUTOINCREMENT, \
		user_id     INTEGER ,\
		date INTEGER, \
		FOREIGN KEY(user_id) REFERENCES users(user_id)\
		 )"
		)))
	{
		qDebug() << "error creating sessions Table in database.";
		qDebug() << query.lastError().text();
		Database::close();
		return false;
	}
	Database::close();
	return true;

}

bool Session::completeTable()
{
	Session *s = new Session(1, QDateTime::currentDateTime());
	
	Database::open();
	bool succeeded = s->insertIntoDatabase();
	Database::close();
	return succeeded;
}
