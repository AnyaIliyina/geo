#include "SM_Session.h"
#include "Database.h"
#include "QStatusBar"
#include "State.h"
#include "Session.h"

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
	Session *s = new Session(1, QDateTime::currentDateTime());
	s->insertIntoDatabase();
	emit newMessage(State::coded("Модуль поиска начал работу..."));
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