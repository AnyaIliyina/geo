#include "User.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "Database.h"

QString User::login()
{
	return m_login;
}

User::User(int type_id, QString login, QString password)
{
	m_user_id = 0;
	m_type_id = type_id;
	m_login = login;
	m_password = password;
}

User::User(int id)
{
	QSqlDatabase db = Database::database();
	QSqlTableModel model(nullptr, db);
	model.setTable("users");
	const QString filter = QString("user_id == %1").arg(id);
	model.setFilter(filter);
	model.select();
	QString login = model.record(0).value("login").toString();
	QString password = model.record(0).value("password").toString();
	int type_id = model.record(0).value("type_id").toInt();
	db.close();

	m_user_id = id;
	m_type_id = type_id;
	m_login = login;
	m_password = password;

}

User::~User()
{
}

int User::user_id()
{
	return m_user_id;
}

bool User::insertIntoDatabase()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare("INSERT INTO users ( type_id, login, password)\
		VALUES (?, ?, ?)");
	query.addBindValue(m_type_id);
	query.addBindValue(m_login);
	query.addBindValue(m_password);
	if (!query.exec()) {
		qDebug() << "User::insertIntoDatabase():  error inserting into Table users";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}

bool User::createTable()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	if (!query.exec("CREATE TABLE IF NOT EXISTS  users (\
		user_id  INTEGER         PRIMARY KEY AUTOINCREMENT, \
		type_id     integer    UNIQUE NOT NULL,\
		login NVARCHAR(16) UNIQUE NOT NULL,\
		password NVARCHAR(16),\
		FOREIGN KEY(type_id) REFERENCES usertypes(type_id)\
		 )"
		))
	{
		qDebug() << "error creating users Table in database.";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}

bool User::completeTable()
{
	User *user = new User(1, "search_module", "111");
	bool succeeded = user->insertIntoDatabase();
	delete user;
	return succeeded;
}

bool User::userIsValid(const QString & login, const QString& password)
{
	QSqlDatabase db = Database::database();
	QSqlQuery qry(db);
	if (!qry.exec("SELECT login FROM users WHERE login=\'" + login + "\' AND password=\'" + password + "\'"))
	{
		qDebug() << "error while checking if user is valid.";
		qDebug() << qry.lastError().text();
		db.close();
		return false;
	}
			if (qry.next())
		{
			db.close();
			return true;
		}
		else
		{
			db.close();
			return false;
		}
	
}
