#pragma once
#pragma once

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUrl>
#include <QDateTime>

/*!
*  \brief Представляет сущность Пользователь
			(таблица users)
*  \author Козырева О.
*  \date		15 марта 2016
*/

class User {
private:
	int m_user_id;
	int m_type_id;
	QString m_login;
	QString m_password;

public:
	QString login();
	
	/*!
	Конструирует объект класса User из параметров
	\param int type_id - идентификатор типа пользователя 
	\param QString login - логин пользователя
	\param  QString password - пароль пользователя
	*/
	User(int type_id, QString login, QString password);
	
	/*!
	Конструирует объект класса User из данных в базе
	\param int id - id пользователя в базе
	*/
	User(int id);
	
	~User();
	
	/*!
	Возвращает id пользователя
	\return int user_id - id пользователя в базе
	*/
	int user_id();
	
	/*!
	Записывает информацию о пользователе в базу данных.
	\return true - если запись в БД успешно добавлена
	*/
	bool insertIntoDatabase();
	
	/*!
	Создает таблицу "users" в базе данных.
	\return true - если таблица успешно создана
	*/
	static bool createTable();
	
	/*!
	Заполняет таблицу "users" в БД начальными значениями.
	\return true - если таблица успешно заполнена
	*/
	static bool completeTable();
	
	/*!

	*/
	static bool userIsValid(const QString& login, const QString& password);
};

