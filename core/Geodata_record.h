#pragma once

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUrl>
#include <QDateTime>


/*!
*  \brief     
*  \details
*  \author    
*  \version
*  \date     15 март 2016
*  \pre
*  \bug
*  \warning
*  \copyright
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
	QString place_name();
	Geodata_record(int site_id, int session_id, int format_id, int scale_id, int state_id, QString place_name, QString comment = "");
	Geodata_record(int id);
	~Geodata_record();
	int record_id();
	bool insertIntoDatabase();
	static bool createTable();
	static bool completeTable();
	QString static coded(QByteArray encodedStr);
};
