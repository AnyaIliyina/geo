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
	emit setStatus(State::coded("Модуль поиска начал работу..."));
	search();
}


/*!
Получает список непроверенных сайтов(со статусом 0);
если возможно, производит поиск ГПИ на этих сайтах
*/
void SM_Session::search()
{
	// получить список сайтов со статусом 1 (нуждающихся в проверке):
	QList<Site> sites = Site::sitesByStatus(1); 

	// создать все возможные парсеры (пока только ParserGisLub):
	ParserGisLub *parserGL = new ParserGisLub();	
	// TODO : ParserGeofabric

	// проверить, есть ли в списке сайтов такие, для которых имеется парсер:
	QString urlGL = parserGL->url();		// url сайта GisLub
	int siteIdGL = 0;
	for (int i = 0; i < sites.count(); i++)
	{
		Site site = sites.at(i);
		if (site.url().contains(urlGL))
					siteIdGL = site.site_id();
	}
	
	// парсить найденные сайты:
	int search_result = -3;
	if (siteIdGL > 0)
		search_result = parserGL->parse(m_session_id, siteIdGL);
	delete parserGL;
	
	// вывести сообщение о результатах поиска в зависимости от search_result
	if((search_result==0)|(siteIdGL==0))
		emit setStatus(State::coded("Модуль поиска: все сайты проверены."));
}


/*!
Отправляет сигнал основному окну с целью поменять 
сообщение панели QStatusBar
\param const QString &text - текст нового сообщения
*/
void SM_Session::setStatus(const QString &text)
{
	emit signalStatusOffered(text);
}
