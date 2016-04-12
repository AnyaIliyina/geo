#include "ui_SitesView.h"
#include <qapplication.h>
#include <QMainWindow>
#include <QSqlTableModel>


namespace Ui {
	class SitesView;
}

/*!
*  \brief Выводит содержимое таблицы Sites (временно)
*  \author Козырева О.
*  \date   март 2016
*/
class  SitesView:public QDockWidget {
	Q_OBJECT
public:
	explicit SitesView(QDockWidget *parent = 0);
	~SitesView();
private:
	Ui::SitesView *ui;
	QSqlQueryModel *model;
private:
	
	void createUi();
	//void searchButton();
public slots:
	void setupModel();//const QStringList &headers*/);
};