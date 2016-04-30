#include "ParserGeofabrik.h"
#include "Geodata_record.h"
#include <QTextEdit>
#include <QStack>
#include <QXmlStreamReader>

/*!
\file
\brief 
*/

#define formatID_pbf 2
#define formatID_shape 1
#define formatID_bz2 3
#define stateID_actual 2
#define statusId_checked 2

int ParserGeofabrik::parse(int session_id, int site_id)
{
	QStack <QString>pages;
	pages.push(url());
	Geodata_record *record = new Geodata_record();
	record->setSessionId(session_id);
	record->setSiteId(site_id);
	record->setStateId(stateID_actual);
	while (!pages.isEmpty())
	{
		QByteArray *reply = getReply(pages.pop());
		if (*reply == "")
			return PAGE_NOT_AVAILABLE;
		if (!separateTable(*reply))
			continue;
		parseTable(*reply, pages, record);
	}
	Site::setStatusId(site_id, statusId_checked);
	return SUCCEEDED;
}


ParserGeofabrik::ParserGeofabrik()
{
	setUrl("http://download.geofabrik.de/index.html");
}


void ParserGeofabrik::parseTable(QByteArray &content, QStack<QString> pages, Geodata_record* record)
{ // TODO: передать QStack<QString> pages по ссылке
	QXmlStreamReader xml(content);
	int counter = 0;
	QString temp;
	while (xml.readNextStartElement())			// в <table>	
	{
		while (xml.readNextStartElement())		// в <tr>
		{
			while (xml.readNextStartElement())	// в <td>
			{
				while (xml.readNextStartElement())	// в <a>
				{
					if (fmod(counter, 4) == 0)
					{
						temp = xml.attributes().at(0).value().toString();
						record->setUrl(QString("http://download.geofabrik.de").append(temp.right(temp.length() - 1)));
						pages.push(record->url());
						qDebug() << record->url();
					//	temp.clear();
					}
					int columnNumber = fmod(counter, 4);
					switch (columnNumber)
					{
					case 0:
						record->setPlacename(xml.readElementText()); break;
					case 1:
						temp = xml.readElementText();
						if (temp != "[missing]")
						{
							record->setFormateId(formatID_pbf);
							record->insertIntoDatabase();
						}
						break;
					case 2:
						temp = xml.readElementText();
						if (temp != "[missing]")
						{
							record->setFormateId(formatID_shape);
							record->insertIntoDatabase();
						}
						break;
					case 3:
						temp = xml.readElementText();
						if (temp != "[missing]")
						{
							record->setFormateId(formatID_bz2);
							record->insertIntoDatabase();
						}
						break;
					}
					counter++;
				}
			}
		}
	}
	delete record;
}


QStringRef ParserGeofabrik::translate(const QString & text)
{
	return QStringRef();
}



ParserGeofabrik::~ParserGeofabrik()
{
}


bool ParserGeofabrik::separateTable(QByteArray& ba)
{
	const QString splitter1 = QString("<table id=\"subregions\">");
	int pos1 = ba.indexOf(splitter1);

	const QString splitter2 = QString("</table>");
	int pos2 = ba.indexOf(splitter2) + splitter2.length();

	if ((pos1 == -1) || (pos2 == -1))				// таблица не найдена
		return false;

	ba = ba.mid(pos1, pos2 - pos1);

	// Удаление кусков, приводящих к ошибкам в чтении xml:
	const QString errorPronePart = QString("&nbsp");
	ba.remove(ba.indexOf(errorPronePart), errorPronePart.length()+1);
	ba.replace("<img src=\"/img/cross.png\">",
		"<a href=\"no\">[missing]</a>");			

	return true;
}