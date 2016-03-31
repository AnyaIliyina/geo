#pragma once

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUrl>
#include <QDateTime>


/*!
*  \brief    Представляет сущность Георесурс
			(таблица Geodata_record в базе)
*  \author   Козырева О.
*  \date     15 март 2016
*/

class Geodata_record {
private:
	int m_record_id;
	int m_site_id;
	int m_session_id;
	int m_format_id;
	int m_scale_id;
	int m_state_id;
	QString m_place_name;
	QString m_comment;
public:
	const QString& place_name() const;
	Geodata_record(int site_id, int session_id, int format_id,
		int scale_id, int state_id, const QString& place_name, const QString& comment = "");
	Geodata_record(int id);
	~Geodata_record();
	int record_id();
	bool insertIntoDatabase();
	static bool createTable();
	static bool completeTable();
};
