#include "ViewForm.h"
#include <qapplication.h>
#include <QMainWindow>
#include <QSqlTableModel>
#include "NewDockWidget.h"
#include "Database.h"
#include <QTableView>

ViewForm::ViewForm(QWidget *parent) :QWidget(parent), ui(new Ui::ViewForm)
{
	ui->setupUi(this);
	NewDockWidget *ndw = new NewDockWidget();
	QObject::connect(ui->btnNew, SIGNAL(clicked()), ndw, SLOT(showNDW()));
}

ViewForm::~ViewForm()
{
	delete ui;
}

void ViewForm::setupModel(QString& whereQryPart)
{
	QSqlDatabase db = Database::database();
	model = new QSqlQueryModel(this);
	model->setQuery(QString("SELECT site_name, url FROM sites %1").arg(whereQryPart), db);
	createTable();

}

void ViewForm::refresh(QString query)
{
	this->setupModel(query);
}

void ViewForm::createTable()
{
	ui->tableView->setModel(model);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

}
