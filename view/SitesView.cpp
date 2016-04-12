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
	QObject::connect(ui->btnSearch, SIGNAL(clicked()), this, SLOT(setupModel()));//QStringList() << ("URL") << State::coded("Название сайта"))));
	//this->setupModel( QStringList() << ("URL")<< State::coded("Название сайта"));
	//this->createUi();
}

SitesView::~SitesView()
{
	delete ui;
}

void SitesView::setupModel()// const QStringList & headers)
{
	QSqlDatabase db = Database::database();
	model = new QSqlQueryModel(this);
	model->setQuery(QString("SELECT site_name, url FROM sites WHERE site_id in (select site_id from geodata_records WHERE place_name='%1')").arg(ui->textGeo->text()));
	
	/*for (int i = 0, j = 0; i < model->columnCount(); i++, j++)
	{
		model->setHeaderData(i, Qt::Horizontal, headers[j]);
	}*/
	createUi();

}

void SitesView::createUi()
{
	ui->tableView->setModel(model);
	//ui->tableView->setColumnHidden(0, true);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	
}

/*void SitesView::searchButton()
{
	QObject::connect(ui->btnSearch, SIGNAL(clicked()), this, SLOT(setupModel(QStringList() << ("URL") << State::coded("Название сайта"))));
	
}*/
