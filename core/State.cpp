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

State::State(QString state_name)
{
	m_state_name = state_name;
	m_state_id = 0;
}

State::State(int id)
{
	QSqlDatabase db = Database::database();
	QSqlTableModel model(nullptr, db);
	model.setTable("states");
	const QString filter = QString("state_id == %1").arg(id);
	model.setFilter(filter);
	model.select();
	QString state_name = model.record(0).value("state_name").toString();
	db.close();

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

bool State::insertIntoDatabase()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	query.prepare("INSERT INTO states(state_name)\
	VALUES (?)");
	query.addBindValue(m_state_name);
	if (!query.exec()) {
		qDebug() << "State::insertIntoDatabase(): error inserting into Table states";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}

bool State::createTable()
{
	QSqlDatabase db = Database::database();
	QSqlQuery query(db);
	if (!query.exec("CREATE TABLE IF NOT EXISTS states (\
		state_id INTEGER PRIMARY KEY AUTOINCREMENT, \
		state_name TEXT UNIQUE NOT NULL\
		)"
		))
	{
		qDebug() << "error creating states Table in database";
		qDebug() << query.lastError().text();
		db.close();
		return false;
	}
	db.close();
	return true;
}

QString State::coded(QByteArray encodedStr) // метод для получения строки в кодировке Unicode 
{ // из QByteArray с кодировкой Windows-1251 
	QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
	// QTextCodec *codec2 = QTextCodec::codecForName("UTF-8"); 
	QString const string = codec->toUnicode(encodedStr);
	return string;
}

bool State::completeTable()
{
	State *s = new State(coded("Актуально"));
	bool succeeded = s->insertIntoDatabase();
	delete s;
	return succeeded;
}
