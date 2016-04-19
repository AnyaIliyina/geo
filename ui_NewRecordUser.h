/********************************************************************************
** Form generated from reading UI file 'NewRecordUser.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWRECORDUSER_H
#define UI_NEWRECORDUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewRecordUser
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineUrl;
    QLabel *label_3;
    QLineEdit *lineSite;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCreate;
    QPushButton *btnCancel;
    QLabel *lineError;

    void setupUi(QWidget *NewRecordUser)
    {
        if (NewRecordUser->objectName().isEmpty())
            NewRecordUser->setObjectName(QStringLiteral("NewRecordUser"));
        NewRecordUser->resize(415, 150);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NewRecordUser->sizePolicy().hasHeightForWidth());
        NewRecordUser->setSizePolicy(sizePolicy);
        NewRecordUser->setMinimumSize(QSize(415, 150));
        NewRecordUser->setMaximumSize(QSize(415, 150));
        widget = new QWidget(NewRecordUser);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 391, 121));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineUrl = new QLineEdit(widget);
        lineUrl->setObjectName(QStringLiteral("lineUrl"));
        lineUrl->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineUrl);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineSite = new QLineEdit(widget);
        lineSite->setObjectName(QStringLiteral("lineSite"));
        lineSite->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineSite);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnCreate = new QPushButton(widget);
        btnCreate->setObjectName(QStringLiteral("btnCreate"));
        btnCreate->setFont(font);

        horizontalLayout->addWidget(btnCreate);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setFont(font);

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        lineError = new QLabel(widget);
        lineError->setObjectName(QStringLiteral("lineError"));

        verticalLayout_2->addWidget(lineError);


        retranslateUi(NewRecordUser);
        QObject::connect(btnCancel, SIGNAL(clicked()), NewRecordUser, SLOT(close()));

        QMetaObject::connectSlotsByName(NewRecordUser);
    } // setupUi

    void retranslateUi(QWidget *NewRecordUser)
    {
        NewRecordUser->setWindowTitle(QApplication::translate("NewRecordUser", "\320\235\320\276\320\262\320\260\321\217 \320\267\320\260\320\277\320\270\321\201\321\214", 0));
        label_2->setText(QApplication::translate("NewRecordUser", "URL", 0));
        label_3->setText(QApplication::translate("NewRecordUser", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\320\260\320\271\321\202\320\260", 0));
        btnCreate->setText(QApplication::translate("NewRecordUser", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", 0));
        btnCancel->setText(QApplication::translate("NewRecordUser", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        lineError->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewRecordUser: public Ui_NewRecordUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWRECORDUSER_H
