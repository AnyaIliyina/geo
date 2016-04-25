/********************************************************************************
** Form generated from reading UI file 'SearchForm.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHFORM_H
#define UI_SEARCHFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchForm
{
public:
    QWidget *dockWidgetContents;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *textGeo;
    QLabel *label_2;
    QLineEdit *textURL;
    QLabel *label_3;
    QComboBox *comboBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSearch;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDockWidget *SearchForm)
    {
        if (SearchForm->objectName().isEmpty())
            SearchForm->setObjectName(QStringLiteral("SearchForm"));
        SearchForm->resize(362, 200);
        SearchForm->setMinimumSize(QSize(362, 200));
        SearchForm->setMaximumSize(QSize(362, 200));
        QFont font;
        font.setPointSize(9);
        SearchForm->setFont(font);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        layoutWidget = new QWidget(dockWidgetContents);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 10, 341, 108));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setVerticalSpacing(12);
        formLayout->setContentsMargins(0, 12, 0, 12);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        textGeo = new QLineEdit(layoutWidget);
        textGeo->setObjectName(QStringLiteral("textGeo"));
        textGeo->setFont(font);
        textGeo->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(0, QFormLayout::FieldRole, textGeo);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        textURL = new QLineEdit(layoutWidget);
        textURL->setObjectName(QStringLiteral("textURL"));
        textURL->setFont(font);
        textURL->setStyleSheet(QLatin1String("QLineEdit{\n"
"border-radius:4;\n"
"border-width:1px;\n"
"max-height:20px;\n"
"min-height:20px;\n"
"\n"
"}"));

        formLayout->setWidget(1, QFormLayout::FieldRole, textURL);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setFont(font);
        comboBox->setStyleSheet(QLatin1String("QComboBox{\n"
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

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox);

        layoutWidget1 = new QWidget(dockWidgetContents);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(60, 130, 246, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSearch = new QPushButton(layoutWidget1);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));
        QPalette palette;
        QBrush brush(QColor(30, 30, 30, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient(0.0225989, 0.023, 0, 1);
        gradient.setSpread(QGradient::ReflectSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(255, 255, 255, 255));
        gradient.setColorAt(0.813559, QColor(204, 204, 204, 255));
        gradient.setColorAt(1, QColor(162, 162, 184, 255));
        QBrush brush1(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(0, 127, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(0, 106, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(0, 42, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(0, 56, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient1(0.0225989, 0.023, 0, 1);
        gradient1.setSpread(QGradient::ReflectSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(255, 255, 255, 255));
        gradient1.setColorAt(0.813559, QColor(204, 204, 204, 255));
        gradient1.setColorAt(1, QColor(162, 162, 184, 255));
        QBrush brush7(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush7);
        QLinearGradient gradient2(0.0225989, 0.023, 0, 1);
        gradient2.setSpread(QGradient::ReflectSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(255, 255, 255, 255));
        gradient2.setColorAt(0.813559, QColor(204, 204, 204, 255));
        gradient2.setColorAt(1, QColor(162, 162, 184, 255));
        QBrush brush8(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush8);
        QBrush brush9(QColor(0, 0, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush9);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush10(QColor(255, 255, 220, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient3(0.0225989, 0.023, 0, 1);
        gradient3.setSpread(QGradient::ReflectSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(255, 255, 255, 255));
        gradient3.setColorAt(0.813559, QColor(204, 204, 204, 255));
        gradient3.setColorAt(1, QColor(162, 162, 184, 255));
        QBrush brush11(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient4(0.0225989, 0.023, 0, 1);
        gradient4.setSpread(QGradient::ReflectSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(255, 255, 255, 255));
        gradient4.setColorAt(0.813559, QColor(204, 204, 204, 255));
        gradient4.setColorAt(1, QColor(162, 162, 184, 255));
        QBrush brush12(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush12);
        QLinearGradient gradient5(0.0225989, 0.023, 0, 1);
        gradient5.setSpread(QGradient::ReflectSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(255, 255, 255, 255));
        gradient5.setColorAt(0.813559, QColor(204, 204, 204, 255));
        gradient5.setColorAt(1, QColor(162, 162, 184, 255));
        QBrush brush13(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient6(0.0225989, 0.023, 0, 1);
        gradient6.setSpread(QGradient::ReflectSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(255, 255, 255, 255));
        gradient6.setColorAt(0.813559, QColor(204, 204, 204, 255));
        gradient6.setColorAt(1, QColor(162, 162, 184, 255));
        QBrush brush14(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush14);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient7(0.0225989, 0.023, 0, 1);
        gradient7.setSpread(QGradient::ReflectSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(255, 255, 255, 255));
        gradient7.setColorAt(0.813559, QColor(204, 204, 204, 255));
        gradient7.setColorAt(1, QColor(162, 162, 184, 255));
        QBrush brush15(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush15);
        QLinearGradient gradient8(0.0225989, 0.023, 0, 1);
        gradient8.setSpread(QGradient::ReflectSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(255, 255, 255, 255));
        gradient8.setColorAt(0.813559, QColor(204, 204, 204, 255));
        gradient8.setColorAt(1, QColor(162, 162, 184, 255));
        QBrush brush16(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush16);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush9);
        QBrush brush17(QColor(0, 85, 0, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush17);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush9);
        btnSearch->setPalette(palette);
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        btnSearch->setFont(font1);
        btnSearch->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout->addWidget(btnSearch);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        SearchForm->setWidget(dockWidgetContents);

        retranslateUi(SearchForm);

        QMetaObject::connectSlotsByName(SearchForm);
    } // setupUi

    void retranslateUi(QDockWidget *SearchForm)
    {
        SearchForm->setWindowTitle(QApplication::translate("SearchForm", "\320\237\320\276\320\270\321\201\320\272", 0));
        label->setText(QApplication::translate("SearchForm", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\274\320\265\321\201\321\202\320\275\320\276\321\201\321\202\320\270", 0));
        label_2->setText(QApplication::translate("SearchForm", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\320\260\320\271\321\202\320\260", 0));
        label_3->setText(QApplication::translate("SearchForm", "\320\244\320\276\321\200\320\274\320\260\321\202", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("SearchForm", "Shapefile", 0)
         << QApplication::translate("SearchForm", "Shapefile", 0)
         << QApplication::translate("SearchForm", "Jpg", 0)
         << QApplication::translate("SearchForm", "Png", 0)
        );
        btnSearch->setText(QApplication::translate("SearchForm", "\320\237\320\276\320\270\321\201\320\272", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchForm: public Ui_SearchForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHFORM_H
