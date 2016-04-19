#pragma once
#include "ui_SearchForm.h"
#include <qapplication.h>
#include <QMainWindow>
#include <QSqlTableModel>


namespace Ui {
	class SearchForm;
}

/*!
*  \brief  ����� ��� ������
*  \author �������� �.
*  \date   ������ 2016
*/
class  SearchForm:public QDockWidget {
	Q_OBJECT
public:
	explicit SearchForm(QDockWidget *parent = 0);
	~SearchForm();

	/*!
	����� ��� �������� ������ �������
	\param QList<QString> args - ������, ���������� ������, ��� ����������� �������
	\return QString qry - ������ ������� � ����
	*/
	QString ParseWhereArgs(QList<QString>& args);

	
private:
	Ui::SearchForm *ui;
	
public slots:
	/*!
	���� ��� ���������� ������ �� ��������� ������
	*/
	void WhereQueryPart();

};