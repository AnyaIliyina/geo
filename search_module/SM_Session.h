#pragma once

#include <QString>
#include <QObject>
#include <QDebug>
#include <QUrl>
#include <QDateTime>

/*!
\file
\brief 
*/

/*! 
 *  \brief     Создает сессию для модуля поиска, запускает его работу.
 *  \details   Search Module session
 *  \author    Ильина А.
 *  \date      март 2016
 */

class SM_Session : public QObject {
Q_OBJECT
public:
	SM_Session();
	~SM_Session();
	
	/*!	Начинает сессию поиска	*/
	void start();

private:
	int m_session_id = -1;		// id сессии поиска

	/*!
	Отправляет сигнал основному окну с целью поменять
	сообщение панели QStatusBar
	\param const QString &text - текст нового сообщения
	*/
	void newMessage(const QString &text);

signals:
	void newStatusbarText(const QString &text);
};
