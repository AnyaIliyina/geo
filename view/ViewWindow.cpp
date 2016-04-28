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
#include "TableModel.h"

ViewWindow::ViewWindow(int session_id, QWidget * parent): ui(new Ui::ViewWindow) // ??
{
	m_session_id = session_id;
	ui->setupUi(this);
	//Refresh();
	setupModel();
	NewDockWidget *ndw = new NewDockWidget(m_session_id);
	QObject::connect(ui->action_New, SIGNAL(triggered()), ndw, SLOT(slotShowNDW()));
	QObject::connect(ui->action_Delete, SIGNAL(triggered()), this, SLOT(slotDeleteMessage()));
	QObject::connect(ndw, SIGNAL(signalAdded()), this, SLOT(slotRefresh()));
	QObject::connect(this, SIGNAL(signalDeleted()), this, SLOT(slotRefresh()));
}

ViewWindow::~ViewWindow()
{
	delete ui;
}

void ViewWindow::setupModel()
{
	QSqlDatabase db = Database::database();
	model = new TableModel(this);
	createTable();

}
void ViewWindow::slotRefresh()
{
	setupModel();
}

void ViewWindow::createTable()
{
	QSortFilterProxyModel *filterModel = new QSortFilterProxyModel();
	filterModel->setSourceModel(model);
	ui->tableView->setModel(filterModel);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableView->setColumnHidden(0, true);
	ui->tableView->setColumnHidden(6, true);
	ui->tableView->setSortingEnabled(true);
	ui->tableView->resizeColumnsToContents();

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