#pragma once

#include "Parser.h"
#include <QString>
#include <QObject>
#include <QDebug>


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
class  ParserGisLub : public Parser {
Q_OBJECT
public:
	int parse();
	ParserGisLub(int session_id);
	~ParserGisLub();
private:
	const QString m_url = "http://beryllium.gis-lab.info/project/osmshp";
	int m_session_id;
};
