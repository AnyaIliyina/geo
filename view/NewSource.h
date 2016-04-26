#pragma once
#include <QDockWidget>
#include "ui_NewSource.h"
/*!
\brief
\author �������� �.
\date ������ 2016�.
*/

class NewSource : public QWidget {
	Q_OBJECT
private:
	Ui::NewSource *ui;
	QString m_url;
	QString m_site_name;
	QString m_comment;
	
public:
	/*!
	�����������
	\param QDockWidget *ptr - ��������� �� ������������ ������
	*/
	explicit NewSource(QWidget *ptr = 0);

	/*!
	����������
	*/
	~NewSource();
private:
	/*!
	��������� ������ �� �����
	*/
	void textRead();
	/*!	
	������� ����� ������ � ������� sites
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
	/*!

	*/
	void slotCheck();
	public slots:
	/*!
	���������� ������
	*/
	void slotShowNS();

};