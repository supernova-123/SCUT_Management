/********************************************************************************
** Form generated from reading UI file 'mainUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINUI_H
#define UI_MAINUI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainUIClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QPushButton *information;
    QPushButton *student;
    QPushButton *teacher;
    QPushButton *visitor;
    QPushButton *addAdmin;
    QPushButton *logout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *Data;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mainUIClass)
    {
        if (mainUIClass->objectName().isEmpty())
            mainUIClass->setObjectName(QString::fromUtf8("mainUIClass"));
        mainUIClass->setEnabled(true);
        mainUIClass->resize(214, 242);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/myIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        mainUIClass->setWindowIcon(icon);
        centralWidget = new QWidget(mainUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        information = new QPushButton(centralWidget);
        information->setObjectName(QString::fromUtf8("information"));

        verticalLayout_3->addWidget(information);

        student = new QPushButton(centralWidget);
        student->setObjectName(QString::fromUtf8("student"));

        verticalLayout_3->addWidget(student);

        teacher = new QPushButton(centralWidget);
        teacher->setObjectName(QString::fromUtf8("teacher"));

        verticalLayout_3->addWidget(teacher);

        visitor = new QPushButton(centralWidget);
        visitor->setObjectName(QString::fromUtf8("visitor"));

        verticalLayout_3->addWidget(visitor);

        addAdmin = new QPushButton(centralWidget);
        addAdmin->setObjectName(QString::fromUtf8("addAdmin"));

        verticalLayout_3->addWidget(addAdmin);

        logout = new QPushButton(centralWidget);
        logout->setObjectName(QString::fromUtf8("logout"));

        verticalLayout_3->addWidget(logout);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 30));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        Data = new QLabel(centralWidget);
        Data->setObjectName(QString::fromUtf8("Data"));
        Data->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(Data);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        mainUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 214, 22));
        mainUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mainUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(mainUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        mainUIClass->setStatusBar(statusBar);

        retranslateUi(mainUIClass);

        QMetaObject::connectSlotsByName(mainUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainUIClass)
    {
        mainUIClass->setWindowTitle(QCoreApplication::translate("mainUIClass", "mainUI", nullptr));
        information->setText(QCoreApplication::translate("mainUIClass", "\346\210\221\347\232\204\344\277\241\346\201\257", nullptr));
        student->setText(QCoreApplication::translate("mainUIClass", "\346\237\245\347\234\213\345\255\246\347\224\237\345\220\215\345\215\225", nullptr));
        teacher->setText(QCoreApplication::translate("mainUIClass", "\346\237\245\347\234\213\346\225\231\350\201\214\345\267\245\345\220\215\345\215\225", nullptr));
        visitor->setText(QCoreApplication::translate("mainUIClass", "\346\237\245\347\234\213\350\256\277\345\256\242\345\220\215\345\215\225", nullptr));
        addAdmin->setText(QCoreApplication::translate("mainUIClass", "\346\267\273\345\212\240/\345\210\240\351\231\244\347\256\241\347\220\206\345\221\230", nullptr));
        logout->setText(QCoreApplication::translate("mainUIClass", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("mainUIClass", "\344\273\212\346\227\245\345\271\277\344\270\234\347\226\253\346\203\205", nullptr));
        Data->setText(QCoreApplication::translate("mainUIClass", "123", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainUIClass: public Ui_mainUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUI_H
