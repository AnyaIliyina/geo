#pragma once
/*!
\file
*/

#include <QString>
#include <QSqlDatabase>
#include <QDir>

/*! 
 *  \brief     Класс для работы с БД
 *  \author    Ильина А.
 *  \date     март 2016
 */
 
class Database {
private:
	static const QString connectionName;	// название подключения
	static const QString pathToDb;			// путь к файлу с базой
	static int CurrentSessionId;
	static int SmSessionId;

	/*!	Создает в базе таблицы "Sites", "Formats",
	"State", "Scale", "User", "Status", "Session", "Usertype" */
	static void configure();

public:
	/*!	Возвращает открытое подключение к базе.
	\return QSqlDatabase db - подключение к базе */
	static QSqlDatabase database();
	
	/*! Создает подключение connectionName к базе. 
	Если необходимо, заново создает таблицы базы pathToDb */
	static void restore();

	static void setCurrentSessionId(int _session_id);
	static void setSmSessionId(int smSessionId);
	static int currentSessionId();
	static int smSessionId();
};