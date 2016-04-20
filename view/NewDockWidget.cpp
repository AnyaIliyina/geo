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
	
	connect(ui->btnCreate, SIGNAL(clicked()), SLOT(check()));
}

NewDockWidget::NewDockWidget(int session_id, QDockWidget * ptr)
{
	ui = new Ui::NewDockWidget();
	ui->setupUi(this);
	m_session_id = session_id;
	
	connect(ui->btnCreate, SIGNAL(clicked()), SLOT(check()));
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
	Geodata_record* ngdr= new Geodata_record(m_site_id, m_format_id, m_place_name, m_session_id, 1, 2);
	ngdr->insertIntoDatabase();
	int okMsgBox = QMessageBox::information(this, Scale::coded("Успех!"), Scale::coded("Новая запись успешно добавлена"), Scale::coded("Ok"));
	if (okMsgBox == 0)
	{
		ui->btnCancel->click();
	}
	
}

void NewDockWidget::check()
{
	textRead();
	if (emptyLine())
	{
			addMessage();
	}
	else
	{
		ui->lineError->setText(Scale::coded("Заполни первые 4 поля, товарищ!"));
	}
}

void NewDockWidget::addMessage()
{	
	int saveMsgBox = QMessageBox::information(this,
			Scale::coded("Создать новую запись?"), Scale::coded("Новая запись будет создана в базе"),
			Scale::coded("Создать"), Scale::coded("Отмена"));
		if (saveMsgBox == 0)
		{
			addNewRecord();
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
	Site* ns = new Site(m_url, m_site_name);
	int site_id = ns->insertIntoDatabase();
	if (site_id > 0)
		{
			m_site_id = site_id;
			qDebug() << "NewDockWidget m_site_id: " << m_site_id;
			
		}
		else
		{
			m_site_id=Site::site_id(m_url, m_site_name);
			qDebug() << m_site_id;
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
	if ((m_place_name.isEmpty()) || (m_url.isEmpty()) || (m_site_name.isEmpty()) ||(m_format_name.isEmpty()))
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
