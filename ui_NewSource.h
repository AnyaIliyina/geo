/********************************************************************************
** Form generated from reading UI file 'NewSource.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSOURCE_H
#define UI_NEWSOURCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewSource
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineUrl;
    QLabel *label_3;
    QLineEdit *lineSite;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCreate;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *NewSource)
    {
        if (NewSource->objectName().isEmpty())
            NewSource->setObjectName(QStringLiteral("NewSource"));
        NewSource->resize(438, 114);
        NewSource->setMinimumSize(QSize(380, 114));
        NewSource->setMaximumSize(QSize(500, 114));
        QFont font;
        font.setPointSize(9);
        NewSource->setFont(font);
        gridLayout = new QGridLayout(NewSource);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setVerticalSpacing(15);
        label_2 = new QLabel(NewSource);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineUrl = new QLineEdit(NewSource);
        lineUrl->setObjectName(QStringLiteral("lineUrl"));
        lineUrl->setFont(font);
        lineUrl->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineUrl);

        label_3 = new QLabel(NewSource);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineSite = new QLineEdit(NewSource);
        lineSite->setObjectName(QStringLiteral("lineSite"));
        lineSite->setFont(font);
        lineSite->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineSite);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCreate = new QPushButton(NewSource);
        btnCreate->setObjectName(QStringLiteral("btnCreate"));
        btnCreate->setFont(font);
        btnCreate->setStyleSheet(QLatin1String("QPushButton{\n"
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
"}\n"
""));

        horizontalLayout->addWidget(btnCreate);

        btnCancel = new QPushButton(NewSource);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setFont(font);
        btnCancel->setStyleSheet(QLatin1String("QPushButton{\n"
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
"}\n"
""));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        formLayout->setLayout(2, QFormLayout::SpanningRole, horizontalLayout);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);


        retranslateUi(NewSource);

        QMetaObject::connectSlotsByName(NewSource);
    } // setupUi

    void retranslateUi(QWidget *NewSource)
    {
        NewSource->setWindowTitle(QApplication::translate("NewSource", "\320\235\320\276\320\262\321\213\320\271 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272", 0));
        label_2->setText(QApplication::translate("NewSource", "URL \321\201\320\260\320\271\321\202\320\260", 0));
        label_3->setText(QApplication::translate("NewSource", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\320\260\320\271\321\202\320\260", 0));
        btnCreate->setText(QApplication::translate("NewSource", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", 0));
        btnCancel->setText(QApplication::translate("NewSource", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class NewSource: public Ui_NewSource {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSOURCE_H
