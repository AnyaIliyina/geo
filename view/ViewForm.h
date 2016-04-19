#pragma once
#include "ui_ViewForm.h"
#include <qapplication.h>
#include <QMainWindow>
#include <QSqlTableModel>

/*!
*  \brief  ����� ����������� ������ � ������ � ����
*  \author �������� �.
*  \date   ������ 2016
*/

class ViewForm : public QWidget {
	Q_OBJECT
public:
	explicit ViewForm(QWidget *parent = 0);
	~ViewForm();

	/*!
	\param QString whereQryPart- ������ ������� � ����
	*/
	void setupModel(QString& whereQryPart);
private:
	void createTable();
	Ui::ViewForm *ui;
	QSqlQueryModel *model;
};