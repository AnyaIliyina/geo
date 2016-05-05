﻿#pragma once
#include "ui_ViewWindow.h"
#include "Item_model.h"
#include "Geodata.h"
#include "SortFilterProxyModel.h"
#include <QApplication>
#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSortFilterProxyModel>

/*!
	 \file
	 \brief  Вывод результатов поиска и работа с ними
	 \author Козырева О.
	 \date   апрель 2016
*/

class ViewWindow : public QMainWindow {
	Q_OBJECT
public:
	/*!
	Конструктор
	*/
	explicit ViewWindow(QWidget *parent = 0);

	/*!
	Деструктор
	*/
	~ViewWindow();
		
	/*!
	\param QString whereQryPart- строка запроса к базе
	*/
	 void setupModel();

private:
	Ui::ViewWindow *ui;
	ItemModel* m_model=nullptr;
	SortFilterProxyModel *filterModel;
	bool m_editMode = false;
	

	/*!
	Метод для установки модели в таблицу и настройки таблицы
	*/
	 void createTable();

	 void setDisabled();
		
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
	 Слот обновления модели
	 */
	 void slotRefresh();
	 /*!
	 Слоты включения/выключения кнопок 
	 */
     void slotEnableButtons(const QItemSelection &, const QItemSelection &);
	 void slotEnableButtons();
	 /*!
	 Слот фильтрации данных в таблице
	 \param QString text - искомая строка
	 */
	 void slotFilterChanged(QString text);

	 /*!
	 Слот открытия ссылки
	 */
	 void slotOpenUrl();
 signals:
	 /*!
	 Сигнал для включения/выключения кнопок
	 */
	 void signalChangeEditMode();

	 /*!
	 Сигнал о том, что данные в модели изменились
	 */
	 void dataChanged();

};