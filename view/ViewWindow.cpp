#include "ViewWindow.h"
#include "Database.h"
#include "TableModel.h"
#include "Scale.h"
#include "State.h"
#include "Geodata_record.h"
#include "Item_model.h"
#include "Combo_delegate.h"
#include "Site.h"
#include "Format.h"
#include "Session.h"
#include "SearchForm.h"
#include "SortFilterProxyModel.h"
#include <QSortFilterProxyModel>
#include <QApplication>
#include <QMainWindow>
#include <QSqlTableModel>
#include <QTableView>
#include <QMessageBox>


ViewWindow::ViewWindow(QWidget * parent): ui(new Ui::ViewWindow) // ??
{
	ui->setupUi(this);
	setupModel();
	QObject::connect(ui->action_New, SIGNAL(triggered()), this, SLOT(slotAdd()));
	QObject::connect(ui->action_Delete, SIGNAL(triggered()), this, SLOT(slotDelete()));
	QObject::connect(ui->action_Edit, SIGNAL(triggered()), this, SLOT(slotEdit()));
	QObject::connect(ui->action_Yes, SIGNAL(triggered()), this, SLOT(slotSave()));
	QObject::connect(ui->action_No, SIGNAL(triggered()), this, SLOT(slotCancel()));
	QObject::connect(ui->tableView->selectionModel(),SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)) ,this, SLOT(slotEnableButtons(const QItemSelection &, const QItemSelection &)) );
	QObject::connect(this, SIGNAL(signalChangeEditMode()), this, SLOT(slotEnableButtons()));
	
}

ViewWindow::~ViewWindow()
{
	delete ui;
	delete m_model;
}

void ViewWindow::setupModel()
{
	delete m_model;
	QSqlDatabase db = Database::database();
	m_model = new ItemModel();
	createTable();
}
void ViewWindow::slotRefresh()
{
	setupModel();
}

void ViewWindow::slotEnableButtons()
{
	qDebug() << "SLOOOOOOOT";
	if (m_editMode)
	{
		ui->action_Edit->setEnabled(false);
		ui->action_Delete->setEnabled(false);
		ui->action_New->setEnabled(false);
		ui->action_Yes->setEnabled(true);
		ui->action_No->setEnabled(true);
	}
	else
	{
		ui->action_New->setEnabled(true);
		ui->action_Yes->setEnabled(false);
		ui->action_No->setEnabled(false);
		if (ui->tableView->selectionModel()->selectedRows().count() > 1)
		{
			ui->action_Delete->setEnabled(true);
			ui->action_Edit->setEnabled(false);
		}
		if (ui->tableView->selectionModel()->selectedRows().count() == 1)
		{
			ui->action_Delete->setEnabled(true);
			ui->action_Edit->setEnabled(true);
		}
		if (ui->tableView->selectionModel()->selectedRows().count() == 0)
		{
			ui->action_Delete->setEnabled(false);
			ui->action_Edit->setEnabled(false);
		}
	}
}

void ViewWindow::slotFilterChanged(QString text)
{
	QRegExp regExp(text,Qt::CaseInsensitive);
	filterModel->setFilterRegExp(regExp);
}

void ViewWindow::slotEnableButtons(const QItemSelection &, const QItemSelection &)
{
	qDebug() << "SLOOOOOOOT";
	if (m_editMode)
	{
		ui->action_Edit->setEnabled(false);
		ui->action_Delete->setEnabled(false);
		ui->action_New->setEnabled(false);
		ui->action_Yes->setEnabled(true);
		ui->action_No->setEnabled(true);
	}
	else
	{
		ui->action_New->setEnabled(true);
		ui->action_Yes->setEnabled(false);
		ui->action_No->setEnabled(false);
		if (ui->tableView->selectionModel()->selectedRows().count() > 1)
		{
			ui->action_Delete->setEnabled(true);
			ui->action_Edit->setEnabled(false);
		}
		if (ui->tableView->selectionModel()->selectedRows().count() == 1)
		{
			ui->action_Delete->setEnabled(true);
			ui->action_Edit->setEnabled(true);
		}
		if (ui->tableView->selectionModel()->selectedRows().count() ==0)
		{
			ui->action_Delete->setEnabled(false);
			ui->action_Edit->setEnabled(false);
		}
	}
	
}

