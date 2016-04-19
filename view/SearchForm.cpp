#include "SearchForm.h"
#include "ui_SearchForm.h"
#include "State.h"
#include <QTableWidget>
#include <QSqlQueryModel>
#include "Database.h"
#include "NewDockWidget.h"
#include "ViewForm.h"
/*!
\file
\brief
*/

SearchForm::SearchForm(QDockWidget *parent) :QDockWidget(parent), ui(new Ui::SearchForm)
{
	ui->setupUi(this);
	QObject::connect(ui->btnSearch, SIGNAL(clicked()), this, SLOT(WhereQueryPart()));
	
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
	QString qry = " WHERE ";
	for (int i = 0;i < args.length();i++)
	{
		qry += args[i];
		if (i != (args.length() - 1))
		{
			qry += " AND ";
		}
	}
	return qry;
}

void SearchForm::WhereQueryPart()
{
	QList<QString> whereArgs;
	if (!ui->textGeo->text().isEmpty())
	{
		whereArgs.push_back(QString("(site_id IN (SELECT site_id FROM geodata_records WHERE place_name='%1'))").arg(ui->textGeo->text()));
	}
	if (!ui->textURL->text().isEmpty())
	{
		whereArgs.push_back(QString("(site_name='%1')").arg(ui->textURL->text()));
	}
	if (!ui->comboBox->currentText().isEmpty())
	{
		whereArgs.push_back(QString("(site_id IN (SELECT site_id FROM geodata_records WHERE format_id in (SELECT format_id FROM formats WHERE format_name='%1')))").arg(ui->comboBox->currentText()));
	}
	QString whereQryPart = ParseWhereArgs(whereArgs);
	ViewForm::setupModel(whereQryPart);

}

