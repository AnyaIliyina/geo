#include "SM_Session.h"
#include "Database.h"
#include "QStatusBar"
#include "State.h"
#include "Session.h"
#include "ParserGisLub.h"
#include "ParserGeofabrik.h"
#include "Geodata_record.h"
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
	Session::createSMsession();
	emit setStatus(State::coded("Модуль поиска начал работу..."));
	search();
}


/*!
Получает список непроверенных сайтов(со статусом 0);
Если возможно, производит поиск ГПИ на этих сайтах
*/
void SM_Session::search()
{
	// получить список сайтов со статусом 1 (нуждающихся в проверке):
	QList<Site> sites = Site::sitesByStatus(1); 

	// создать все возможные парсеры:
	ParserGisLub *parserGL = new ParserGisLub();	
	ParserGeofabrik *parserGeofabrik = new ParserGeofabrik();

	// Если для сайта есть парсер, вызвать parse(int, int), удалить стрые записи.
	int resultGeofabrik; int resultGL;
	for (int s = 0; s < sites.count(); s++)
	{	
		Site site = sites.at(s);
		if (site.url().contains(parserGL->url()))
		{
				resultGL = parserGL->parse(site.site_id());
				if (resultGL == 0)
					Geodata_record::deleteOldSmRecords(site.site_id());				
		}
		
		if (site.url().contains(parserGeofabrik->url()))
		{
			resultGeofabrik = parserGeofabrik->parse(site.site_id());
			if (resultGeofabrik == 0)
				Geodata_record::deleteOldSmRecords(site.site_id());
		}
	}

	delete parserGL;
	delete parserGeofabrik;
	
	// вывести сообщение о результатах поиска в зависимости от search_result
	if (resultGL==0 && resultGeofabrik==0)
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
