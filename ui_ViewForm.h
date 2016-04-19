/********************************************************************************
** Form generated from reading UI file 'ViewForm.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWFORM_H
#define UI_VIEWFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewForm
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnNew;
    QPushButton *btnEdit;
    QPushButton *btnDelete;

    void setupUi(QWidget *ViewForm)
    {
        if (ViewForm->objectName().isEmpty())
            ViewForm->setObjectName(QStringLiteral("ViewForm"));
        ViewForm->resize(540, 420);
        ViewForm->setMinimumSize(QSize(540, 420));
        widget = new QWidget(ViewForm);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 9, 523, 392));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(widget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setMinimumSize(QSize(521, 351));
        tableView->setStyleSheet(QLatin1String("QTableView{\n"
"border:none;\n"
"}"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 10, -1, -1);
        btnNew = new QPushButton(widget);
        btnNew->setObjectName(QStringLiteral("btnNew"));
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        btnNew->setFont(font);
        btnNew->setAutoFillBackground(false);
        btnNew->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color:qlineargradient(spread:reflect, x1:0.0225989, y1:0.023, x2:0, y2:1, stop:0 rgba(255, 255, 255, 255), stop:0.813559 rgba(204, 204, 204, 255), stop:1 rgba(162, 162, 184, 255));\n"
"font: 9pt ;\n"
"	border-color: rgb(144, 144, 144);\n"
"	\n"
"	color: rgb(30, 30, 30);\n"
"border-width: 1px;\n"
"border-radius:4;\n"
"border-style:solid;\n"
"\n"
"min-width:150px;\n"
"max-width:150px;\n"
"min-height:20px;\n"
"max-height:20px;\n"
"}"));

        horizontalLayout->addWidget(btnNew);

        btnEdit = new QPushButton(widget);
        btnEdit->setObjectName(QStringLiteral("btnEdit"));
        btnEdit->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color:qlineargradient(spread:reflect, x1:0.0225989, y1:0.023, x2:0, y2:1, stop:0 rgba(255, 255, 255, 255), stop:0.813559 rgba(204, 204, 204, 255), stop:1 rgba(162, 162, 184, 255));\n"
"font: 9pt ;\n"
"	border-color: rgb(144, 144, 144);\n"
"	\n"
"	color: rgb(30, 30, 30);\n"
"border-width: 1px;\n"
"border-radius:4;\n"
"border-style:solid;\n"
"\n"
"min-width:150px;\n"
"max-width:150px;\n"
"min-height:20px;\n"
"max-height:20px;\n"
"}"));

        horizontalLayout->addWidget(btnEdit);

        btnDelete = new QPushButton(widget);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        btnDelete->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color:qlineargradient(spread:reflect, x1:0.0225989, y1:0.023, x2:0, y2:1, stop:0 rgba(255, 255, 255, 255), stop:0.813559 rgba(204, 204, 204, 255), stop:1 rgba(162, 162, 184, 255));\n"
"font: 9pt ;\n"
"	border-color: rgb(144, 144, 144);\n"
"	\n"
"	color: rgb(30, 30, 30);\n"
"border-width: 1px;\n"
"border-radius:4;\n"
"border-style:solid;\n"
"\n"
"min-width:150px;\n"
"max-width:150px;\n"
"min-height:20px;\n"
"max-height:20px;\n"
"}"));

        horizontalLayout->addWidget(btnDelete);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ViewForm);

        QMetaObject::connectSlotsByName(ViewForm);
    } // setupUi

    void retranslateUi(QWidget *ViewForm)
    {
        ViewForm->setWindowTitle(QApplication::translate("ViewForm", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213 \320\277\320\276\320\270\321\201\320\272\320\260", 0));
        btnNew->setText(QApplication::translate("ViewForm", "\320\235\320\276\320\262\320\260\321\217 \320\267\320\260\320\277\320\270\321\201\321\214", 0));
        btnEdit->setText(QApplication::translate("ViewForm", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
        btnDelete->setText(QApplication::translate("ViewForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewForm: public Ui_ViewForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWFORM_H
