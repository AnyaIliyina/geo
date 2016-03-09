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
*  \date		9 марта 2016
*  \pre
*  \bug
*  \warning
*  \copyright
*/

class State {
private:
	int m_state_id;
	QString m_state_name;

public:
	QString state_name();
	State(QString state_name);
	State(int id);
	~State();
	int state_id();
	bool insertIntoDatabase();
	static bool createTable();
	static bool completeTable();
	QString coded(QByteArray encodedStr);
};
