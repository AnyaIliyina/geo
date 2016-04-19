#include "ParserGisLub.h"
#include <QDebug>
#include <QTextEdit>
#include <QXmlStreamReader>

#include <QBuffer>

/*!
\file
\brief 
*/

int ParserGisLub::parse(int session_id, int site_id)
{
	QByteArray *reply = getReply();
	if (*reply == "")
		return PAGE_NOT_AVAILABLE;

	separateTableBody(*reply);
	
	QXmlStreamReader xml(*reply);
	QString str;
	QList<QVariant> record_fields(QString placename, int state = 1);
		if (xml.readNextStartElement()) {
		{
			if(xml.name() == "tbody")
				while (xml.readNextStartElement())
			{
				if (xml.name() == "tr")
				while (xml.readNextStartElement())
				{
					if (xml.name() == "td") {
						str += "\n       ";
						str += xml.name();
					}
					
					while (xml.readNextStartElement())
					{
						str += "\n            ";
						str += xml.name();
						QXmlStreamAttributes attributes = xml.attributes();
						for (int i = 0; i < attributes.count(); i++)
						{
							str += "\n";
							str += attributes.at(i).name();
							str += ": ";
							str += attributes.at(i).value();
						}
						str += xml.readElementText();
					}

				}
			}
			
		}
		QTextEdit *txt = new QTextEdit;
		txt->setText(str);
		txt->show();
	}
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