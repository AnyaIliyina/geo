#include "ParserGeofabrik.h"
#include "Geodata_record.h"
#include <QTextEdit>
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

int ParserGeofabrik::parse(int site_id)
{
	m_pages.push("http://download.geofabrik.de/south-america.html");
	//m_pages.push(url());
	//m_pages.push("http://download.geofabrik.de/europe.html");
	Geodata_record *record = new Geodata_record();
	record->setSessionId(m_session_id);
	record->setSiteId(site_id);
	record->setStateId(stateID_actual);
	/*QByteArray *replyIndex = getReply(m_pages.pop());
	separateTable(*replyIndex);
	parseTable(*replyIndex, record, true);*/

	while (!m_pages.isEmpty())
	{
		QString currentPage = m_pages.pop();
		m_currUrl = currentPage.left(currentPage.lastIndexOf('.'));
		qDebug() << "m_currUrl = " << m_currUrl;
		QByteArray *reply = getReply(currentPage);
		qDebug() << "\ngoing to " << currentPage;
		if (*reply == "")
		{
			qDebug() << "wrong adress(";
			return PAGE_NOT_AVAILABLE;
		}
		if (!separateTable(*reply))
		{
			qDebug() << "table not separated, move on";
			continue;
		}
		if(parseTable(*reply, record)==-1)
			return ERROR_INSERTING_INTO_DB;
	}
	Site::setStatusId(site_id, statusId_checked);
	return SUCCEEDED;
}


ParserGeofabrik::ParserGeofabrik()
{
	setUrl("http://download.geofabrik.de/index.html");
}


int ParserGeofabrik::parseTable(QByteArray &content, Geodata_record* record, bool isIndex)
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
						qDebug() << "temp before: " << temp;
						temp = xml.attributes().at(0).value().toString();
						qDebug() << "temp after: " << temp;
						qDebug() << m_pages.length();
						if (isIndex)
							record->setUrl(QString("http://download.geofabrik.de").
								append(temp.right(temp.length() - 1)));
						else
							record->setUrl(m_currUrl+temp);
						qDebug() << record->url();
						m_pages.push(record->url());
						qDebug() << m_pages.length();
						
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
							if(!record->insertIntoDatabase())
								return ERROR_INSERTING_INTO_DB;
						}
						break;
					case 2:
						temp = xml.readElementText();
						if (temp != "[missing]") 
						{
							record->setFormateId(formatID_shape);
							if (!record->insertIntoDatabase())
								return ERROR_INSERTING_INTO_DB;
						}
						break;
					case 3:
						temp = xml.readElementText();
						if (temp != "[missing]")
						{
							record->setFormateId(formatID_bz2);
							if (!record->insertIntoDatabase())
								return ERROR_INSERTING_INTO_DB;
						}
						break;
					}
					counter++;
				}
			}
		}
	}
	delete record;
	return SUCCEEDED;
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
	if(ba.indexOf("No sub regions are defined for this region")>-1)
	{
		qDebug() << "no subregions";
		return false;
	}
	//if(ba.indexOf("<p>No sub regions are defined for this region.</p>"))

	const QString splitter1 = QString("<table id=\"subregions\">");
	int pos1 = ba.lastIndexOf(splitter1);

	const QString splitter2 = QString("</table>");
	int pos2 = ba.lastIndexOf(splitter2) + splitter2.length();

	ba = ba.mid(pos1, pos2 - pos1);

	// Удаление кусков, приводящих к ошибкам в чтении xml:
	const QString errorPronePart = QString("&nbsp");
	ba.remove(ba.indexOf(errorPronePart), errorPronePart.length()+1);
	ba.replace("<img src=\"/img/cross.png\">",
		"<a href=\"no\">[missing]</a>");			
	
	return true;
}