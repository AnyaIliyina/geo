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
	Database::open();
	QSqlTableModel model;
	model.setTable("users");
	const QString filter = QString("user_id == %1").arg(id);
	model.setFilter(filter);
	model.select();
	QString login = model.record(0).value("login").toString();
	QString password = model.record(0).value("password").toString();
	int type_id = model.record(0).value("type_id").toInt();
	Database::close();

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
	Database::open();
	QSqlQuery query;
	query.prepare("INSERT INTO users ( type_id, login, password)\
		VALUES (?, ?, ?)");
	query.addBindValue(m_type_id);
	query.addBindValue(m_login);
	query.addBindValue(m_password);
	if (!query.exec()) {
		qDebug() << "User::insertIntoDatabase():  error inserting into Table users";
		qDebug() << query.lastError().text();
		Database::close();
		return false;
	}
	Database::close();
	return true;
}

bool User::createTable()
{
	Database::open();
	QSqlQuery query;
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
		Database::close();
		return false;
	}
	Database::close();
	return true;
}

bool User::completeTable()
{
	User *user = new User(1, "search_module", "111");
	Database::open();
	bool succeeded = user->insertIntoDatabase();
	Database::close();
	return succeeded;
}

bool User::usersValig(const QString & login, const QString& password)
{
	Database::open();
	QSqlQuery qry;
	if (qry.exec("SELECT login FROM users WHERE login=\'" + login + "\' AND password=\'" + password + "\'"))
	{
		if (qry.next())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
