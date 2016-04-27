/********************************************************************************
** Form generated from reading UI file 'NewDockWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDOCKWIDGET_H
#define UI_NEWDOCKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewRecord
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *linePlace;
    QLabel *label_3;
    QComboBox *boxSite;
    QLabel *label_2;
    QLineEdit *lineUrl;
    QLabel *label_4;
    QComboBox *boxFormat;
    QLabel *label_5;
    QLineEdit *lineScale;
    QLabel *label_6;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCreate;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lineError;

    void setupUi(QWidget *NewRecord)
    {
        if (NewRecord->objectName().isEmpty())
            NewRecord->setObjectName(QStringLiteral("NewRecord"));
        NewRecord->resize(480, 324);
        gridLayout = new QGridLayout(NewRecord);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(15);
        formLayout->setContentsMargins(-1, -1, -1, 10);
        label = new QLabel(NewRecord);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        linePlace = new QLineEdit(NewRecord);
        linePlace->setObjectName(QStringLiteral("linePlace"));
        linePlace->setFont(font);
        linePlace->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(0, QFormLayout::FieldRole, linePlace);

        label_3 = new QLabel(NewRecord);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        boxSite = new QComboBox(NewRecord);
        boxSite->setObjectName(QStringLiteral("boxSite"));
        boxSite->setFont(font);
        boxSite->setStyleSheet(QLatin1String("QComboBox{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}\n"
"QComboBox:editable{\n"
"\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:4}"));

        formLayout->setWidget(1, QFormLayout::FieldRole, boxSite);

        label_2 = new QLabel(NewRecord);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lineUrl = new QLineEdit(NewRecord);
        lineUrl->setObjectName(QStringLiteral("lineUrl"));
        lineUrl->setFont(font);
        lineUrl->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineUrl);

        label_4 = new QLabel(NewRecord);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        boxFormat = new QComboBox(NewRecord);
        boxFormat->setObjectName(QStringLiteral("boxFormat"));
        boxFormat->setFont(font);
        boxFormat->setStyleSheet(QLatin1String("QComboBox{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}\n"
"QComboBox:editable{\n"
"\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:4}"));

        formLayout->setWidget(3, QFormLayout::FieldRole, boxFormat);

        label_5 = new QLabel(NewRecord);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        lineScale = new QLineEdit(NewRecord);
        lineScale->setObjectName(QStringLiteral("lineScale"));
        lineScale->setFont(font);
        lineScale->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineScale);

        label_6 = new QLabel(NewRecord);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        textEdit = new QTextEdit(NewRecord);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setStyleSheet(QLatin1String("QTextEdit{\n"
"border-radius:8;\n"
"border-width:1px;\n"
"max-height:70px;\n"
"min-height:70px;\n"
"\n"
"}"));

        formLayout->setWidget(5, QFormLayout::FieldRole, textEdit);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCreate = new QPushButton(NewRecord);
        btnCreate->setObjectName(QStringLiteral("btnCreate"));
        btnCreate->setFont(font);
        btnCreate->setStyleSheet(QLatin1String("QPushButton{\n"
"border:0px\n"
"\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCreate->setIcon(icon);
        btnCreate->setIconSize(QSize(30, 30));
        btnCreate->setFlat(true);

        horizontalLayout->addWidget(btnCreate);

        btnCancel = new QPushButton(NewRecord);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setFont(font);
        btnCancel->setStyleSheet(QLatin1String("QPushButton{\n"
"border:0px}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon1);
        btnCancel->setIconSize(QSize(30, 30));
        btnCancel->setFlat(true);

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        lineError = new QLabel(NewRecord);
        lineError->setObjectName(QStringLiteral("lineError"));
        lineError->setFont(font);

        gridLayout->addWidget(lineError, 2, 0, 1, 1);


        retranslateUi(NewRecord);
        QObject::connect(btnCancel, SIGNAL(clicked()), NewRecord, SLOT(close()));

        QMetaObject::connectSlotsByName(NewRecord);
    } // setupUi

    void retranslateUi(QWidget *NewRecord)
    {
        NewRecord->setWindowTitle(QApplication::translate("NewRecord", "\320\235\320\276\320\262\320\260\321\217 \320\267\320\260\320\277\320\270\321\201\321\214", 0));
        label->setText(QApplication::translate("NewRecord", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\274\320\265\321\201\321\202\320\260 *", 0));
        label_3->setText(QApplication::translate("NewRecord", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\320\260\320\271\321\202\320\260 *", 0));
        label_2->setText(QApplication::translate("NewRecord", "URL ", 0));
        label_4->setText(QApplication::translate("NewRecord", "\320\244\320\276\321\200\320\274\320\260\321\202 \320\264\320\260\320\275\320\275\321\213\321\205 *", 0));
        label_5->setText(QApplication::translate("NewRecord", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", 0));
        label_6->setText(QApplication::translate("NewRecord", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\270", 0));
        btnCreate->setText(QString());
        btnCancel->setText(QString());
        lineError->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewRecord: public Ui_NewRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDOCKWIDGET_H
