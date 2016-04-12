#include "Status.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "Database.h"
#include <QTextCodec>

/*!
\file
\brief
*/

QString Status::status_name()
{
	return m_status_name;
}

Status::Status(QString status_name)
{
	m_status_id = 0;
	m_status_name = status_name;
}

Status::Status(int id)
{
	QSqlDatabase db = Database::database();
	QSqlTableModel model(nullptr, db);
	model.setTable("statuses");
	const QString filter = QString("status_id == %1").arg(id);
	model.setFilter(filter);
	model.select();
	QString status_name = model.record(0).value("status_name").toString();
	db.close();

	m_status_id = id;
	m_status_name = status_name;
}

Status::~Status()
{
}

int Status::status_id()
{
	return m_status_id;
}

bool Status::insertIntoDatabase()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare("INSERT INTO statuses(status_name)\
	VALUES (?)");
	query.addBindValue(m_status_name);
	if (!query.exec()) {
		qDebug() << "State::insertIntoDatabase(): error inserting into Table statuses";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}

bool Status::createTable()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	if (!query.exec("CREATE TABLE IF NOT EXISTS statuses (\
		status_id INTEGER PRIMARY KEY AUTOINCREMENT, \
		status_name TEXT UNIQUE NOT NULL\
		)"
		))
	{
		qDebug() << "error creating statuses Table in database";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}

bool Status::completeTable()
{
	Status *s = new Status(coded("Проверено"));
	bool succeeded = s->insertIntoDatabase();
	delete s;
	return succeeded;
}

QString Status::coded(QByteArray encodedStr)
{
	// из QByteArray с кодировкой Windows-1251 
	QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
	// QTextCodec *codec2 = QTextCodec::codecForName("UTF-8"); 
	QString const string = codec->toUnicode(encodedStr);
	return string;
}
