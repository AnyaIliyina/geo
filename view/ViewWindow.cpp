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
	Refresh();
	NewDockWidget *ndw = new NewDockWidget(m_session_id);
	QObject::connect(ui->action_New, SIGNAL(triggered()), ndw, SLOT(slotShowNDW()));
	QObject::connect(ui->action_Delete, SIGNAL(triggered()), this, SLOT(slotDeleteMessage()));
}

ViewWindow::~ViewWindow()
{
	delete ui;
}
/*
void ViewWindow::setupModel(const QStringList & headers)
{
	QSqlDatabase db = Database::database();
	model = new QSqlRelationalTableModel(this);
	model->setTable("geodata_records");
	model->setRelation(1, QSqlRelation("sites", "site_id", "site_name"));
	//model->setRelation(2,)
	model->setRelation(3, QSqlRelation("formats", "format_id", "format_name"));
	model->setRelation(4, QSqlRelation("scales", "scale_id", "description"));
	model->setRelation(5, QSqlRelation("states", "state_id", "state_name"));

	for (int i = 0, j = 0;i < model->columnCount(); i++, j++)
	{
		model->setHeaderData(i, Qt::Horizontal, headers[j]);
	}
	model->setSort(0, Qt::AscendingOrder);
	model->select();
}
*/
void ViewWindow::setupModel(const QStringList &headers, QString whereQryPart)
{
	QSqlDatabase db = Database::database();
	model = new TableModel(this);
	
	/*model->setQuery(QString("SELECT geodata_records.record_id, geodata_records.place_name, sites.site_name, formats.format_name, scales.description,\
	 states.state_name, sessions.date, usertypes.type_name, geodata_records.comment \
	FROM sites,sessions, users, formats, usertypes, scales, states, geodata_records\
	 WHERE geodata_records.site_id=sites.site_id AND states.state_id=geodata_records.state_id AND formats.format_id=geodata_records.format_id\
	 AND usertypes.type_id=users.type_id AND users.user_id=sessions.user_id AND geodata_records.session_id=sessions.session_id %1").arg(whereQryPart), db);
	for (int i = 0, j = 0;i < model->columnCount();i++, j++)
	{
		model->setHeaderData(i, Qt::Horizontal, headers[j]);
	}
	model->sort(0, Qt::AscendingOrder);*/
	createTable();

}
void ViewWindow::Refresh()
{
	this->setupModel(QStringList() << Scale::coded("id")
		<< Scale::coded("Название местности")
		<< Scale::coded("Название сайта")
		<< Scale::coded("Формат")
		<< Scale::coded("Масштаб")
		<< Scale::coded("Статус")
		<< Scale::coded("Дата изменения")
		<< Scale::coded("Пользователь")
		<< Scale::coded("Комментарии"));
}

/*void ViewWindow::slotRefresh(QString query)
{
	this->setupModel(query, QStringList() << Scale::coded("id")
		<< Scale::coded("Название местности")
		<< Scale::coded("Название сайта")
		<< Scale::coded("Формат")
		<< Scale::coded("Масштаб")
		<< Scale::coded("Статус")
		<< Scale::coded("Пользователь")
		<< Scale::coded("Комментарии"));
}*/


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