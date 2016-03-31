﻿#pragma once
#pragma once

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUrl>
#include <QDateTime>

/*!
*  \brief Представляет сущность Масштаб
		(таблица scales)
*  \author Козырева О.
*  \date 10 марта 2016
*/

class Scale {
private:
	int m_scale_id;
	QString m_description;

public:
	QString description();
	Scale(QString description);
	Scale(int id);
	~Scale();
	int scale_id();
	bool insertIntoDatabase();
	static bool createTable();
	static bool completeTable();
	QString coded(QByteArray encodedStr);
};

