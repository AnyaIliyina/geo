#include "NewRecordUser.h"
#include <QSqlQuery>
#include "Database.h"
#include "Site.h"
#include <QMessageBox>
#include "Scale.h"

NewRecordUser::NewRecordUser(QDockWidget * ptr)
{
	ui = new Ui::NewRecordUser();
	ui->setupUi(this);

	connect(ui->btnCreate, SIGNAL(clicked()), SLOT(check()));
}

NewRecordUser::~NewRecordUser()
{
	qDebug() << "newrecorduser destructor";
	delete ui;
}

void NewRecordUser::check()
{
	textRead();
	if (emptyLine())
	{
		if (Site::checkUrl(m_url))
		{
			addMessage();
		}
		else 
		{
			ui->lineError->setText(Scale::coded("URL �� ��������."));
		}
	}
	else
	{
		ui->lineError->setText(Scale::coded("������� ��� ����, �������!"));
	}
}
void NewRecordUser::addMessage()
{
	int saveMsgBox = QMessageBox::information(this,
	Scale::coded("������� ����� ������?"), Scale::coded("����� ������ ����� ������� � ����"),
	Scale::coded("�������"), Scale::coded("������"));
	if (saveMsgBox == 0)
	{
	addSite();
	}

}

void NewRecordUser::addSite()
{
		Site* ns = new Site(m_url, m_site_name);
		int site_id = ns->insertIntoDatabase();
		if (site_id > 0)
		{
			int okMsgBox = QMessageBox::information(this, Scale::coded("�����!"), Scale::coded("����� ������ ������� ���������"), Scale::coded("Ok"));
			if (okMsgBox == 0)
			{
				ui->btnCancel->click();
			}
		}
		else
		{
			
			ui->lineError->setText(Scale::coded("������ ������ ���� � ����"));
		}
	
}
void NewRecordUser::textRead()
{
	
	m_url = ui->lineUrl->text();
	m_site_name = ui->lineSite->text();
	
}

bool NewRecordUser::emptyLine()
{
	if ((m_url.isEmpty()) || (m_site_name.isEmpty()))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void NewRecordUser::showNDW()
{
	this->show();
}
