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
	delete ui;
}

void NewDockWidget::addNewRecord()
{
	
	textRead();
	getSiteId();
	getFormatId();
	Geodata_record* ngdr= new Geodata_record(m_site_id, m_format_id, m_place_name);
	ngdr->insertIntoDatabase();
	
}
void NewDockWidget::addMessage()
{
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
	int m_format_id = ui->boxFormat->currentIndex();
	
}

void NewDockWidget::getSiteId()
{
	if (Site::checkUrl(m_url))
	{
		Site* ns = new Site(m_url, m_site_name);
		int site_id = ns->insertIntoDatabase();
		
		if (!site_id == -1)
		{
			m_site_id = site_id;
			
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
	if ((m_place_name == "") || (m_url == "") || (m_site_name == ""))
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
