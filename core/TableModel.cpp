#include "TableModel.h"
#include "State.h"

TableModel::TableModel(QObject *parent) :QAbstractTableModel(parent)
{

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
		return (State::coded("�������� ���������"));
	case SITE_NAME:
		return (State::coded("����"));
	case FORMAT_NAME:
		return (State::coded("������"));
	case DESCRIPTION:
		return (State::coded("�������"));
	case STATE_NAME:
		return (State::coded("������"));
	case DATE:
		return (State::coded("����"));
	case USER_TYPE:
		return (State::coded("������������"));
	case COMMENT:
		return (State::coded("�����������"));
	}
	return QVariant();
}


