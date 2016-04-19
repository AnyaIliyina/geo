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
	virtual int parse(int session_id, int site_id) = 0;
	const QString& url();
protected:
	QByteArray* getReply();
	void setUrl(const QString& url);
private:
	QString m_url;
};
