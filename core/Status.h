#pragma once
#pragma once

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUrl>
#include <QDateTime>

/*!
*  \brief Представляет сущность Статус
			(таблица statuses)
*  \author Козырева О.
*  \date 15 марта 2016
*/

class Status {
private:
	int m_status_id;
	QString m_status_name;

public:
	QString status_name();
	Status(QString status_name);
	Status(int id);
	~Status();
	int status_id();
	bool insertIntoDatabase();
	static bool createTable();
	static bool completeTable();
	QString static coded(QByteArray encodedStr);
};

