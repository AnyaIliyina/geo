#include "ViewForm.h"
#include <qapplication.h>
#include <QMainWindow>
#include <QSqlTableModel>
#include "NewDockWidget.h"
#include "Database.h"
#include <QTableView>
#include <QMessageBox>
#include "Scale.h"
#include "Geodata_record.h"
#include <QSortFilterProxyModel>


//ViewForm::ViewForm(QWidget *parent) :QWidget(parent), ui(new Ui::ViewForm)	
//{
//	ui->setupUi(this);
//	NewDockWidget *ndw = new NewDockWidget();
//	QObject::connect(ui->btnNew, SIGNAL(clicked()), ndw, SLOT(showNDW()));
//	QObject::connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(deleteMessage()));
//	
//}

ViewForm::ViewForm(int session_id, QWidget * parent): ui(new Ui::ViewForm) // ??
{
	m_session_id = session_id;
	ui->setupUi(this);
	NewDockWidget *ndw = new NewDockWidget(m_session_id);
	QObject::connect(ui->btnNew, SIGNAL(clicked()), ndw, SLOT(showNDW()));
	QObject::connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(deleteMessage()));
}

ViewForm::~ViewForm()
{
	delete ui;
}

void ViewForm::setupModel(QString& whereQryPart, const QStringList &headers)
{
	QSqlDatabase db = Database::database();
	model = new QSqlQueryModel(this);
	
	model->setQuery(QString("SELECT geodata_records.record_id, sites.site_name, formats.format_name, scales.description, states.state_name, geodata_records.place_name, geodata_records.comment\
		FROM sites, formats, scales, states, geodata_records WHERE geodata_records.site_id=sites.site_id AND states.state_id=geodata_records.state_id\
		AND formats.format_id=geodata_records.format_id %1").arg(whereQryPart), db);
	for (int i = 0, j = 0;i < model->columnCount();i++, j++)
	{
		model->setHeaderData(i, Qt::Horizontal, headers[j]);
	}
	
	
	createTable();

}

void ViewForm::refresh(QString query)
{
	this->setupModel(query, QStringList() << Scale::coded("id")
		<< Scale::coded("Название сайта")
		<< Scale::coded("Формат")
		<< Scale::coded("Масштаб")
		<< Scale::coded("Статус")
		<< Scale::coded("Название местности")
		<< Scale::coded("Комментарии"));
}


void ViewForm::createTable()
{
	QSortFilterProxyModel *filterModel = new QSortFilterProxyModel();
	filterModel->setSourceModel(model);
	ui->tableView->setModel(filterModel);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableView->setColumnHidden(0, true);
	ui->tableView->setSortingEnabled(true);

	//ui->tableView->resizeColumnsToContents();

}

void ViewForm::deleteMessage()
{
	int  deleteMsgBox = QMessageBox::information(this,
		Scale::coded("Удалить выбранную запись?"), Scale::coded("Выбранная запись будет удалена из базы"),
		Scale::coded("Удалить"), Scale::coded("Отмена"));
	if (deleteMsgBox == 0)
	{
		deleteRecord();
	}
}

void ViewForm::deleteRecord()
{
	QModelIndex cur = ui->tableView->currentIndex();
	int id = cur.sibling(cur.row(), 0).data().toInt();
	Geodata_record::deleteRecord(id);
	emit del();
}