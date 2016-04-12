#include "SM_Session.h"
#include "Parser.h"
#include <QDebug>
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>


/*!
\file
\brief 
*/

const QByteArray * Parser::getReply(const QString & url)
{
	QEventLoop eventLoop;
	QNetworkAccessManager mgr;
	QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	// eventLoop блокирует все действия до тех пор пока ответ QNetworkReply не получен

	QUrl myUrl(url);
	if (!myUrl.isValid())
		qDebug() << "getReply error: URL not valid";
	QNetworkRequest req(myUrl);
	QNetworkReply *reply = mgr.get(req);

	eventLoop.exec();
	const QByteArray *result;
	if (reply->error() == QNetworkReply::NoError) {
		//success
		result = new QByteArray(reply->readAll());
		delete reply;
	}
	else {
		//failure
		result = new QByteArray(nullptr);
		//result = "Failure" + reply->errorString());
		delete reply;
	}
	return result;
}
