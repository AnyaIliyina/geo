#pragma once

#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUrl>
#include <QDateTime>
/*!
\file
*/


/*!
*  \brief    Представляет сущность Георесурс
			(таблица Geodata_records)
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

	/*!
	Возвращает название местности
	\return const QString& place_name - название местности
	*/
	const QString& place_name() const;
	
	/*!
	Конструирует объект класса Geodata_record из параметров
	\param int site_id - id сайта:
	\param int session_id - id сессии;
	\param int format_id - id формата;
	\param int scale_id - id масштаба;
	\param int state_id - id состояния (актуальность);
	\param const QString& place_name - название местности;
	\param const QString& commant - комментарий;
	*/
	Geodata_record(int site_id, int format_id, const QString& place_name,
		int session_id=1, int scale_id=1, int state_id=1,
		const QString& comment = "");
	
	/*!
	Создает Георесурс из данных в базе
	\param int id - id георесурса
	*/
	Geodata_record(int id);
	
	~Geodata_record();
	
	/*!
	Возвращает id георесурса
	\return int record_id - id ресурса
	*/
	int record_id();
	
	/*!
	Записывает геопространственную информацию в базу данных.
	\return true - если запись в БД успешно добавлена
	*/
	bool insertIntoDatabase();
	
	/*!
	Создает таблицу "geodata_records" в базе данных.
	\return true - если таблица успешно создана
	*/
	static bool createTable();
	
	/*!
	Заполняет таблицу "geodata_records" в БД начальными значениями.
	\return true - если таблица успешно заполнена
	*/
	static bool completeTable();
};
