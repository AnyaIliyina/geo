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
������������ ������ ������ State �� ����������
*/
State::State(QString state_name)
{
	m_state_name = state_name;
	m_state_id = 0;
}

/*!
������������ ������ ������ State �� ������ � ����
\param int id - id ����� � ����
*/
State::State(int id)
{
	Database::open();
	QSqlTableModel model;
	model.setTable("states");
	const QString filter = QString("state_id == %1");
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
���������� ���������� � ������� � ���� ������.
\return true - ���� ������ � �� ������� ���������
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
������� ������� "states" � ���� ������.
\return true - ���� ������� ������� �������
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

QString State::coded(QByteArray encodedStr) // ����� ��� ��������� ������ � ��������� Unicode 
{ // �� QByteArray � ���������� Windows-1251 
	QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
	// QTextCodec *codec2 = QTextCodec::codecForName("UTF-8"); 
	QString const string = codec->toUnicode(encodedStr);
	return string;
}

/*!
��������� ������� "states" � �� ���������� ����������.
\return true - ���� ������� ������� ���������
*/
bool State::completeTable()
{
	State *s = new State("���������");

	Database::open();
	bool succeeded = s->insertIntoDatabase();
	Database::close();
	return succeeded;
}
