#include "ui_SiteView.h"
#include <qapplication.h>
#include <QMainWindow>
#include <QSqlTableModel>

/*class Table :public QDockWidget, public Ui::DockWidget
{
Q_OBJECT

public:
Table(QDockWidget* pwgt = 0) : QDockWidget(pwgt)
{
setupUi(this);

}*/

namespace Ui {
	class SiteView;
}

class  SiteView:public QDockWidget {
	Q_OBJECT
public:
	explicit SiteView(QDockWidget *parent = 0);
	~SiteView();
private:
	Ui::DockWidget *ui;
	QSqlTableModel *model;
private:
	void setupModel(const QStringList &headers);
	void createUi();
};