#include "Geodata_record.h"
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "Database.h"
#include <QTextCodec>


Geodata_record::Geodata_record(int site_id, int session_id, int format_id, int scale_id, 
	int state_id, const QString& place_name, const QString& comment)
{
	m_record_id = 0;
	m_site_id = site_id;
	m_session_id = session_id;
	m_format_id = format_id;
	m_scale_id = scale_id;
	m_state_id = state_id;
	m_place_name = place_name;
	m_comment = comment;
}

const QString& Geodata_record::place_name() const
{
	return m_place_name;
}

Geodata_record::Geodata_record(int id)
{
	Database::open();
	QSqlTableModel model;
	model.setTable("geodata_records");
	const QString filter = QString("record_id == %1").arg(id);
	model.setFilter(filter);
	model.select();
	QString place_name = model.record(0).value("place_name").toString();
	int site_id = model.record(0).value("site_id").toInt();
	int session_id = model.record(0).value("session_id").toInt();
	int format_id = model.record(0).value("format_id").toInt();
	int scale_id = model.record(0).value("scale_id").toInt();
	int state_id = model.record(0).value("state_id").toInt();
	QString comment = model.record(0).value("comment").toString();
	Database::close();

	m_record_id = id;
	m_site_id = site_id;
	m_session_id = session_id;
	m_format_id = format_id;
	m_scale_id = scale_id;
	m_state_id = state_id;
	m_place_name = place_name;
	m_comment = comment;
}

Geodata_record::~Geodata_record()
{
}

int Geodata_record::record_id()
{
	return m_record_id;
}

bool Geodata_record::insertIntoDatabase()
{
	Database::open();
	QSqlQuery query;
	query.prepare("INSERT INTO geodata_records ( site_id, session_id, format_id, scale_id, state_id, place_name, comment)\
		VALUES (?, ?, ?, ?, ?, ?, ?)");
	query.addBindValue(m_site_id);
	query.addBindValue(m_session_id);
	query.addBindValue(m_format_id);
	query.addBindValue(m_scale_id);
	query.addBindValue(m_state_id);
	query.addBindValue(m_place_name);
	query.addBindValue(m_comment);
	if (!query.exec()) {
		qDebug() << "Geodata_record::insertIntoDatabase():  error inserting into Table geodata_records";
		qDebug() << query.lastError().text();
		Database::close();
		return false;
	}
	Database::close();
	return true;
}

bool Geodata_record::createTable()
{
	Database::open();
	QSqlQuery query;
	if (!query.exec("CREATE TABLE IF NOT EXISTS  geodata_records (\
		record_id  INTEGER         PRIMARY KEY AUTOINCREMENT, \
		site_id INTEGER,		\
		session_id INTEGER,		\
		format_id INTEGER,		\
		scale_id INTEGER,		\
		state_id INTEGER,		\
		place_name     TEXT   NOT NULL,\
		comment TEXT,   \
		FOREIGN KEY(site_id) REFERENCES sites(site_id),\
		FOREIGN KEY(session_id) REFERENCES sessions(session_id),\
		FOREIGN KEY(format_id) REFERENCES formats(format_id),\
		FOREIGN KEY(scale_id) REFERENCES scales(scale_id),\
		FOREIGN KEY(state_id) REFERENCES states(state_id)\
		 )"
		))
	{
		qDebug() << "error creating geodata_records Table in database.";
		qDebug() << query.lastError().text();
		Database::close();
		return false;
	}
	Database::close();
	return true;

}

bool Geodata_record::completeTable()
{
	Geodata_record *gdr = new Geodata_record(1,1,1,1,1, "Ekaterinburg","ohoho");
	Database::open();
	bool succeeded = gdr->insertIntoDatabase();
	Database::close();
	return succeeded;
}


