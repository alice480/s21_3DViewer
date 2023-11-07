/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "widgetogl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    WidgetOGL *openGLWidget;
    QGroupBox *controlPanel;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *saving;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton_selectFile;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *savePicture;
    QPushButton *saveGif;
    QGroupBox *scaling;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *scaleToCenter;
    QPushButton *scaleOptimize;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *scaleDown;
    QSpinBox *scaleStep;
    QPushButton *scaleUp;
    QGroupBox *moving;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *moveX;
    QRadioButton *moveY;
    QRadioButton *moveZ;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *moveBack;
    QSpinBox *moveStep;
    QPushButton *moveForward;
    QGroupBox *rotating;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *rotateX;
    QRadioButton *rotateY;
    QRadioButton *rotateZ;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *rotateBack;
    QSpinBox *rotateStep;
    QPushButton *rotateForward;
    QGroupBox *viewingArea;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *perspective;
    QPushButton *bgColorBtn;
    QGroupBox *edgeSet;
    QVBoxLayout *verticalLayout;
    QCheckBox *edgeDashChk;
    QHBoxLayout *horizontalLayout_2;
    QLabel *edgeThickLbl;
    QSpinBox *edgeThickBox;
    QPushButton *edgeColorBtn;
    QGroupBox *vertexSet;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *displayMethodNot;
    QRadioButton *displayMethodSphere;
    QRadioButton *displayMethodCube;
    QHBoxLayout *horizontalLayout_3;
    QLabel *vSizeLbl;
    QSpinBox *vSizeBox;
    QPushButton *vColorBtn;
    QGroupBox *emptyArea;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1174, 972);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        openGLWidget = new WidgetOGL(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setMinimumSize(QSize(400, 400));

        horizontalLayout->addWidget(openGLWidget);

        controlPanel = new QGroupBox(centralwidget);
        controlPanel->setObjectName(QString::fromUtf8("controlPanel"));
        controlPanel->setMaximumSize(QSize(384, 16777215));
        verticalLayout_8 = new QVBoxLayout(controlPanel);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        saving = new QGroupBox(controlPanel);
        saving->setObjectName(QString::fromUtf8("saving"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(saving->sizePolicy().hasHeightForWidth());
        saving->setSizePolicy(sizePolicy);
        verticalLayout_6 = new QVBoxLayout(saving);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        pushButton_selectFile = new QPushButton(saving);
        pushButton_selectFile->setObjectName(QString::fromUtf8("pushButton_selectFile"));

        verticalLayout_6->addWidget(pushButton_selectFile);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        savePicture = new QPushButton(saving);
        savePicture->setObjectName(QString::fromUtf8("savePicture"));
        savePicture->setEnabled(true);

        horizontalLayout_11->addWidget(savePicture);

        saveGif = new QPushButton(saving);
        saveGif->setObjectName(QString::fromUtf8("saveGif"));
        saveGif->setEnabled(true);
        saveGif->setCheckable(true);

        horizontalLayout_11->addWidget(saveGif);


        verticalLayout_6->addLayout(horizontalLayout_11);


        verticalLayout_8->addWidget(saving);

        scaling = new QGroupBox(controlPanel);
        scaling->setObjectName(QString::fromUtf8("scaling"));
        sizePolicy.setHeightForWidth(scaling->sizePolicy().hasHeightForWidth());
        scaling->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(scaling);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        scaleToCenter = new QPushButton(scaling);
        scaleToCenter->setObjectName(QString::fromUtf8("scaleToCenter"));
        scaleToCenter->setEnabled(true);

        horizontalLayout_10->addWidget(scaleToCenter);

        scaleOptimize = new QPushButton(scaling);
        scaleOptimize->setObjectName(QString::fromUtf8("scaleOptimize"));
        scaleOptimize->setEnabled(true);

        horizontalLayout_10->addWidget(scaleOptimize);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        scaleDown = new QPushButton(scaling);
        scaleDown->setObjectName(QString::fromUtf8("scaleDown"));

        horizontalLayout_9->addWidget(scaleDown);

        scaleStep = new QSpinBox(scaling);
        scaleStep->setObjectName(QString::fromUtf8("scaleStep"));
        scaleStep->setMinimum(1);
        scaleStep->setMaximum(50);
        scaleStep->setValue(25);

        horizontalLayout_9->addWidget(scaleStep);

        scaleUp = new QPushButton(scaling);
        scaleUp->setObjectName(QString::fromUtf8("scaleUp"));

        horizontalLayout_9->addWidget(scaleUp);


        verticalLayout_5->addLayout(horizontalLayout_9);


        verticalLayout_8->addWidget(scaling);

        moving = new QGroupBox(controlPanel);
        moving->setObjectName(QString::fromUtf8("moving"));
        sizePolicy.setHeightForWidth(moving->sizePolicy().hasHeightForWidth());
        moving->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(moving);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        moveX = new QRadioButton(moving);
        moveX->setObjectName(QString::fromUtf8("moveX"));
        moveX->setChecked(true);

        horizontalLayout_5->addWidget(moveX);

        moveY = new QRadioButton(moving);
        moveY->setObjectName(QString::fromUtf8("moveY"));

        horizontalLayout_5->addWidget(moveY);

        moveZ = new QRadioButton(moving);
        moveZ->setObjectName(QString::fromUtf8("moveZ"));

        horizontalLayout_5->addWidget(moveZ);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        moveBack = new QPushButton(moving);
        moveBack->setObjectName(QString::fromUtf8("moveBack"));

        horizontalLayout_4->addWidget(moveBack);

        moveStep = new QSpinBox(moving);
        moveStep->setObjectName(QString::fromUtf8("moveStep"));
        moveStep->setMinimum(1);
        moveStep->setMaximum(100);
        moveStep->setValue(15);

        horizontalLayout_4->addWidget(moveStep);

        moveForward = new QPushButton(moving);
        moveForward->setObjectName(QString::fromUtf8("moveForward"));

        horizontalLayout_4->addWidget(moveForward);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_8->addWidget(moving);

        rotating = new QGroupBox(controlPanel);
        rotating->setObjectName(QString::fromUtf8("rotating"));
        sizePolicy.setHeightForWidth(rotating->sizePolicy().hasHeightForWidth());
        rotating->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(rotating);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        rotateX = new QRadioButton(rotating);
        rotateX->setObjectName(QString::fromUtf8("rotateX"));
        rotateX->setChecked(true);

        horizontalLayout_7->addWidget(rotateX);

        rotateY = new QRadioButton(rotating);
        rotateY->setObjectName(QString::fromUtf8("rotateY"));

        horizontalLayout_7->addWidget(rotateY);

        rotateZ = new QRadioButton(rotating);
        rotateZ->setObjectName(QString::fromUtf8("rotateZ"));

        horizontalLayout_7->addWidget(rotateZ);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        rotateBack = new QPushButton(rotating);
        rotateBack->setObjectName(QString::fromUtf8("rotateBack"));

        horizontalLayout_8->addWidget(rotateBack);

        rotateStep = new QSpinBox(rotating);
        rotateStep->setObjectName(QString::fromUtf8("rotateStep"));
        rotateStep->setMinimum(1);
        rotateStep->setMaximum(359);
        rotateStep->setValue(15);

        horizontalLayout_8->addWidget(rotateStep);

        rotateForward = new QPushButton(rotating);
        rotateForward->setObjectName(QString::fromUtf8("rotateForward"));

        horizontalLayout_8->addWidget(rotateForward);


        verticalLayout_4->addLayout(horizontalLayout_8);


        verticalLayout_8->addWidget(rotating);

        viewingArea = new QGroupBox(controlPanel);
        viewingArea->setObjectName(QString::fromUtf8("viewingArea"));
        sizePolicy.setHeightForWidth(viewingArea->sizePolicy().hasHeightForWidth());
        viewingArea->setSizePolicy(sizePolicy);
        verticalLayout_7 = new QVBoxLayout(viewingArea);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        perspective = new QCheckBox(viewingArea);
        perspective->setObjectName(QString::fromUtf8("perspective"));

        verticalLayout_7->addWidget(perspective);

        bgColorBtn = new QPushButton(viewingArea);
        bgColorBtn->setObjectName(QString::fromUtf8("bgColorBtn"));

        verticalLayout_7->addWidget(bgColorBtn);


        verticalLayout_8->addWidget(viewingArea);

        edgeSet = new QGroupBox(controlPanel);
        edgeSet->setObjectName(QString::fromUtf8("edgeSet"));
        sizePolicy.setHeightForWidth(edgeSet->sizePolicy().hasHeightForWidth());
        edgeSet->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(edgeSet);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        edgeDashChk = new QCheckBox(edgeSet);
        edgeDashChk->setObjectName(QString::fromUtf8("edgeDashChk"));

        verticalLayout->addWidget(edgeDashChk);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        edgeThickLbl = new QLabel(edgeSet);
        edgeThickLbl->setObjectName(QString::fromUtf8("edgeThickLbl"));

        horizontalLayout_2->addWidget(edgeThickLbl);

        edgeThickBox = new QSpinBox(edgeSet);
        edgeThickBox->setObjectName(QString::fromUtf8("edgeThickBox"));
        edgeThickBox->setMinimum(1);
        edgeThickBox->setMaximum(30);
        edgeThickBox->setValue(4);

        horizontalLayout_2->addWidget(edgeThickBox);


        verticalLayout->addLayout(horizontalLayout_2);

        edgeColorBtn = new QPushButton(edgeSet);
        edgeColorBtn->setObjectName(QString::fromUtf8("edgeColorBtn"));

        verticalLayout->addWidget(edgeColorBtn);


        verticalLayout_8->addWidget(edgeSet);

        vertexSet = new QGroupBox(controlPanel);
        vertexSet->setObjectName(QString::fromUtf8("vertexSet"));
        sizePolicy.setHeightForWidth(vertexSet->sizePolicy().hasHeightForWidth());
        vertexSet->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(vertexSet);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        displayMethodNot = new QRadioButton(vertexSet);
        displayMethodNot->setObjectName(QString::fromUtf8("displayMethodNot"));
        QFont font;
        font.setPointSize(11);
        displayMethodNot->setFont(font);
        displayMethodNot->setChecked(true);

        horizontalLayout_6->addWidget(displayMethodNot);

        displayMethodSphere = new QRadioButton(vertexSet);
        displayMethodSphere->setObjectName(QString::fromUtf8("displayMethodSphere"));
        displayMethodSphere->setFont(font);

        horizontalLayout_6->addWidget(displayMethodSphere);

        displayMethodCube = new QRadioButton(vertexSet);
        displayMethodCube->setObjectName(QString::fromUtf8("displayMethodCube"));
        displayMethodCube->setFont(font);

        horizontalLayout_6->addWidget(displayMethodCube);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        vSizeLbl = new QLabel(vertexSet);
        vSizeLbl->setObjectName(QString::fromUtf8("vSizeLbl"));

        horizontalLayout_3->addWidget(vSizeLbl);

        vSizeBox = new QSpinBox(vertexSet);
        vSizeBox->setObjectName(QString::fromUtf8("vSizeBox"));
        vSizeBox->setMinimum(1);
        vSizeBox->setMaximum(60);
        vSizeBox->setValue(25);

        horizontalLayout_3->addWidget(vSizeBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        vColorBtn = new QPushButton(vertexSet);
        vColorBtn->setObjectName(QString::fromUtf8("vColorBtn"));

        verticalLayout_2->addWidget(vColorBtn);


        verticalLayout_8->addWidget(vertexSet);

        emptyArea = new QGroupBox(controlPanel);
        emptyArea->setObjectName(QString::fromUtf8("emptyArea"));

        verticalLayout_8->addWidget(emptyArea);


        horizontalLayout->addWidget(controlPanel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1174, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3DViewer", nullptr));
        controlPanel->setTitle(QString());
        saving->setTitle(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\320\270\320\265 \320\270 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265", nullptr));
        pushButton_selectFile->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        savePicture->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\321\203", nullptr));
        saveGif->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \320\263\320\270\321\204\320\272\321\203", nullptr));
        scaling->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        scaleToCenter->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        scaleOptimize->setText(QCoreApplication::translate("MainWindow", "\320\222\320\277\320\270\321\201\320\260\321\202\321\214 \320\262 \321\215\320\272\321\200\320\260\320\275", nullptr));
        scaleDown->setText(QCoreApplication::translate("MainWindow", "<<", nullptr));
        scaleUp->setText(QCoreApplication::translate("MainWindow", ">>", nullptr));
        moving->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        moveX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        moveY->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        moveZ->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        moveBack->setText(QCoreApplication::translate("MainWindow", "<<", nullptr));
        moveForward->setText(QCoreApplication::translate("MainWindow", ">>", nullptr));
        rotating->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265", nullptr));
        rotateX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        rotateY->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        rotateZ->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        rotateBack->setText(QCoreApplication::translate("MainWindow", "<<", nullptr));
        rotateForward->setText(QCoreApplication::translate("MainWindow", ">>", nullptr));
        viewingArea->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\276\320\261\320\273\320\260\321\201\321\202\320\270 \320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\260", nullptr));
        perspective->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\321\201\320\277\320\265\320\272\321\202\320\270\320\262\320\275\320\260\321\217 \320\277\321\200\320\276\320\265\320\272\321\206\320\270\321\217", nullptr));
        bgColorBtn->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        edgeSet->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \321\200\321\221\320\261\320\265\321\200", nullptr));
        edgeDashChk->setText(QCoreApplication::translate("MainWindow", "\320\237\321\203\320\275\320\272\321\202\320\270\321\200", nullptr));
        edgeThickLbl->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260", nullptr));
        edgeColorBtn->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        vertexSet->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\262\320\265\321\200\321\210\320\270\320\275", nullptr));
        displayMethodNot->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));
        displayMethodSphere->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        displayMethodCube->setText(QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));
        vSizeLbl->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200", nullptr));
        vColorBtn->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        emptyArea->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
