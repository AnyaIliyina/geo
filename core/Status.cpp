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
Конструирует объект класса Status из параметров
*/
Status::Status(QString status_name)
{
	m_status_id = 0;
	m_status_name = status_name;
}

/*!
Конструирует объект класса Status из данных в базе
\param int id - id статуса в базе
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
Записывает информацию о статусе в базу данных.
\return true - если запись в БД успешно добавлена
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
Создает таблицу "statuses" в базе данных.
\return true - если таблица успешно создана
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
Заполняет таблицу "statuses" в БД начальными значениями.
\return true - если таблица успешно заполнена
*/
bool Status::completeTable()
{
	Status *s = new Status(coded("Проверено"));

	Database::open();
	bool succeeded = s->insertIntoDatabase();
	Database::close();
	return succeeded;
}

QString Status::coded(QByteArray encodedStr)
{
	// из QByteArray с кодировкой Windows-1251 
	QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
	// QTextCodec *codec2 = QTextCodec::codecForName("UTF-8"); 
	QString const string = codec->toUnicode(encodedStr);
	return string;
}
