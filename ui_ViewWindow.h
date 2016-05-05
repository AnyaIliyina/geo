/********************************************************************************
** Form generated from reading UI file 'ViewWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWWINDOW_H
#define UI_VIEWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewWindow
{
public:
    QAction *action_New;
    QAction *action_Delete;
    QAction *action_Edit;
    QAction *action_Yes;
    QAction *action_No;
    QAction *action_OpenUrl;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QToolBar *toolBar;

    void setupUi(QMainWindow *ViewWindow)
    {
        if (ViewWindow->objectName().isEmpty())
            ViewWindow->setObjectName(QStringLiteral("ViewWindow"));
        ViewWindow->resize(670, 389);
        action_New = new QAction(ViewWindow);
        action_New->setObjectName(QStringLiteral("action_New"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon);
        action_Delete = new QAction(ViewWindow);
        action_Delete->setObjectName(QStringLiteral("action_Delete"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/trash.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Delete->setIcon(icon1);
        action_Edit = new QAction(ViewWindow);
        action_Edit->setObjectName(QStringLiteral("action_Edit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/note.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Edit->setIcon(icon2);
        action_Yes = new QAction(ViewWindow);
        action_Yes->setObjectName(QStringLiteral("action_Yes"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Yes->setIcon(icon3);
        action_No = new QAction(ViewWindow);
        action_No->setObjectName(QStringLiteral("action_No"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_No->setIcon(icon4);
        action_OpenUrl = new QAction(ViewWindow);
        action_OpenUrl->setObjectName(QStringLiteral("action_OpenUrl"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_OpenUrl->setIcon(icon5);
        centralwidget = new QWidget(ViewWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setMinimumSize(QSize(550, 200));
        tableView->setStyleSheet(QLatin1String("QTableView{\n"
"border-width:2px\n"
"}"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        ViewWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(ViewWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        ViewWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(action_New);
        toolBar->addAction(action_Delete);
        toolBar->addSeparator();
        toolBar->addAction(action_OpenUrl);
        toolBar->addSeparator();
        toolBar->addAction(action_Edit);
        toolBar->addSeparator();
        toolBar->addAction(action_Yes);
        toolBar->addAction(action_No);

        retranslateUi(ViewWindow);

        QMetaObject::connectSlotsByName(ViewWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ViewWindow)
    {
        ViewWindow->setWindowTitle(QApplication::translate("ViewWindow", "MainWindow", 0));
#ifndef QT_NO_TOOLTIP
        ViewWindow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        action_New->setText(QApplication::translate("ViewWindow", "&New", 0));
        action_Delete->setText(QApplication::translate("ViewWindow", "&Delete", 0));
        action_Edit->setText(QApplication::translate("ViewWindow", "&Edit", 0));
        action_Yes->setText(QApplication::translate("ViewWindow", "&Yes", 0));
        action_No->setText(QApplication::translate("ViewWindow", "&No", 0));
        action_OpenUrl->setText(QApplication::translate("ViewWindow", "&OpenUrl", 0));
        toolBar->setWindowTitle(QApplication::translate("ViewWindow", "toolBar", 0));
#ifndef QT_NO_TOOLTIP
        toolBar->setToolTip(QString());
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class ViewWindow: public Ui_ViewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWWINDOW_H
