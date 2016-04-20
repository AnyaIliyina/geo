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
	int m_session_id = -1;
public:
	/*!
	�����������
	\param QDockWidget *ptr - ��������� �� ������������ ������
	*/
	explicit NewDockWidget(QDockWidget *ptr = 0);

	/*!
	�����������
	\param QDockWidget *ptr - ��������� �� ������������ ������
	*/
	explicit NewDockWidget(int session_id, QDockWidget *ptr = 0);
	
	
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
	/*!
	������� ��������� � �������� ����� ������
	*/
	void addMessage();
private slots:
	

	void check();
public slots:
	/*!
	���������� ������
	*/
	void showNDW();
	
};