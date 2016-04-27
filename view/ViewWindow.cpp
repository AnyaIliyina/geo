#include "ViewWindow.h"
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


//ViewWindow::ViewWindow(QWidget *parent) :QWidget(parent), ui(new Ui::ViewWindow)	
//{
//	ui->setupUi(this);
//	NewDockWidget *ndw = new NewDockWidget();
//	QObject::connect(ui->btnNew, SIGNAL(clicked()), ndw, SLOT(showNDW()));
//	QObject::connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(deleteMessage()));
//	
//}

ViewWindow::ViewWindow(int session_id, QWidget * parent): ui(new Ui::ViewWindow) // ??
{
	m_session_id = session_id;
	ui->setupUi(this);
	NewDockWidget *ndw = new NewDockWidget(m_session_id);
	QObject::connect(ui->action_New, SIGNAL(triggered()), ndw, SLOT(slotShowNDW()));
	QObject::connect(ui->action_Delete, SIGNAL(triggered()), this, SLOT(slotDeleteMessage()));
}

ViewWindow::~ViewWindow()
{
	delete ui;
}

void ViewWindow::setupModel(QString& whereQryPart, const QStringList &headers)
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

void ViewWindow::slotRefresh(QString query)
{
	this->setupModel(query, QStringList() << Scale::coded("id")
		<< Scale::coded("Название сайта")
		<< Scale::coded("Формат")
		<< Scale::coded("Масштаб")
		<< Scale::coded("Статус")
		<< Scale::coded("Название местности")
		<< Scale::coded("Комментарии"));
}


void ViewWindow::createTable()
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

void ViewWindow::slotDeleteMessage()
{
	int  deleteMsgBox = QMessageBox::information(this,
		Scale::coded("Удалить выбранную запись?"), Scale::coded("Выбранная запись будет удалена из базы"),
		Scale::coded("Удалить"), Scale::coded("Отмена"));
	if (deleteMsgBox == 0)
	{
		deleteRecord();
	}
}

void ViewWindow::deleteRecord()
{
	QModelIndex cur = ui->tableView->currentIndex();
	int id = cur.sibling(cur.row(), 0).data().toInt();
	Geodata_record::deleteRecord(id);
	emit signalDeleted();
}