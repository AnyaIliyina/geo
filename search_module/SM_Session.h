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
	Получает список непроверенных сайтов(со статусом 0); 
	если возможно, производит поиск ГПИ на этих сайтах
	*/
	void search();

	/*!
	Отправляет сигнал основному окну с целью поменять
	сообщение панели QStatusBar
	\param const QString &text - текст нового сообщения
	*/
	void setStatus(const QString &text);

signals:
	void signalStatusOffered(const QString &text);
};
