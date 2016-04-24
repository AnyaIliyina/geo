#include "ParserGeofabrik.h"
#include <QTextEdit>

/*!
\file
\brief 
*/


int ParserGeofabrik::parse(int session_id, int site_id)
{
	QByteArray *reply = getReply();
	if (*reply == "")
		return PAGE_NOT_AVAILABLE;
	//separateTable(*reply);
	QTextEdit *txt = new QTextEdit();
	QTextDocument doc(*reply);
	txt->setText(*reply);
	txt->show();
}

ParserGeofabrik::ParserGeofabrik()
{
	setUrl("http://translate.google.com/translate?hl=&sl=auto&tl=ru&u=http%3A%2F%2Fdownload.geofabrik.de%2Findex.html&sandbox=1");
}


ParserGeofabrik::~ParserGeofabrik()
{
}


void ParserGeofabrik::separateTable(QByteArray& ba)
{
	const QString splitter1 = QString("<table id=\"subregions\">");
	int pos1 = ba.indexOf(splitter1);

	const QString splitter2 = QString("</table>");
	int pos2 = ba.indexOf(splitter2) + splitter2.length();

	if ((pos1 == -1) || (pos2 == -1))
		qDebug() << " ParserGeofabrik :: separateTable(QByteArray&) \
error:\n table not found";

	ba = ba.mid(pos1, pos2 - pos1);

}