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
*  \date		15 марта 2016
*  \pre
*  \bug
*  \warning
*  \copyright
*/

class Session {
private:
	int m_session_id;
	int m_user_id;
	QDateTime m_date;

public:
	
	Session(int user_id, QDateTime date);
	Session(int id);
	~Session();
	int session_id();
	bool insertIntoDatabase();
	static bool createTable();
	static bool completeTable();

};


