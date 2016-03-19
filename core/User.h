#pragma once
#pragma once

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUrl>
#include <QDateTime>

/*!
*  \brief
*  \details
*  \author
*  \version
*  \date		15 ����� 2016
*  \pre
*  \bug
*  \warning
*  \copyright
*/

class User {
private:
	int m_user_id;
	int m_type_id;
	QString m_login;
	QString m_password;

public:
	QString login();
	User(int type_id, QString login, QString password);
	User(int id);
	~User();
	int user_id();
	bool insertIntoDatabase();
	static bool createTable();
	static bool completeTable();
	
};

