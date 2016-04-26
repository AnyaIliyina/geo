﻿#pragma once

#include <QObject>
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

class Status : public QObject {
	Q_OBJECT
private:
	int m_status_id;
	QString m_status_name;

public:
	QString status_name();
		
	/*!
	Конструирует объект класса Status из параметров
	\param const QString status_name - название создаваемого статуса
	*/
	Status(QString status_name);
	
	/*!
	Конструирует объект класса Status из данных в базе
	\param int id - id статуса в базе
	*/
	Status(int id);
	
	~Status();
	
	/*!
	Возвращает id статуса
	\return int status_id - id статуса
	*/
	int status_id();
	
	/*!
	Записывает информацию о статусе в базу данных.
	\return true - если запись в БД успешно добавлена
	*/
	bool insertIntoDatabase();
	
	/*!
	Создает таблицу "statuses" в базе данных.
	\return true - если таблица успешно создана
	*/
	static bool createTable();

	/*!
	Заполняет таблицу "statuses" в БД начальными значениями.
	\return true - если таблица успешно заполнена
	*/
	static bool completeTable();

	/*!
	Записывает в базу данных список статусов
	\param QStringList statusNames - список названий статусов
	\return true - статусы записаны в БД
	\return false - возникли ошибки*/
	static bool insert(QStringList statusNames);

	
	QString static coded(QByteArray encodedStr);
};

