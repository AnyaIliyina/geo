#pragma once
#include <QDockWidget>
#include "ui_NewRecordUser.h"
/*!
\brief
\author �������� �.
\date ������ 2016�.
*/

class NewRecordUser : public QDockWidget {
	Q_OBJECT
private:
	Ui::NewRecordUser *ui;
	QString m_url;
	QString m_site_name;
	int m_site_id;
public:
	/*!
	�����������
	\param QDockWidget *ptr - ��������� �� ������������ ������
	*/
	explicit NewRecordUser(QDockWidget *ptr = 0);
	/*!
	����������
	*/
	~NewRecordUser();
private:
	/*!
	��������� ������ �� �����
	*/
	void textRead();
	/*!
	������� ��������� � �������� ����� ������
	*/
	void addMessage();
	/*!
	
	*/
	void addSite();
	/*!
	�������� �� ���������� �����
	*/
	bool emptyLine();
	private slots:
	/*!
	check
	*/
	void check();
	
	public slots:
	/*!
	���������� ������
	*/
	void showNDW();

};