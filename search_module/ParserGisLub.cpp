#include "ParserGisLub.h"
#include <QDebug>

/*!
\file
\brief 
*/

int ParserGisLub::parse()
{
	const QByteArray *ar = getReply();
	if (*ar == "")
		return PAGE_NOT_AVAILABLE;
}


ParserGisLub::ParserGisLub(int session_id)
{
	setUrl("http://beryllium.gis-lab.info/project/osmshp");
	setSessionId(session_id);
}



ParserGisLub::~ParserGisLub()
{
}
