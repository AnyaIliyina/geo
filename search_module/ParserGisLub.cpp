#include "ParserGisLub.h"
#include <QDebug>
#include <QTextEdit>
#include <QXmlStreamReader>
#include "Geodata_record.h"
#include "State.h"

/*!
\file
\brief 
*/

#define stateID_actual 1
#define stateID_notActual 2
#define formatID_shape 1

int ParserGisLub::parse(int session_id, int site_id)
{
	QByteArray *reply = getReply();
	if (*reply == "")
		return PAGE_NOT_AVAILABLE;

	separateTableBody(*reply);
	Geodata_record *record = new Geodata_record();
	int counter = 0;
	QXmlStreamReader xml(*reply);
	while (xml.readNextStartElement())				// в <tbody>
	{
		if (xml.name() == "tr")
			while (xml.readNextStartElement())		// в <tr>
			{
				while (xml.readNextStartElement())	// в <td>
				{
					if (fmod(counter, 4) == 0)
						record->setUrl(QString("http://view-source:beryllium.gis-lab.info").
							append(xml.attributes().at(0).value()));
					QString buffer = xml.readElementText();
					if (fmod(counter, 4) == 0)
						record->setPlacename(buffer.simplified());
					if (fmod(counter - 1, 4) == 0)
					{
						record->setStateId(buffer.contains(State::coded("Не")) ?
							stateID_notActual : stateID_actual);
						record->setFormateId(formatID_shape);
						record->setSiteId(site_id);
						record->setSessionId(session_id);
						qDebug() << record->url();
						if (!record->insertIntoDatabase())
							return ERROR_INSERTING_INTO_DB;
					}
					counter++;
				}
			}
	}
	//TODO: изменить статус сайта - сайт прошел проверку модулем поиска
	delete record;
	return SUCCEEDED;
}



ParserGisLub::ParserGisLub()
{
	setUrl("http://beryllium.gis-lab.info/project/osmshp");
}



ParserGisLub::~ParserGisLub()
{
}



/*!
Ищет в исходном тексте таблицу, удаляет текст до начала таблицы и после ее конца
\param QByteArray& ba - исходный текст
*/
void ParserGisLub::separateTableBody(QByteArray& ba)
{
	const QString splitter1 = QString("<tbody>");
	int pos1 = ba.indexOf(splitter1);
	
	const QString splitter2 = QString("</tbody>");
	int pos2 = ba.indexOf(splitter2) + splitter2.length();
	
	if ((pos1==-1) || (pos2==-1))
		qDebug() << "ParserGisLub :: separateTableBody(QByteArray&) \
error:\n table not found";

	ba = ba.mid(pos1, pos2 - pos1);
}