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

public:
	/*!
	Отправляет get-запрос на сайт, ищет в ответе сведенья об источниках ГПИ, формирует и заносит в БД
	записи Geodata_record.
	\param session_id - id сессии поиска;
	\param site_id - id сайта gis-lab.info;
	\return 0 - без ошибок;
	\return -2 - страница недоступна;
	*/
	int parse(int session_id, int site_id);
	ParserGeofabrik();
	~ParserGeofabrik();
private:
	/*!
	Ищет в исходном тексте таблицу, удаляет текст до начала таблицы и после ее конца.
	\param QByteArray& ba - исходный текст
	*/
	bool separateTable(QByteArray& content);

	/*!
	Просматривает содержимое таблицы. По мере нахождения заносит в
	запись Geodata_record информацию об актуальности, названии местности и адресе.
	Сохраняет полученную запись в БД. Адреса добавляет в стек pages.
	\param QByteArray& content - содержимое таблицы;
	\param QStack<QString>& pages - стек;
	\param Geodata_record* record - запись;*/
	void parseTable(QByteArray& content, QStack<QString> pages, Geodata_record* record);

	QStringRef translate(const QString& text);
};
