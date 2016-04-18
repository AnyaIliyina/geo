#pragma once

#include "Parser.h"
#include <QString>
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
	const QByteArray& findTheTable(const QByteArray *reply);
public:
	int parse();
	ParserGisLub(int session_id);
	~ParserGisLub();
};
