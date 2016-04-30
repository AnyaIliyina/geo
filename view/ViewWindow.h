#pragma once
#include "ui_ViewWindow.h"
#include <qapplication.h>
#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include "TableModel.h"
#include "Item_model.h"
#include "Geodata.h"

/*!
*  \brief  Вывод результатов поиска и работа с ними
*  \author Козырева О.
*  \date   апрель 2016
*/

class ViewWindow : public QMainWindow {
	Q_OBJECT
public:
	/*!
	Конструктор
	*/
	explicit ViewWindow(int session_id, QWidget *parent = 0);

	/*!
	Деструктор
	*/
	~ViewWindow();
		
	/*!
	\param QString whereQryPart- строка запроса к базе
	*/
	 void setupModel();

private:
	ItemModel* m_model=nullptr;
	/*!
	
	*/
	 void createTable();
	
	Ui::ViewWindow *ui;
	
	int m_session_id = -1;
	bool m_editMode = false;
	
private slots:
	/*!
	Слот добавления
	*/
	void slotAdd();
	/*!
	Слот удаления
	*/
	void slotDelete();
	/*
	 Слот редактирования
	 */
	 void slotEdit();
	 /*!
	 Слот применения изменений
	 */
	 void slotSave();
	 /*!
	 Слот отмены изменений
	 */
	 void slotCancel();
	/*!

	*/
	 void slotRefresh();
	 /*
	 
	 */
    void slotEnableButtons(const QItemSelection &, const QItemSelection &);
	void slotEnableButtons();
signals:


	void signalChangeEditMode();
};