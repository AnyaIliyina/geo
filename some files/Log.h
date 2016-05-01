#pragma once

#include <QObject>
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUrl>
#include <QDateTime>

/*!
\file
*/

/*!
*  \brief    Класс для краткой записи истории действий с базой
(таблица Logs)
*  \author   Ильина А.
*  \date     май 2016
*/


class Log: public QObject {
	Q_OBJECT
private:
	int m_session_id;
	QString m_operation_name;
	QString m_error = "";
public:
	/*!
	Возвращает название формата
	\return QString& format_name - название формата
	*/
	const QString& format_name() const;

	/*!
	Возвращает id формата
	\return int format_id - id формата
	*/
	static int format_id(QString format_name);
	
	/*!
	Создает формат с заданным названием
	\param const QString &format_name - название создаваемого формата
	*/
	Format(const QString& format_name);
	
	/*!
	Конструирует объект, используя информацию в базе
	\param int formatId- id формата
	*/
	Format(int id);
	
	~Format();
	
	/*!
	Записывает информацию о формате в таблицу БД "formats"
	\return true - если информация записана
	*/
	bool insertIntoDatabase();

	
	/*!
	Создает таблицу "formats" в базе.
	\return true - если таблица успешно создана
	*/
	static bool createTable();
	
};
