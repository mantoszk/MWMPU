/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "openglwidget.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *OpenGLTab;
    QWidget *connectionTab;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *autoButton;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *verticalSpacer_2;
    QWidget *openGLTab;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_14;
    OpenGLWidget *openGLWidget;
    QTabWidget *tabWidget;
    QWidget *horizontalTab1;
    QGridLayout *gridLayout_8;
    QWidget *widget_2;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout_15;
    QCustomPlot *angleGraph;
    QCustomPlot *distanceGraph;
    QWidget *verticalTab1;
    QGridLayout *gridLayout_9;
    QWidget *widget_3;
    QGridLayout *gridLayout_11;
    QVBoxLayout *verticalLayout_10;
    QCustomPlot *angleGraph2;
    QCustomPlot *distanceGraph2;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *calibrateButton;
    QSpacerItem *horizontalSpacer_15;
    QWidget *diagramsTab;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget_2;
    QWidget *horizontalTab2;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QCustomPlot *accelerationGraph;
    QCustomPlot *angularVelocityGraph;
    QWidget *verticalTab2;
    QGridLayout *gridLayout_12;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *accelerationGraph2;
    QCustomPlot *angularVelocityGraph2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *resetButton;
    QSpacerItem *horizontalSpacer_2;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 720);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        OpenGLTab = new QTabWidget(centralWidget);
        OpenGLTab->setObjectName(QStringLiteral("OpenGLTab"));
        connectionTab = new QWidget();
        connectionTab->setObjectName(QStringLiteral("connectionTab"));
        gridLayout_6 = new QGridLayout(connectionTab);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_12);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);

        label = new QLabel(connectionTab);
        label->setObjectName(QStringLiteral("label"));
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label);

        comboBox = new QComboBox(connectionTab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setLayoutDirection(Qt::LeftToRight);
        comboBox->setMaxVisibleItems(5);
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout_11->addWidget(comboBox);

        autoButton = new QPushButton(connectionTab);
        autoButton->setObjectName(QStringLiteral("autoButton"));

        horizontalLayout_11->addWidget(autoButton);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_16);


        verticalLayout_7->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);

        connectButton = new QPushButton(connectionTab);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        horizontalLayout_10->addWidget(connectButton);

        disconnectButton = new QPushButton(connectionTab);
        disconnectButton->setObjectName(QStringLiteral("disconnectButton"));

        horizontalLayout_10->addWidget(disconnectButton);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_9);


        verticalLayout_7->addLayout(horizontalLayout_10);


        horizontalLayout_12->addLayout(verticalLayout_7);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_13);


        verticalLayout_8->addLayout(horizontalLayout_12);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_2);


        gridLayout_6->addLayout(verticalLayout_8, 0, 0, 1, 1);

        OpenGLTab->addTab(connectionTab, QString());
        openGLTab = new QWidget();
        openGLTab->setObjectName(QStringLiteral("openGLTab"));
        gridLayout_7 = new QGridLayout(openGLTab);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        openGLWidget = new OpenGLWidget(openGLTab);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));

        horizontalLayout_14->addWidget(openGLWidget);

        tabWidget = new QTabWidget(openGLTab);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        horizontalTab1 = new QWidget();
        horizontalTab1->setObjectName(QStringLiteral("horizontalTab1"));
        gridLayout_8 = new QGridLayout(horizontalTab1);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        widget_2 = new QWidget(horizontalTab1);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout_10 = new QGridLayout(widget_2);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        angleGraph = new QCustomPlot(widget_2);
        angleGraph->setObjectName(QStringLiteral("angleGraph"));

        horizontalLayout_15->addWidget(angleGraph);

        distanceGraph = new QCustomPlot(widget_2);
        distanceGraph->setObjectName(QStringLiteral("distanceGraph"));

        horizontalLayout_15->addWidget(distanceGraph);


        gridLayout_10->addLayout(horizontalLayout_15, 0, 0, 1, 1);


        gridLayout_8->addWidget(widget_2, 0, 0, 1, 1);

        tabWidget->addTab(horizontalTab1, QString());
        verticalTab1 = new QWidget();
        verticalTab1->setObjectName(QStringLiteral("verticalTab1"));
        gridLayout_9 = new QGridLayout(verticalTab1);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        widget_3 = new QWidget(verticalTab1);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        gridLayout_11 = new QGridLayout(widget_3);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        angleGraph2 = new QCustomPlot(widget_3);
        angleGraph2->setObjectName(QStringLiteral("angleGraph2"));

        verticalLayout_10->addWidget(angleGraph2);

        distanceGraph2 = new QCustomPlot(widget_3);
        distanceGraph2->setObjectName(QStringLiteral("distanceGraph2"));

        verticalLayout_10->addWidget(distanceGraph2);


        gridLayout_11->addLayout(verticalLayout_10, 0, 0, 1, 1);


        gridLayout_9->addWidget(widget_3, 0, 0, 1, 1);

        tabWidget->addTab(verticalTab1, QString());

        horizontalLayout_14->addWidget(tabWidget);


        verticalLayout_9->addLayout(horizontalLayout_14);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_14);

        calibrateButton = new QPushButton(openGLTab);
        calibrateButton->setObjectName(QStringLiteral("calibrateButton"));

        horizontalLayout_13->addWidget(calibrateButton);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_15);


        verticalLayout_9->addLayout(horizontalLayout_13);


        gridLayout_7->addLayout(verticalLayout_9, 0, 0, 1, 1);

        OpenGLTab->addTab(openGLTab, QString());
        diagramsTab = new QWidget();
        diagramsTab->setObjectName(QStringLiteral("diagramsTab"));
        gridLayout_2 = new QGridLayout(diagramsTab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget_2 = new QTabWidget(diagramsTab);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        horizontalTab2 = new QWidget();
        horizontalTab2->setObjectName(QStringLiteral("horizontalTab2"));
        gridLayout_5 = new QGridLayout(horizontalTab2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        accelerationGraph = new QCustomPlot(horizontalTab2);
        accelerationGraph->setObjectName(QStringLiteral("accelerationGraph"));

        horizontalLayout_5->addWidget(accelerationGraph);

        angularVelocityGraph = new QCustomPlot(horizontalTab2);
        angularVelocityGraph->setObjectName(QStringLiteral("angularVelocityGraph"));

        horizontalLayout_5->addWidget(angularVelocityGraph);


        gridLayout_5->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        tabWidget_2->addTab(horizontalTab2, QString());
        verticalTab2 = new QWidget();
        verticalTab2->setObjectName(QStringLiteral("verticalTab2"));
        gridLayout_12 = new QGridLayout(verticalTab2);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        accelerationGraph2 = new QCustomPlot(verticalTab2);
        accelerationGraph2->setObjectName(QStringLiteral("accelerationGraph2"));

        verticalLayout_2->addWidget(accelerationGraph2);

        angularVelocityGraph2 = new QCustomPlot(verticalTab2);
        angularVelocityGraph2->setObjectName(QStringLiteral("angularVelocityGraph2"));

        verticalLayout_2->addWidget(angularVelocityGraph2);


        gridLayout_12->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidget_2->addTab(verticalTab2, QString());

        verticalLayout->addWidget(tabWidget_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        resetButton = new QPushButton(diagramsTab);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        horizontalLayout->addWidget(resetButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        OpenGLTab->addTab(diagramsTab, QString());

        gridLayout->addWidget(OpenGLTab, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        OpenGLTab->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Choose device:", nullptr));
        autoButton->setText(QApplication::translate("MainWindow", "Auto", nullptr));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        disconnectButton->setText(QApplication::translate("MainWindow", "Disconnect", nullptr));
        OpenGLTab->setTabText(OpenGLTab->indexOf(connectionTab), QApplication::translate("MainWindow", "Connection", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(horizontalTab1), QApplication::translate("MainWindow", "Horizontal", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(verticalTab1), QApplication::translate("MainWindow", "Vertical", nullptr));
        calibrateButton->setText(QApplication::translate("MainWindow", "Calibrate", nullptr));
        OpenGLTab->setTabText(OpenGLTab->indexOf(openGLTab), QApplication::translate("MainWindow", "OpenGL", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(horizontalTab2), QApplication::translate("MainWindow", "Horizontal", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(verticalTab2), QApplication::translate("MainWindow", "Vertical", nullptr));
        resetButton->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        OpenGLTab->setTabText(OpenGLTab->indexOf(diagramsTab), QApplication::translate("MainWindow", "Diagrams", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
