#include "Scale.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "Database.h"
#include <QTextCodec>

/*!
\file
\brief
*/

QString Scale::description()
{
	return m_description;
}

/*!
Конструирует объект класса Scale из параметров
*/
Scale::Scale(QString description)
{
	m_description = description;
	m_scale_id = 0;
}

/*!
Конструирует объект класса Scale из данных в базе
\param int id - id сайта в базе
*/
Scale::Scale(int id)
{
	Database::open();
	QSqlTableModel model;
	model.setTable("scales");
	const QString filter = QString("scate_id == %1");
	model.setFilter(filter);
	model.select();
	QString description = model.record(0).value("description").toString();
	Database::close();

	m_scale_id = id;
	m_description = description;
}

Scale::~Scale()
{
}

int Scale::scale_id()
{
	return m_scale_id;
}

/*!
Записывает информацию о масштабе в базу данных.
\return true - если запись в БД успешно добавлена
*/
bool Scale::insertIntoDatabase()
{
	Database::open();
	QSqlQuery query;
	query.prepare("INSERT INTO scales(description)\
	VALUES (?)");
	query.addBindValue(m_description);
	if (!query.exec()) {
		qDebug() << "Scale::insertIntoDatabase(): error inserting into Table scales";
		qDebug() << query.lastError().text();
		Database::close();
		return false;
	}
	Database::close();
	return true;
}

/*!
Создает таблицу "scales" в базе данных.
\return true - если таблица успешно создана
*/
bool Scale::createTable()
{
	Database::open();
	QSqlQuery query;
	if (!query.exec("CREATE TABLE IF NOT EXISTS scales (\
		scale_id INTEGER PRIMARY KEY AUTOINCREMENT, \
		description TEXT UNIQUE NOT NULL\
		)"
		))
	{
		qDebug() << "error creating scales Table in database";
		qDebug() << query.lastError().text();
		Database::close();
		return false;
	}
	Database::close();
	return true;
}

QString Scale::coded(QByteArray encodedStr) // метод для получения строки в кодировке Unicode 
{ // из QByteArray с кодировкой Windows-1251 
	QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
	// QTextCodec *codec2 = QTextCodec::codecForName("UTF-8"); 
	QString const string = codec->toUnicode(encodedStr);
	return string;
}


/*!
Заполняет таблицу "scales" в БД начальными значениями.
\return true - если таблица успешно заполнена
*/
bool Scale::completeTable()
{
	Scale *s = new Scale("500:1");

	Database::open();
	bool succeeded = s->insertIntoDatabase();
	Database::close();
	return succeeded;
}
