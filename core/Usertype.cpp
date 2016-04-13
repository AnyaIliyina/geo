﻿#include "Usertype.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "Database.h"
#include <QTextCodec>

/*!
\file
\brief
*/

QString Usertype::type_name()
{
	return m_type_name;
}

Usertype::Usertype(QString type_name)
{
	m_type_id = 0;
	m_type_name = type_name;
}

Usertype::Usertype(int id)
{
	QSqlDatabase db = Database::database();
	QSqlTableModel model(this, db);
	model.setTable("usertypes");
	const QString filter = QString("type_id == %1").arg(id);
	model.setFilter(filter);
	model.select();
	QString type_name = model.record(0).value("type_name").toString();
	db.close();

	m_type_id = id;
	m_type_name = type_name;
}

Usertype::~Usertype()
{
}

int Usertype::type_id()
{
	return m_type_id;
}

bool Usertype::insertIntoDatabase()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare("INSERT INTO usertypes(type_name)\
	VALUES (?)");
	query.addBindValue(m_type_name);
	if (!query.exec()) {
		qDebug() << "State::insertIntoDatabase(): error inserting into Table usertypes";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}

bool Usertype::createTable()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	if (!query.exec("CREATE TABLE IF NOT EXISTS usertypes (\
		type_id INTEGER PRIMARY KEY AUTOINCREMENT, \
		type_name TEXT UNIQUE NOT NULL\
		)"
		))
	{
		qDebug() << "error creating usertypes Table in database";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}

bool Usertype::completeTable()
{
	Usertype *user = new Usertype(coded("Модуль поиска"));
	bool succeeded = user->insertIntoDatabase();
	delete user;
	return succeeded;
}

QString Usertype::coded(QByteArray encodedStr)
{
	// из QByteArray с кодировкой Windows-1251 
	QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
	// QTextCodec *codec2 = QTextCodec::codecForName("UTF-8"); 
	QString const string = codec->toUnicode(encodedStr);
	return string;
}
