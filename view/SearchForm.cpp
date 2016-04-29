#include "SearchForm.h"
#include "ui_SearchForm.h"
#include "State.h"
#include <QTableWidget>
#include <QSqlQueryModel>
#include "Database.h"
#include "Format.h"
#include <QLineEdit>
/*!
\file
\brief
*/

SearchForm::SearchForm(QDockWidget *parent) :ui(new Ui::SearchForm)
{
	ui->setupUi(this);
	ui->comboBox->addItems(Format::getFormatNames());
	//QObject::connect(ui->textGeo, SIGNAL(QLineEdit::textEdited()), this, SLOT(slotCreateQuery()));
	
}

SearchForm::~SearchForm()
{
	delete ui;
}

QString SearchForm::ParseWhereArgs(QList<QString>& args)
{
	if (args.length() == 0)
	{
		return QString();
	}
	QString qry = " AND ";
	for (int i = 0;i < args.length();i++)
	{
		
		qry += args[i];
		if (i != (args.length() - 1))
		{
			qry += " AND ";

		}
		
	}
	qDebug() << qry;
	return qry;
}
void SearchForm::slotCreateQuery()
{
	QList<QString> whereArgs;
	if (!ui->textGeo->text().isEmpty())
	{
		whereArgs.push_back(QString("(place_name='%1')").arg(ui->textGeo->text()));
	}
	if (!ui->textURL->text().isEmpty())
	{
		whereArgs.push_back(QString("(sites.site_id=geodata_records.site_id in (SELECT site_id FROM sites WHERE site_name='%1'))").arg(ui->textURL->text()));
	}
	if (!ui->comboBox->currentText().isEmpty())
	{
		whereArgs.push_back(QString("(formats.format_id=geodata_records.format_id in  (SELECT format_id FROM formats WHERE  format_name='%1'))").arg(ui->comboBox->currentText()));
	}
	QString whereQryPart = ParseWhereArgs(whereArgs);
	qDebug() << whereQryPart;
	emit signalQueryCreated(whereQryPart);
}