void ViewWindow::createTable()
{
	m_model->loadData(0);
	filterModel = new SortFilterProxyModel();
	filterModel->setSourceModel(m_model);
	ui->tableView->setModel(filterModel);

	auto comboDelegateSite = new ComboDelegate(Site::getSiteNames(), this);
	ui->tableView->setItemDelegateForColumn(2, comboDelegateSite);

	auto comboDelegateFormat = new ComboDelegate(Format::getFormatNames(), this);
	ui->tableView->setItemDelegateForColumn(3, comboDelegateFormat);

	auto comboDelegateScale = new ComboDelegate(Scale::getDescription(), this);
	ui->tableView->setItemDelegateForColumn(4, comboDelegateScale);

	auto comboDelegateState = new ComboDelegate(State::getStates(), this);
	ui->tableView->setItemDelegateForColumn(5, comboDelegateState);

	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setColumnHidden(0, true);
	ui->tableView->setSortingEnabled(true);
	ui->tableView->resizeColumnsToContents();

}

void ViewWindow::slotAdd()
{
	m_editMode = true;
	emit signalChangeEditMode();
	QModelIndex index;
	auto m_index = filterModel->mapToSource(index);
	m_model->insertRows(0, 1, m_index);
	auto rowCount = m_model->rowCount(m_index);
	qDebug() << "slotAdd rowcount" << rowCount;
	auto child = m_model->index(rowCount - 1, 0, m_index); 
	qDebug() << "slotAdd child"<<child;
	ui->tableView->selectionModel()->setCurrentIndex(child, QItemSelectionModel::SelectCurrent);
	qDebug() << "SLot add child" << child;
	ui->tableView->edit(child);
}

void ViewWindow::slotDelete()
{
	
	int  deleteMsgBox = QMessageBox::question(this, "",
		Scale::coded("Удалить выбранную запись?"),
		QMessageBox::Yes, QMessageBox::No);
	if (deleteMsgBox == QMessageBox::Yes)
	{
		auto index = ui->tableView->selectionModel()->currentIndex();
		auto m_index = filterModel->mapToSource(index);
		qDebug()<<"Slot Delete" << index;
		qDebug() << "Slot Delete" << m_index;
		m_model->removeRows(0, 1, m_index);
	}
}

void ViewWindow::slotEdit()
{
	
	m_editMode = true;
	emit signalChangeEditMode();
	auto index = ui->tableView->selectionModel()->currentIndex();
	qDebug() <<"slotEdit index" <<index;
	auto m_index= filterModel->mapToSource(index);
	qDebug() << "index map" << m_index;
	m_model->startEditMode(m_index);
	ui->tableView->edit(m_index);
}

void ViewWindow::slotSave()
{
	if (m_model->save())
	{
		m_editMode = false;
		emit signalChangeEditMode();
		QMessageBox::information(this, "", Scale::coded("Сохранено"), QMessageBox::Ok);
	}
	else
		QMessageBox::critical(this, "", Scale::coded("Не удалось применить изменения"), QMessageBox::Ok);
	auto index = ui->tableView->selectionModel()->currentIndex();
	auto m_index = filterModel->mapToSource(index);
}

void ViewWindow::slotCancel()
{
	if (m_model->cancel())
	{
		m_editMode = false;
		emit signalChangeEditMode();
	}
	else
		QMessageBox::critical(this, "", Scale::coded("Не удалось отменить изменения"), QMessageBox::Ok);
	auto index = ui->tableView->selectionModel()->currentIndex();
	auto m_index = filterModel->mapToSource(index);
	ui->tableView->reset();
	ui->tableView->selectionModel()->setCurrentIndex(m_index, QItemSelectionModel::Select |
		QItemSelectionModel::Rows);
	
}

