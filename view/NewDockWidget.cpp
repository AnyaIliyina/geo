#include "NewDockWidget.h"
#include <QSqlQuery>
#include "Database.h"
#include "Site.h"
#include "Geodata_record.h"
#include <QMessageBox>
#include "Scale.h"

NewDockWidget::NewDockWidget(QDockWidget * ptr)
{
	ui = new Ui::NewDockWidget();
	ui->setupUi(this);
	
	connect(ui->btnCreate, SIGNAL(clicked()), SLOT(addMessage()));
}

NewDockWidget::~NewDockWidget()
{
	qDebug() << "newDockWidget destructor";
	delete ui;
}

void NewDockWidget::addNewRecord()
{
	
	
	getSiteId();
	getFormatId();
	qDebug() << m_site_id, m_format_id, m_place_name;
	Geodata_record* ngdr= new Geodata_record(m_site_id, m_format_id, m_place_name);
	ngdr->insertIntoDatabase();
	
}
void NewDockWidget::addMessage()
{	
	textRead();
	if (emptyLine())
	{
		int saveMsgBox = QMessageBox::information(this,
			Scale::coded("Создать новую запись?"), Scale::coded("Новая запись будет создана в базе"),
			Scale::coded("Создать"), Scale::coded("Отмена"));
		if (saveMsgBox == 0)
		{
			addNewRecord();

		}
	}
	else
	{
		ui->lineError->setText(Scale::coded("Заполни хоть первые 3 поля, товарищ!"));
	}
}

void NewDockWidget::getFormatId()
{
	qDebug() << "getting FormatId...";
	 m_format_id = ui->boxFormat->currentIndex();
	qDebug() << "m_formatId = " << m_format_id;
}

void NewDockWidget::getSiteId()
{
	qDebug() << "getting SiteId...";
	if (Site::checkUrl(m_url))
	{
		Site* ns = new Site(m_url, m_site_name);
		int site_id = ns->insertIntoDatabase();
		
		if (site_id > 0)
		{
			m_site_id = site_id;
			qDebug() << "NewDockWidget m_site_id: " << m_site_id;
			
		}
		else
		{
			m_site_id=Site::site_id(m_url);
			qDebug() << m_site_id;
		}
	}
}

void NewDockWidget::textRead()
{
	m_place_name = ui->linePlace->text();
	m_url = ui->lineUrl->text();
	m_site_name = ui->lineSite->text();
	m_format_name = ui->boxFormat->currentText();
}

bool NewDockWidget::emptyLine()
{
	if ((m_place_name.isEmpty()) || (m_url.isEmpty()) || (m_site_name.isEmpty()))
	{
			 return false;
	}
	else
	{
		return true;
	}
}

void NewDockWidget::showNDW()
{
	this->show();
}
