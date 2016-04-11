#include "SitesView.h"
#include "ui_SitesView.h"
#include "State.h"
#include <QTableWidget>
#include <QSqlQueryModel>
#include "Database.h"
/*!
\file
\brief Временный класс для вывода содержимого таблицы Sites
*/

SitesView::SitesView(QDockWidget *parent) :
	QDockWidget(parent),
	ui(new Ui::SitesView)
{
	ui->setupUi(this);
	this->setupModel( QStringList() 
		<< ("URL")
		<< State::coded("Название сайта"));
	this->createUi();
}

SitesView::~SitesView()
{
	delete ui;
}

void SitesView::setupModel( const QStringList & headers)
{
	Database::open();
	model = new QSqlQueryModel(this);
	model->setQuery("SELECT site_name, url FROM sites WHERE site_id in (select site_id from geodata_records WHERE place_name='Ekaterinburg')");
	for (int i = 0, j = 0; i < model->columnCount(); i++, j++)
	{
		model->setHeaderData(i, Qt::Horizontal, headers[j]);
	}

}

void SitesView::createUi()
{
	ui->tableView->setModel(model);
	//ui->tableView->setColumnHidden(0, true);
	
	
}