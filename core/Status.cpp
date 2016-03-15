#include "Status.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "Database.h"
#include <QTextCodec>

/*!
\file
\brief
*/

QString Status::status_name()
{
	return m_status_name;
}

/*!
������������ ������ ������ Status �� ����������
*/
Status::Status(QString status_name)
{
	m_status_id = 0;
	m_status_name = status_name;
}

/*!
������������ ������ ������ Status �� ������ � ����
\param int id - id ������� � ����
*/
Status::Status(int id)
{
	Database::open();
	QSqlTableModel model;
	model.setTable("statuses");
	const QString filter = QString("status_id == %1").arg(id);
	model.setFilter(filter);
	model.select();
	QString status_name = model.record(0).value("status_name").toString();
	Database::close();

	m_status_id = id;
	m_status_name = status_name;
}

Status::~Status()
{
}

int Status::status_id()
{
	return m_status_id;
}


/*!
���������� ���������� � ������� � ���� ������.
\return true - ���� ������ � �� ������� ���������
*/
bool Status::insertIntoDatabase()
{
	Database::open();
	QSqlQuery query;
	query.prepare("INSERT INTO statuses(status_name)\
	VALUES (?)");
	query.addBindValue(m_status_name);
	if (!query.exec()) {
		qDebug() << "State::insertIntoDatabase(): error inserting into Table statuses";
		qDebug() << query.lastError().text();
		Database::close();
		return false;
	}
	Database::close();
	return true;
}

/*!
������� ������� "statuses" � ���� ������.
\return true - ���� ������� ������� �������
*/
bool Status::createTable()
{
	Database::open();
	QSqlQuery query;
	if (!query.exec("CREATE TABLE IF NOT EXISTS statuses (\
		status_id INTEGER PRIMARY KEY AUTOINCREMENT, \
		status_name TEXT UNIQUE NOT NULL\
		)"
		))
	{
		qDebug() << "error creating statuses Table in database";
		qDebug() << query.lastError().text();
		Database::close();
		return false;
	}
	Database::close();
	return true;
}

/*!
��������� ������� "statuses" � �� ���������� ����������.
\return true - ���� ������� ������� ���������
*/
bool Status::completeTable()
{
	Status *s = new Status(coded("���������"));

	Database::open();
	bool succeeded = s->insertIntoDatabase();
	Database::close();
	return succeeded;
}

QString Status::coded(QByteArray encodedStr)
{
	// �� QByteArray � ���������� Windows-1251 
	QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
	// QTextCodec *codec2 = QTextCodec::codecForName("UTF-8"); 
	QString const string = codec->toUnicode(encodedStr);
	return string;
}
