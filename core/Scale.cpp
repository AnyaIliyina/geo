#include "Scale.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "Database.h"
#include <QTextCodec>

/*!
\file
\brief
*/

QString Scale::description()
{
	return m_description;
}

Scale::Scale(QString description)
{
	m_description = description;
	m_scale_id = 0;
}

Scale::Scale(int id)
{
	QSqlDatabase db = Database::database();
	QSqlTableModel model(nullptr, db);
	model.setTable("scales");
	const QString filter = QString("scate_id == %1");
	model.setFilter(filter);
	model.select();
	QString description = model.record(0).value("description").toString();
	db.close();

	m_scale_id = id;
	m_description = description;
}

Scale::~Scale()
{
}

int Scale::scale_id()
{
	return m_scale_id;
}

bool Scale::insertIntoDatabase()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare("INSERT INTO scales(description)\
	VALUES (?)");
	query.addBindValue(m_description);
	if (!query.exec()) {
		qDebug() << "Scale::insertIntoDatabase(): error inserting into Table scales";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}

bool Scale::createTable()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	if (!query.exec("CREATE TABLE IF NOT EXISTS scales (\
		scale_id INTEGER PRIMARY KEY AUTOINCREMENT, \
		description TEXT UNIQUE NOT NULL\
		)"
		))
	{
		qDebug() << "error creating scales Table in database";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}

QString Scale::coded(QByteArray encodedStr) // метод для получения строки в кодировке Unicode 
{ // из QByteArray с кодировкой Windows-1251 
	QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
	// QTextCodec *codec2 = QTextCodec::codecForName("UTF-8"); 
	QString const string = codec->toUnicode(encodedStr);
	return string;
}

bool Scale::completeTable()
{
	Scale *s = new Scale("500:1");
	bool succeeded = s->insertIntoDatabase();
	delete s;
	return succeeded;
}
