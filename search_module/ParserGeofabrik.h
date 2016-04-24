#pragma once
/*!
\file
\brief
*/
#include "Parser.h"


/*!
*  \brief Получает и обрабатывает данные с сайта ??
*  \details Отправляет get-запрос на сайт, ищет в ответе сведенья об источниках ГПИ, формирует
записи Geodata_record.
*  \author    Ильина А.
*  \date     апрель 2016
*/

class  ParserGeofabrik : public Parser {
	Q_OBJECT
private:
	/*!
	Ищет в исходном тексте таблицу, удаляет текст до начала таблицы и после ее конца
	\param QByteArray& ba - исходный текст
	*/
	void separateTable(QByteArray& ba);
public:
	int parse(int session_id, int site_id);
	ParserGeofabrik();
	~ParserGeofabrik();
};
