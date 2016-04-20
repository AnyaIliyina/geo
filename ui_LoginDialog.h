/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *lblResult;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_login;
    QLabel *lbl_password;
    QVBoxLayout *verticalLayout;
    QLineEdit *line_Login;
    QLineEdit *line_Pass;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_login;
    QPushButton *btn_exit;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(348, 119);
        QFont font;
        font.setPointSize(9);
        LoginDialog->setFont(font);
        LoginDialog->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}\n"
"\n"
""));
        gridLayout = new QGridLayout(LoginDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lblResult = new QLabel(LoginDialog);
        lblResult->setObjectName(QStringLiteral("lblResult"));

        gridLayout->addWidget(lblResult, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lbl_login = new QLabel(LoginDialog);
        lbl_login->setObjectName(QStringLiteral("lbl_login"));

        verticalLayout_2->addWidget(lbl_login);

        lbl_password = new QLabel(LoginDialog);
        lbl_password->setObjectName(QStringLiteral("lbl_password"));

        verticalLayout_2->addWidget(lbl_password);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        line_Login = new QLineEdit(LoginDialog);
        line_Login->setObjectName(QStringLiteral("line_Login"));

        verticalLayout->addWidget(line_Login);

        line_Pass = new QLineEdit(LoginDialog);
        line_Pass->setObjectName(QStringLiteral("line_Pass"));
        line_Pass->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(line_Pass);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_login = new QPushButton(LoginDialog);
        btn_login->setObjectName(QStringLiteral("btn_login"));
        btn_login->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color:qlineargradient(spread:reflect, x1:0.0225989, y1:0.023, x2:0, y2:1, stop:0 rgba(255, 255, 255, 255), stop:0.813559 rgba(204, 204, 204, 255), stop:1 rgba(162, 162, 184, 255));\n"
"font: 9pt ;\n"
"	border-color: rgb(144, 144, 144);\n"
"	\n"
"	color: rgb(30, 30, 30);\n"
"border-width: 1px;\n"
"border-radius:4;\n"
"border-style:solid;\n"
"\n"
"min-width:110px;\n"
"max-width:110px;\n"
"min-height:20px;\n"
"max-height:20px;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(btn_login);

        btn_exit = new QPushButton(LoginDialog);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));
        btn_exit->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color:qlineargradient(spread:reflect, x1:0.0225989, y1:0.023, x2:0, y2:1, stop:0 rgba(255, 255, 255, 255), stop:0.813559 rgba(204, 204, 204, 255), stop:1 rgba(162, 162, 184, 255));\n"
"font: 9pt ;\n"
"	border-color: rgb(144, 144, 144);\n"
"	\n"
"	color: rgb(30, 30, 30);\n"
"border-width: 1px;\n"
"border-radius:4;\n"
"border-style:solid;\n"
"\n"
"min-width:110px;\n"
"max-width:110px;\n"
"min-height:20px;\n"
"max-height:20px;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(btn_exit);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(LoginDialog);
        QObject::connect(btn_exit, SIGNAL(clicked()), LoginDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", 0));
        lblResult->setText(QString());
        lbl_login->setText(QApplication::translate("LoginDialog", "\320\233\320\276\320\263\320\270\320\275:", 0));
        lbl_password->setText(QApplication::translate("LoginDialog", "\320\237\320\260\321\200\320\276\320\273\321\214:", 0));
        btn_login->setText(QApplication::translate("LoginDialog", "Ok", 0));
        btn_exit->setText(QApplication::translate("LoginDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
