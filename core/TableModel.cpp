#include "TableModel.h"
#include "State.h"
#include "Database.h"
#include <QSqlRecord>
#include <QSqlTableModel>

TableModel::TableModel(QObject *parent) :QAbstractTableModel(parent)
{
	QSqlDatabase db = Database::database();
	QSqlTableModel model(nullptr, db);
	model.setTable("geodata_records");
	/*const QString filter = QString("record_id == %1").arg(id);
	model.setFilter(filter);*/
	model.select();
	for (int i = 0; i < model.rowCount(); i++)
	{
		int row = m_geo.count();
		beginInsertRows(QModelIndex(), row, row);
		GeoData g;

		g[PLACE_NAME] = model.record(i).value("place_name").toString();
		g[FORMAT_NAME] = model.record(0).value("format_id").toInt();
		
		m_geo << g;
		endInsertRows();
	}
}


int TableModel::rowCount(const QModelIndex & parent) const
{
	Q_UNUSED(parent);
	return m_geo.count();
}

int TableModel::columnCount(const QModelIndex & parent) const
{
	Q_UNUSED(parent);
	return LAST;
}

QVariant TableModel::data(const QModelIndex & index, int role) const
{
	if (!index.isValid() || m_geo.count() <= index.row() || (role != Qt::DisplayRole&&role != Qt::EditRole))
	{
		return QVariant();
	}
	return m_geo[index.row()][Column(index.column())];
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole)
	{
		return QVariant();
	}
	if (orientation == Qt::Vertical)
	{
		return section;
	}
	switch (section)
	{
	case ID:
		return ("ID");
	case PLACE_NAME:
		return (State::coded("Название местности"));
	case SITE_NAME:
		return (State::coded("Сайт"));
	case FORMAT_NAME:
		return (State::coded("Формат"));
	case DESCRIPTION:
		return (State::coded("Масштаб"));
	case STATE_NAME:
		return (State::coded("Статус"));
	case DATE:
		return (State::coded("Дата"));
	case USER_TYPE:
		return (State::coded("Пользователь"));
	case COMMENT:
		return (State::coded("Комментарии"));
	}
	return QVariant();
}


