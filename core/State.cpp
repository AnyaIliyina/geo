#include "State.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "Database.h"
#include <QTextCodec>

/*!
\file
\brief  
*/

QString State::state_name()
{
	return m_state_name;
}

/*!
Конструирует объект класса State из параметров
*/
State::State(QString state_name)
{
	m_state_name = state_name;
	m_state_id = 0;
}

/*!
Конструирует объект класса State из данных в базе
\param int id - id статуса в базе
*/
State::State(int id)
{
	Database::open();
	QSqlTableModel model;
	model.setTable("states");
	const QString filter = QString("state_id == %1").arg(id);
	model.setFilter(filter);
	model.select();
	QString state_name = model.record(0).value("state_name").toString();
	Database::close();

	m_state_id = id;
	m_state_name= state_name;
}

State::~State()
{
}

int State::state_id()
{
	return m_state_id;
}

/*!
Записывает информацию о статусе в базу данных.
\return true - если запись в БД успешно добавлена
*/
bool State::insertIntoDatabase()
{
	Database::open();
	QSqlQuery query;
	query.prepare("INSERT INTO states(state_name)\
	VALUES (?)");
	query.addBindValue(m_state_name);
	if (!query.exec()) {
		qDebug() << "State::insertIntoDatabase(): error inserting into Table states";
		qDebug() << query.lastError().text();
		Database::close();
		return false;
	}
	Database::close();
	return true;
}

/*!
Создает таблицу "states" в базе данных.
\return true - если таблица успешно создана
*/
bool State::createTable()
{
	Database::open();
	QSqlQuery query;
	if (!query.exec("CREATE TABLE IF NOT EXISTS states (\
		state_id INTEGER PRIMARY KEY AUTOINCREMENT, \
		state_name TEXT UNIQUE NOT NULL\
		)"
		))
	{
		qDebug() << "error creating states Table in database";
		qDebug() << query.lastError().text();
		Database::close();
		return false;
	}
	Database::close();
	return true;
}

QString State::coded(QByteArray encodedStr) // метод для получения строки в кодировке Unicode 
{ // из QByteArray с кодировкой Windows-1251 
	QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
	// QTextCodec *codec2 = QTextCodec::codecForName("UTF-8"); 
	QString const string = codec->toUnicode(encodedStr);
	return string;
}

/*!
Заполняет таблицу "states" в БД начальными значениями.
\return true - если таблица успешно заполнена
*/
bool State::completeTable()
{
	State *s = new State(coded("Актуально"));

	Database::open();
	bool succeeded = s->insertIntoDatabase();
	Database::close();
	return succeeded;
}
