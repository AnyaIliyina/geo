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
    QGridLayout *gridLayout_2;
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
        NewDockWidget->resize(420, 280);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NewDockWidget->sizePolicy().hasHeightForWidth());
        NewDockWidget->setSizePolicy(sizePolicy);
        NewDockWidget->setMinimumSize(QSize(420, 280));
        NewDockWidget->setMaximumSize(QSize(420, 280));
        QFont font;
        font.setPointSize(9);
        NewDockWidget->setFont(font);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dockWidgetContents->setMaximumSize(QSize(420, 250));
        gridLayout_2 = new QGridLayout(dockWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 10, -1, -1);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(15);
        gridLayout->setContentsMargins(-1, 0, -1, 20);
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        linePlace = new QLineEdit(dockWidgetContents);
        linePlace->setObjectName(QStringLiteral("linePlace"));
        linePlace->setFont(font);
        linePlace->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        gridLayout->addWidget(linePlace, 0, 1, 1, 1);

        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineUrl = new QLineEdit(dockWidgetContents);
        lineUrl->setObjectName(QStringLiteral("lineUrl"));
        lineUrl->setFont(font);
        lineUrl->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        gridLayout->addWidget(lineUrl, 1, 1, 1, 1);

        label_3 = new QLabel(dockWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineSite = new QLineEdit(dockWidgetContents);
        lineSite->setObjectName(QStringLiteral("lineSite"));
        lineSite->setFont(font);
        lineSite->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        gridLayout->addWidget(lineSite, 2, 1, 1, 1);

        label_4 = new QLabel(dockWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        boxFormat = new QComboBox(dockWidgetContents);
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

        gridLayout->addWidget(boxFormat, 3, 1, 1, 1);

        label_5 = new QLabel(dockWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lineScale = new QLineEdit(dockWidgetContents);
        lineScale->setObjectName(QStringLiteral("lineScale"));
        lineScale->setFont(font);
        lineScale->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        gridLayout->addWidget(lineScale, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnCreate = new QPushButton(dockWidgetContents);
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

        btnCancel = new QPushButton(dockWidgetContents);
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


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        lineError = new QLabel(dockWidgetContents);
        lineError->setObjectName(QStringLiteral("lineError"));
        lineError->setFont(font);

        gridLayout_2->addWidget(lineError, 1, 0, 1, 1);

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
         << QApplication::translate("NewDockWidget", "Jpg", 0)
         << QApplication::translate("NewDockWidget", "Png", 0)
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
