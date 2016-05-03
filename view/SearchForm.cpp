#include "SearchForm.h"
#include "ui_SearchForm.h"
#include "State.h"
#include <QTableWidget>
#include <QSqlQueryModel>
#include "Database.h"
#include "Format.h"
#include <QLineEdit>
/*!
\file
\brief
*/

SearchForm::SearchForm(QDockWidget *parent) :ui(new Ui::SearchForm)
{
	ui->setupUi(this);
	ui->comboBox->addItems(Format::getFormatNames());
	//QObject::connect(ui->textGeo, SIGNAL(QLineEdit::textEdited()), this, SLOT(slotCreateQuery()));
	QObject::connect(ui->textGeo, SIGNAL(textChanged(QString)), this, SLOT(filterChange(QString)));
	QObject::connect(ui->textURL, SIGNAL(textChanged(QString)), this, SLOT(filterChange(QString)));
	QObject::connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(filterChange(QString)));
}

SearchForm::~SearchForm()
{
	delete ui;
}

void SearchForm::filterChange(QString text)
{
	emit filterChanged(text);
}



