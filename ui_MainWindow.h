/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionUser;
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *layoutWidget;
    QFormLayout *formLayout_2;
    QLabel *label_1;
    QFormLayout *formLayout;
    QLineEdit *textGeo;
    QLabel *label_2;
    QLineEdit *textURL;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *btnSearch;
    QTableWidget *tableSite;
    QGridLayout *gridLayout;
    QPushButton *btnNew;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menuView;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(730, 560);
        MainWindow->setMinimumSize(QSize(730, 550));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionUser = new QAction(MainWindow);
        actionUser->setObjectName(QStringLiteral("actionUser"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 10, 321, 501));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 0, 258, 480));
        formLayout_2 = new QFormLayout(layoutWidget);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_1 = new QLabel(layoutWidget);
        label_1->setObjectName(QStringLiteral("label_1"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        textGeo = new QLineEdit(layoutWidget);
        textGeo->setObjectName(QStringLiteral("textGeo"));

        formLayout->setWidget(0, QFormLayout::FieldRole, textGeo);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        textURL = new QLineEdit(layoutWidget);
        textURL->setObjectName(QStringLiteral("textURL"));

        formLayout->setWidget(1, QFormLayout::FieldRole, textURL);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        formLayout_2->setLayout(1, QFormLayout::SpanningRole, formLayout);

        btnSearch = new QPushButton(layoutWidget);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));

        formLayout_2->setWidget(2, QFormLayout::SpanningRole, btnSearch);

        tableSite = new QTableWidget(layoutWidget);
        tableSite->setObjectName(QStringLiteral("tableSite"));
        tableSite->setMinimumSize(QSize(150, 300));
        tableSite->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableSite->setSelectionMode(QAbstractItemView::SingleSelection);
        tableSite->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableSite->verticalHeader()->setStretchLastSection(true);

        formLayout_2->setWidget(3, QFormLayout::SpanningRole, tableSite);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnNew = new QPushButton(layoutWidget);
        btnNew->setObjectName(QStringLiteral("btnNew"));

        gridLayout->addWidget(btnNew, 0, 0, 1, 1);

        btnEdit = new QPushButton(layoutWidget);
        btnEdit->setObjectName(QStringLiteral("btnEdit"));

        gridLayout->addWidget(btnEdit, 0, 1, 1, 1);

        btnDelete = new QPushButton(layoutWidget);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));

        gridLayout->addWidget(btnDelete, 0, 2, 1, 1);


        formLayout_2->setLayout(4, QFormLayout::SpanningRole, gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 730, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menu->addAction(actionUser);
        menu->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionExit->setText(QApplication::translate("MainWindow", "&\320\222\321\213\321\205\320\276\320\264", 0));
        actionUser->setText(QApplication::translate("MainWindow", "&\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", 0));
        label_1->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\320\260\320\271\321\202\320\260", 0));
        label_3->setText(QApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260\321\202", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Shapefile", 0)
         << QApplication::translate("MainWindow", "jpg", 0)
        );
        label->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\274\320\265\321\201\321\202\320\275\320\276\321\201\321\202\320\270", 0));
        btnSearch->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", 0));
        btnNew->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \320\267\320\260\320\277\320\270\321\201\321\214", 0));
        btnEdit->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
        btnDelete->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        menu->setTitle(QApplication::translate("MainWindow", "&\320\244\320\260\320\271\320\273", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "&\320\222\320\270\320\264", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
