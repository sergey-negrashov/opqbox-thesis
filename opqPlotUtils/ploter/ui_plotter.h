/********************************************************************************
** Form generated from reading UI file 'plotter.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTTER_H
#define UI_PLOTTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Plotter
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSlider *rangeMin;
    QSlider *rangeMax;
    QLabel *min_label;
    QLabel *max_label;
    QCheckBox *fbox;
    QCheckBox *vbox;
    QSpacerItem *verticalSpacer;
    QPushButton *toCSVBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Plotter)
    {
        if (Plotter->objectName().isEmpty())
            Plotter->setObjectName(QString::fromUtf8("Plotter"));
        Plotter->resize(1209, 1113);
        centralWidget = new QWidget(Plotter);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rangeMin = new QSlider(centralWidget);
        rangeMin->setObjectName(QString::fromUtf8("rangeMin"));
        rangeMin->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(rangeMin);

        rangeMax = new QSlider(centralWidget);
        rangeMax->setObjectName(QString::fromUtf8("rangeMax"));
        rangeMax->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(rangeMax);

        min_label = new QLabel(centralWidget);
        min_label->setObjectName(QString::fromUtf8("min_label"));

        verticalLayout->addWidget(min_label);

        max_label = new QLabel(centralWidget);
        max_label->setObjectName(QString::fromUtf8("max_label"));

        verticalLayout->addWidget(max_label);

        fbox = new QCheckBox(centralWidget);
        fbox->setObjectName(QString::fromUtf8("fbox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fbox->sizePolicy().hasHeightForWidth());
        fbox->setSizePolicy(sizePolicy);
        fbox->setChecked(true);

        verticalLayout->addWidget(fbox);

        vbox = new QCheckBox(centralWidget);
        vbox->setObjectName(QString::fromUtf8("vbox"));
        vbox->setChecked(true);

        verticalLayout->addWidget(vbox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        toCSVBtn = new QPushButton(centralWidget);
        toCSVBtn->setObjectName(QString::fromUtf8("toCSVBtn"));

        verticalLayout->addWidget(toCSVBtn);


        horizontalLayout->addLayout(verticalLayout);

        Plotter->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Plotter);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1209, 27));
        Plotter->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Plotter);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Plotter->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Plotter);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Plotter->setStatusBar(statusBar);

        retranslateUi(Plotter);

        QMetaObject::connectSlotsByName(Plotter);
    } // setupUi

    void retranslateUi(QMainWindow *Plotter)
    {
        Plotter->setWindowTitle(QApplication::translate("Plotter", "Plotter", 0, QApplication::UnicodeUTF8));
        min_label->setText(QApplication::translate("Plotter", "Min", 0, QApplication::UnicodeUTF8));
        max_label->setText(QApplication::translate("Plotter", "Max", 0, QApplication::UnicodeUTF8));
        fbox->setText(QApplication::translate("Plotter", "Frequency", 0, QApplication::UnicodeUTF8));
        vbox->setText(QApplication::translate("Plotter", "Voltage", 0, QApplication::UnicodeUTF8));
        toCSVBtn->setText(QApplication::translate("Plotter", "toCSV", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Plotter: public Ui_Plotter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTTER_H
