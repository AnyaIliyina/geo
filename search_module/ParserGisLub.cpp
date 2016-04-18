#include "ParserGisLub.h"
#include <QDebug>
#include <QTextEdit>
#include <QXmlStreamReader>

/*!
\file
\brief 
*/

int ParserGisLub::parse()
{
	QByteArray *reply = getReply();
	if (*reply == "")
		return PAGE_NOT_AVAILABLE;

	separateTableBody(*reply);
	QTextDocument doc(*reply);
	
	QXmlStreamReader xml(*reply);
	QString str;
	//
	//while (!xml.atEnd() )
	//{
	//	QXmlStreamReader::TokenType token = xml.readNext();
	//	//if (token == QXmlStreamReader::StartElement)
	//	{

	if (xml.readNextStartElement()) {
		{
			
			while (xml.readNextStartElement())
			{
				str += xml.name();
				str += "--\n";
				while (xml.readNextStartElement())
				{
					str += xml.name();
					str += "--\n";
					while (xml.readNextStartElement())
					{
						str += xml.name();
						str += "--\n";
						QXmlStreamAttributes attributes = xml.attributes();
						for (int i = 0; i < attributes.count(); i++)
						{
							str += attributes.at(i).name();
							str += ": ";
							str += attributes.at(i).value();
						}
						str += xml.readElementText(QXmlStreamReader::IncludeChildElements);
						
					}
				}
			}
			if (xml.hasError())
			{
				str += xml.errorString();
				str += "\n";
			}
		}
		QTextEdit *txt = new QTextEdit;
		txt->setText(str);
		txt->show();
	}
}


ParserGisLub::ParserGisLub(int session_id)
{
	setUrl("http://beryllium.gis-lab.info/project/osmshp");
	setSessionId(session_id);
}



ParserGisLub::~ParserGisLub()
{
}


void ParserGisLub::separateTableBody(QByteArray& ba)
{
	const QString splitter1 = QString("<tbody>");
	int pos1 = ba.indexOf(splitter1);
	
	const QString splitter2 = QString("</tbody>");
	int pos2 = ba.indexOf(splitter2) + splitter2.length();
	
	ba = ba.mid(pos1, pos2 - pos1);
}