#pragma once
#include <QDockWidget>
#include "ui_NewDockWidget.h"
/*!
\brief 
\author �������� �.
\date ������ 2016�.
*/

class NewDockWidget : public QDockWidget {
	Q_OBJECT
private:
	Ui::NewDockWidget *ui;
	QString m_place_name;
	QString m_url;
	QString m_site_name;
	QString m_format_name;
	int m_format_id;
	int m_site_id;
public:
	/*!
	�����������
	\param QDockWidget *ptr - ��������� �� ������������ ������
	*/
	explicit NewDockWidget(QDockWidget *ptr = 0);
	/*!
	����������
	*/
	~NewDockWidget();
private:
	/*!
	��������� ������ �� �����
	*/
	void textRead();
	/*!
	�������� id �����
	*/
	void getSiteId();
	/*!
	�������� id �������
	*/
	void getFormatId();
	/*!
	������� ����� ������ � ������� geodata_records
	*/
	void addNewRecord();
	/*!
	�������� �� ���������� �����
	*/
	bool emptyLine();
private slots:
	/*!
	������� ��������� � �������� ����� ������
	*/
	void addMessage();
public slots:
	/*!
	���������� ������
	*/
	void showNDW();
	
};