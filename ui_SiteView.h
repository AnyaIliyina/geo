/********************************************************************************
** Form generated from reading UI file 'SiteView.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SITEVIEW_H
#define UI_SITEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DockWidget
{
public:
    QWidget *dockWidgetContents;
    QTableView *SitesTblView;

    void setupUi(QDockWidget *DockWidget)
    {
        if (DockWidget->objectName().isEmpty())
            DockWidget->setObjectName(QStringLiteral("DockWidget"));
        DockWidget->resize(592, 349);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        SitesTblView = new QTableView(dockWidgetContents);
        SitesTblView->setObjectName(QStringLiteral("SitesTblView"));
        SitesTblView->setGeometry(QRect(10, 0, 571, 321));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SitesTblView->sizePolicy().hasHeightForWidth());
        SitesTblView->setSizePolicy(sizePolicy);
        SitesTblView->setShowGrid(false);
        SitesTblView->horizontalHeader()->setMinimumSectionSize(50);
        SitesTblView->verticalHeader()->setMinimumSectionSize(50);
        DockWidget->setWidget(dockWidgetContents);

        retranslateUi(DockWidget);

        QMetaObject::connectSlotsByName(DockWidget);
    } // setupUi

    void retranslateUi(QDockWidget *DockWidget)
    {
        DockWidget->setWindowTitle(QApplication::translate("DockWidget", "DockWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class DockWidget: public Ui_DockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SITEVIEW_H
