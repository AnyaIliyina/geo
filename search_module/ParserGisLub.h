#pragma once

#include "Parser.h"
#include <QString>
#include <QByteArray>
#include <QObject>
#include <QDebug>


/*!
\file
\brief
*/

/*!
*  \brief Получает и обрабатывает данные с сайта http://beryllium.gis-lab.info/project/osmshp
*  \details Отправляет get-запрос на сайт, ищет в ответе сведенья об источниках ГПИ, формирует
записи Geodata_record.
*  \author    Ильина А.
*  \date     апрель 2016
*/
class  ParserGisLub : public Parser {
	Q_OBJECT
private:
	/*!
	Ищет в исходном тексте таблицу, удаляет текст до начала таблицы и после ее конца
	\param QByteArray& ba - исходный текст
	*/
	void separateTableBody(QByteArray& ba);
public:
	int parse();
	ParserGisLub(int session_id);
	~ParserGisLub();
};
