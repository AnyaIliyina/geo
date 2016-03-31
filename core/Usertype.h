#pragma once
#pragma once

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUrl>
#include <QDateTime>

/*!
*  \brief Представляет сущность Тип пользователя
			(таблица usertypes)
*  \author Козырева О.
*  \date		15 марта 2016
*/

class Usertype {
private:
	int m_type_id;
	QString m_type_name;

public:
	QString type_name();
	Usertype(QString type_name);
	Usertype(int id);
	~Usertype();
	int type_id();
	bool insertIntoDatabase();
	static bool createTable();
	static bool completeTable();
	QString static coded(QByteArray encodedStr);
};

