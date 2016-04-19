#include "SM_Session.h"
#include "Database.h"
#include "QStatusBar"
#include "State.h"
#include "Session.h"
#include "ParserGisLub.h"
#include "Site.h"

/*!
\file
\brief 
*/

SM_Session::SM_Session()
{
}

SM_Session::~SM_Session()
{
}

/*!
Начинает сессию поиска
*/
void SM_Session::start()
{
	Session *session = new Session(1, QDateTime::currentDateTime());
	session->insertIntoDatabase();
	m_session_id = session->session_id();
	delete session;
	search();
	emit newMessage(State::coded("Модуль поиска начал работу..."));
}


/*!
Получает список непроверенных сайтов(со статусом 0);
если возможно, производит поиск ГПИ на этих сайтах
*/
void SM_Session::search()
{
	ParserGisLub *parserGL = new ParserGisLub();
	QString urlGL = parserGL->url();
	QList<Site> sites = Site::sitesByStatus(0); // список сайтов, нуждающихся в проверке 
												//					(со статусом 0)
	int site_GL_id = 0;
	for (int i = 0; i < sites.count(); i++)
	{
		Site s = sites.at(i);
		if (s.url().contains(urlGL))
		{
			site_GL_id = s.site_id();

		}
	}
	if (site_GL_id > 0)
		parserGL->parse(m_session_id, site_GL_id);
}


/*!
Отправляет сигнал основному окну с целью поменять 
сообщение панели QStatusBar
\param const QString &text - текст нового сообщения
*/
void SM_Session::newMessage(const QString &text)
{
	emit newStatusbarText(text);
}
