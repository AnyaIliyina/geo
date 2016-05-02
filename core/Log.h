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
	int m_log_id;
	int m_session_id;
	QString m_operation_name;
	int m_object_id = 0;
	QString m_error_string = "";
public:
	
	
	/*!
	Создает таблицу "logs" в базе.
	\return true - если таблица успешно создана
	*/
	static bool createTable();
	
};
