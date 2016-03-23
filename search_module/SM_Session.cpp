#include "SM_Session.h"
#include "Database.h"
#include "QStatusBar"

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
Отправляет сигнал основному окну с целью поменять 
сообщение панели QStatusBar
\param const QString &text - текст нового сообщения
*/
//void SM_Session::newMessage(const QString &text)
//{
//	emit newStatusbarText(text);
//}