#include "TableModel.h"
#include "State.h"
#include "Database.h"
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QSqlError>

TableModel::TableModel(QObject *parent) :QAbstractTableModel(parent)
{
	QSqlDatabase db = Database::database();
	QSqlQuery q = QSqlQuery(db);
	q.setForwardOnly(true);
	q.prepare("SELECT geodata_records.record_id, geodata_records.place_name, sites.site_name, formats.format_name, scales.description, \
		states.state_name, sessions.date, usertypes.type_name, geodata_records.comment \
		FROM sites, sessions, users, formats, usertypes, scales, states, geodata_records\
		WHERE geodata_records.site_id = sites.site_id AND states.state_id = geodata_records.state_id AND formats.format_id = geodata_records.format_id\
		AND usertypes.type_id = users.type_id AND users.user_id = sessions.user_id AND geodata_records.session_id = sessions.session_id");
	if (!q.exec())
	{
		qDebug() << q.lastError().text();
		db.close();
	}
	while (q.next())
	{
		int row = m_geo.count();
		beginInsertRows(QModelIndex(), row, row);
		GeoData g;
		g[ID] = q.value(0).toInt();
		g[PLACE_NAME] = q.value(1).toString();
		g[SITE_NAME] = q.value(2).toString();
		g[FORMAT_NAME] = q.value(3).toString();
		g[DESCRIPTION] = q.value(4).toString();
		g[STATE_NAME] = q.value(5).toString();
		g[DATE] = q.value(6).toString();
		g[USER_TYPE] = q.value(7).toString();
		g[COMMENT] = q.value(8).toString();
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


