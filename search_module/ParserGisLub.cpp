#include "ParserGisLub.h"
#include <QDebug>

/*!
\file
\brief 
*/

int ParserGisLub::parse()
{
	const QByteArray *ar = getReply(m_url);
	if (*ar == "")
		return PAGE_NOT_AVAILABLE;
}


ParserGisLub::ParserGisLub(int session_id)
{
	m_session_id = session_id;
}



ParserGisLub::~ParserGisLub()
{
}
