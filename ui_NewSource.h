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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewSource
{
public:
    QAction *action_add;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineUrl;
    QLabel *label_3;
    QLineEdit *lineSite;
    QLabel *label_4;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCreate;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lineError;

    void setupUi(QWidget *NewSource)
    {
        if (NewSource->objectName().isEmpty())
            NewSource->setObjectName(QStringLiteral("NewSource"));
        NewSource->resize(476, 230);
        NewSource->setMinimumSize(QSize(380, 210));
        NewSource->setMaximumSize(QSize(500, 230));
        QFont font;
        font.setPointSize(9);
        NewSource->setFont(font);
        action_add = new QAction(NewSource);
        action_add->setObjectName(QStringLiteral("action_add"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_add->setIcon(icon);
        gridLayout = new QGridLayout(NewSource);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(12);
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

        label_4 = new QLabel(NewSource);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        textEdit = new QTextEdit(NewSource);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setStyleSheet(QLatin1String("QTextEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:70px;\n"
"min-height:70px;\n"
"\n"
"}"));

        formLayout->setWidget(2, QFormLayout::FieldRole, textEdit);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 5, -1, 5);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCreate = new QPushButton(NewSource);
        btnCreate->setObjectName(QStringLiteral("btnCreate"));
        btnCreate->setMaximumSize(QSize(152, 30));
        btnCreate->setFont(font);
        btnCreate->setStyleSheet(QLatin1String("QPushButton{border:0px\n"
"}"));
        btnCreate->setIcon(icon);
        btnCreate->setIconSize(QSize(30, 30));
        btnCreate->setFlat(true);

        horizontalLayout->addWidget(btnCreate);

        btnCancel = new QPushButton(NewSource);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnCancel->sizePolicy().hasHeightForWidth());
        btnCancel->setSizePolicy(sizePolicy);
        btnCancel->setMaximumSize(QSize(152, 30));
        btnCancel->setFont(font);
        btnCancel->setStyleSheet(QStringLiteral("QPushButton{border:0px}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon1);
        btnCancel->setIconSize(QSize(30, 30));
        btnCancel->setFlat(true);

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        lineError = new QLabel(NewSource);
        lineError->setObjectName(QStringLiteral("lineError"));

        gridLayout->addWidget(lineError, 2, 0, 1, 1);


        retranslateUi(NewSource);
        QObject::connect(btnCancel, SIGNAL(clicked()), NewSource, SLOT(close()));

        QMetaObject::connectSlotsByName(NewSource);
    } // setupUi

    void retranslateUi(QWidget *NewSource)
    {
        NewSource->setWindowTitle(QApplication::translate("NewSource", "\320\235\320\276\320\262\321\213\320\271 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272", 0));
        action_add->setText(QApplication::translate("NewSource", "&add", 0));
        label_2->setText(QApplication::translate("NewSource", "URL \321\201\320\260\320\271\321\202\320\260", 0));
        label_3->setText(QApplication::translate("NewSource", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\320\260\320\271\321\202\320\260", 0));
        label_4->setText(QApplication::translate("NewSource", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\270", 0));
        btnCreate->setText(QString());
        btnCancel->setText(QString());
        lineError->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewSource: public Ui_NewSource {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSOURCE_H
