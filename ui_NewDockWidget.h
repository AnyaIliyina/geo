/********************************************************************************
** Form generated from reading UI file 'NewDockWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewDockWidget
{
public:
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *linePlace;
    QLabel *label_2;
    QLineEdit *lineUrl;
    QLabel *label_3;
    QLineEdit *lineSite;
    QLabel *label_4;
    QComboBox *boxFormat;
    QLabel *label_5;
    QLineEdit *lineScale;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCreate;
    QPushButton *btnCancel;
    QLabel *lineError;

    void setupUi(QDockWidget *NewDockWidget)
    {
        if (NewDockWidget->objectName().isEmpty())
            NewDockWidget->setObjectName(QStringLiteral("NewDockWidget"));
        NewDockWidget->resize(420, 272);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NewDockWidget->sizePolicy().hasHeightForWidth());
        NewDockWidget->setSizePolicy(sizePolicy);
        NewDockWidget->setMinimumSize(QSize(420, 265));
        NewDockWidget->setMaximumSize(QSize(420, 272));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dockWidgetContents->setMaximumSize(QSize(420, 250));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(15);
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        linePlace = new QLineEdit(dockWidgetContents);
        linePlace->setObjectName(QStringLiteral("linePlace"));
        linePlace->setFont(font);

        gridLayout->addWidget(linePlace, 0, 1, 1, 1);

        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineUrl = new QLineEdit(dockWidgetContents);
        lineUrl->setObjectName(QStringLiteral("lineUrl"));
        lineUrl->setFont(font);

        gridLayout->addWidget(lineUrl, 1, 1, 1, 1);

        label_3 = new QLabel(dockWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineSite = new QLineEdit(dockWidgetContents);
        lineSite->setObjectName(QStringLiteral("lineSite"));
        lineSite->setFont(font);

        gridLayout->addWidget(lineSite, 2, 1, 1, 1);

        label_4 = new QLabel(dockWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        boxFormat = new QComboBox(dockWidgetContents);
        boxFormat->setObjectName(QStringLiteral("boxFormat"));
        boxFormat->setFont(font);

        gridLayout->addWidget(boxFormat, 3, 1, 1, 1);

        label_5 = new QLabel(dockWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lineScale = new QLineEdit(dockWidgetContents);
        lineScale->setObjectName(QStringLiteral("lineScale"));
        lineScale->setFont(font);

        gridLayout->addWidget(lineScale, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnCreate = new QPushButton(dockWidgetContents);
        btnCreate->setObjectName(QStringLiteral("btnCreate"));
        btnCreate->setFont(font);

        horizontalLayout->addWidget(btnCreate);

        btnCancel = new QPushButton(dockWidgetContents);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setFont(font);

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        lineError = new QLabel(dockWidgetContents);
        lineError->setObjectName(QStringLiteral("lineError"));

        verticalLayout_2->addWidget(lineError);

        NewDockWidget->setWidget(dockWidgetContents);

        retranslateUi(NewDockWidget);
        QObject::connect(btnCancel, SIGNAL(clicked()), NewDockWidget, SLOT(close()));

        QMetaObject::connectSlotsByName(NewDockWidget);
    } // setupUi

    void retranslateUi(QDockWidget *NewDockWidget)
    {
        NewDockWidget->setWindowTitle(QApplication::translate("NewDockWidget", "\320\235\320\276\320\262\320\260\321\217 \320\267\320\260\320\277\320\270\321\201\321\214", 0));
        label->setText(QApplication::translate("NewDockWidget", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\274\320\265\321\201\321\202\320\260", 0));
        label_2->setText(QApplication::translate("NewDockWidget", "URL", 0));
        label_3->setText(QApplication::translate("NewDockWidget", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\320\260\320\271\321\202\320\260", 0));
        label_4->setText(QApplication::translate("NewDockWidget", "\320\244\320\276\321\200\320\274\320\260\321\202 \320\264\320\260\320\275\320\275\321\213\321\205", 0));
        boxFormat->clear();
        boxFormat->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("NewDockWidget", "Shapefile", 0)
        );
        label_5->setText(QApplication::translate("NewDockWidget", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", 0));
        btnCreate->setText(QApplication::translate("NewDockWidget", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", 0));
        btnCancel->setText(QApplication::translate("NewDockWidget", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        lineError->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewDockWidget: public Ui_NewDockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDOCKWIDGET_H
