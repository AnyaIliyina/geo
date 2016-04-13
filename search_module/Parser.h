#pragma once

#include <QString>
#include <QObject>
#include <QDebug>
#include <QMap>
#include "Session.h"

/*!
\file
\brief 
*/

/*!
*  \brief
*  \details
*  \author    Ильина А.
*  \date      март 2016
*/
class  Parser : public QObject {
Q_OBJECT
public:
	virtual void parse() = 0;
private:
	virtual const QByteArray* getReply(const QString& url);
};
