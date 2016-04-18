#pragma once

#include <QString>
#include <QObject>
#include <QDebug>
#include <QMap>
#include "Session.h"

#define PAGE_NOT_AVAILABLE -2;
#define ERROR_INSERTING_INTO_DB -1;
#define SUCCEEDED 0;
/*!
\file
\brief 
*/

/*!
*  \brief Базовый класс для 
*  \details
*  \author    Ильина А.
*  \date      март 2016
*/
class  Parser : public QObject {
Q_OBJECT
public:
	virtual int parse() = 0;
	const QString& url();
protected:
	QByteArray* getReply();
	void setSessionId(int session_id);
	void setUrl(const QString& url);
	int session_id();
private:
	QString m_url;
	int m_session_id;
};
