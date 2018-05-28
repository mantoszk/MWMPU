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
#include "ledindicator.h"
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
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *autoButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *disconnectButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *connectButton;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    LedIndicator *led;
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
    LedIndicator *led2;
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
    LedIndicator *led3;
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
        gridLayout_3 = new QGridLayout(connectionTab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_3->addItem(verticalSpacer_3, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(connectionTab);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label);

        comboBox = new QComboBox(connectionTab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMinimumSize(QSize(0, 0));
        comboBox->setFont(font);
        comboBox->setLayoutDirection(Qt::LeftToRight);
        comboBox->setMaxVisibleItems(5);
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout_4->addWidget(comboBox);


        horizontalLayout_3->addLayout(horizontalLayout_4);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        autoButton = new QPushButton(connectionTab);
        autoButton->setObjectName(QStringLiteral("autoButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(autoButton->sizePolicy().hasHeightForWidth());
        autoButton->setSizePolicy(sizePolicy2);
        autoButton->setMinimumSize(QSize(150, 60));
        autoButton->setFont(font);

        horizontalLayout_2->addWidget(autoButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        disconnectButton = new QPushButton(connectionTab);
        disconnectButton->setObjectName(QStringLiteral("disconnectButton"));
        sizePolicy2.setHeightForWidth(disconnectButton->sizePolicy().hasHeightForWidth());
        disconnectButton->setSizePolicy(sizePolicy2);
        disconnectButton->setMinimumSize(QSize(150, 60));
        disconnectButton->setFont(font);

        horizontalLayout_2->addWidget(disconnectButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        connectButton = new QPushButton(connectionTab);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        sizePolicy2.setHeightForWidth(connectButton->sizePolicy().hasHeightForWidth());
        connectButton->setSizePolicy(sizePolicy2);
        connectButton->setMinimumSize(QSize(150, 60));
        connectButton->setFont(font);
        connectButton->setIconSize(QSize(30, 30));
        connectButton->setFlat(false);

        horizontalLayout_2->addWidget(connectButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout_3->addLayout(verticalLayout_3, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_4->addItem(verticalSpacer);

        led = new LedIndicator(connectionTab);
        led->setObjectName(QStringLiteral("led"));

        verticalLayout_4->addWidget(led);


        horizontalLayout_6->addLayout(verticalLayout_4);


        gridLayout_3->addLayout(horizontalLayout_6, 2, 0, 1, 1);

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

        led2 = new LedIndicator(openGLTab);
        led2->setObjectName(QStringLiteral("led2"));

        horizontalLayout_13->addWidget(led2);


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

        led3 = new LedIndicator(diagramsTab);
        led3->setObjectName(QStringLiteral("led3"));

        horizontalLayout->addWidget(led3);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        OpenGLTab->addTab(diagramsTab, QString());

        gridLayout->addWidget(OpenGLTab, 0, 0, 1, 1);

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
        disconnectButton->setText(QApplication::translate("MainWindow", "Disconnect", nullptr));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", nullptr));
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
