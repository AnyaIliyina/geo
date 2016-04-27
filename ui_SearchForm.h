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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
        SearchForm->setFloating(false);
        SearchForm->setFeatures(QDockWidget::NoDockWidgetFeatures);
        SearchForm->setWindowTitle(QString::fromUtf8("\320\244\320\270\320\273\321\214\321\202\321\200"));
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

        SearchForm->setWidget(dockWidgetContents);

        retranslateUi(SearchForm);

        QMetaObject::connectSlotsByName(SearchForm);
    } // setupUi

    void retranslateUi(QDockWidget *SearchForm)
    {
        label->setText(QApplication::translate("SearchForm", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\274\320\265\321\201\321\202\320\275\320\276\321\201\321\202\320\270", 0));
        label_2->setText(QApplication::translate("SearchForm", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\320\260\320\271\321\202\320\260", 0));
        label_3->setText(QApplication::translate("SearchForm", "\320\244\320\276\321\200\320\274\320\260\321\202", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("SearchForm", "Shapefile", 0)
         << QApplication::translate("SearchForm", "Jpg", 0)
         << QApplication::translate("SearchForm", "Png", 0)
        );
        Q_UNUSED(SearchForm);
    } // retranslateUi

};

namespace Ui {
    class SearchForm: public Ui_SearchForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHFORM_H
