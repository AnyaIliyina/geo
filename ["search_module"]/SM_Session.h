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
 *  \brief     Класс SM_Session (Search Module session)
 *  \details  Служит для поиска информации о ГПИ в интернете.
 *  \author    Ильина А.
 *  \date      март 2016
 */

class SM_Session : public QObject {
Q_OBJECT
public:
	SM_Session();
	~SM_Session();
	void start();
private:
	void newMessage(const QString &text);
signals:
	void newStatusbarText(const QString &text);
};