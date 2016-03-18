#include "SiteView.h"
#include "ui_SiteView.h"

SiteView::SiteView(QDockWidget *parent) :
	QDockWidget(parent),
	ui(new Ui::DockWidget)
{
	ui->setupUi(this);
	this->setupModel( QStringList() <<trUtf8("id")
		<< trUtf8("URL")
		<< trUtf8("Название сайта")
		<< trUtf8("Статус")
		<< trUtf8("Комментарии"));
	this->createUi();
}

SiteView::~SiteView()
{
	delete ui;
}

void SiteView::setupModel( const QStringList & headers)
{
	model = new QSqlTableModel(this);
	model->setTable("sites");
	for (int i = 0, j = 0; i < model->columnCount(); i++, j++)
	{
		model->setHeaderData(i, Qt::Horizontal, headers[j]);
	}

}

void SiteView::createUi()
{
	ui->SitesTblView->setModel(model);
	ui->SitesTblView->setColumnHidden(0, true);
	ui->SitesTblView->horizontalHeader()->setStretchLastSection(true);
	
	model->select();
}