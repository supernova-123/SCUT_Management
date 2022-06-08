/********************************************************************************
** Form generated from reading UI file 'ChangeOtherAdmin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEOTHERADMIN_H
#define UI_CHANGEOTHERADMIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeOtherAdmin
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *oldName;
    QLabel *newName;
    QLabel *pwd;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *oldnameedit;
    QLineEdit *newnameedit;
    QLineEdit *newpwdedit;
    QHBoxLayout *horizontalLayout;
    QPushButton *ok;
    QPushButton *no;

    void setupUi(QWidget *ChangeOtherAdmin)
    {
        if (ChangeOtherAdmin->objectName().isEmpty())
            ChangeOtherAdmin->setObjectName(QString::fromUtf8("ChangeOtherAdmin"));
        ChangeOtherAdmin->resize(222, 162);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/addNewFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        ChangeOtherAdmin->setWindowIcon(icon);
        gridLayout = new QGridLayout(ChangeOtherAdmin);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        oldName = new QLabel(ChangeOtherAdmin);
        oldName->setObjectName(QString::fromUtf8("oldName"));

        verticalLayout->addWidget(oldName);

        newName = new QLabel(ChangeOtherAdmin);
        newName->setObjectName(QString::fromUtf8("newName"));

        verticalLayout->addWidget(newName);

        pwd = new QLabel(ChangeOtherAdmin);
        pwd->setObjectName(QString::fromUtf8("pwd"));

        verticalLayout->addWidget(pwd);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        oldnameedit = new QLineEdit(ChangeOtherAdmin);
        oldnameedit->setObjectName(QString::fromUtf8("oldnameedit"));
        oldnameedit->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(oldnameedit);

        newnameedit = new QLineEdit(ChangeOtherAdmin);
        newnameedit->setObjectName(QString::fromUtf8("newnameedit"));
        newnameedit->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(newnameedit);

        newpwdedit = new QLineEdit(ChangeOtherAdmin);
        newpwdedit->setObjectName(QString::fromUtf8("newpwdedit"));
        newpwdedit->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(newpwdedit);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ok = new QPushButton(ChangeOtherAdmin);
        ok->setObjectName(QString::fromUtf8("ok"));

        horizontalLayout->addWidget(ok);

        no = new QPushButton(ChangeOtherAdmin);
        no->setObjectName(QString::fromUtf8("no"));

        horizontalLayout->addWidget(no);


        verticalLayout_3->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(ChangeOtherAdmin);

        QMetaObject::connectSlotsByName(ChangeOtherAdmin);
    } // setupUi

    void retranslateUi(QWidget *ChangeOtherAdmin)
    {
        ChangeOtherAdmin->setWindowTitle(QCoreApplication::translate("ChangeOtherAdmin", "ChangeOtherAdmin", nullptr));
        oldName->setText(QCoreApplication::translate("ChangeOtherAdmin", "\346\227\247\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        newName->setText(QCoreApplication::translate("ChangeOtherAdmin", "\346\226\260\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        pwd->setText(QCoreApplication::translate("ChangeOtherAdmin", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        ok->setText(QCoreApplication::translate("ChangeOtherAdmin", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        no->setText(QCoreApplication::translate("ChangeOtherAdmin", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeOtherAdmin: public Ui_ChangeOtherAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEOTHERADMIN_H
