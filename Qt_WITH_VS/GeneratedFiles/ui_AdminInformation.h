/********************************************************************************
** Form generated from reading UI file 'AdminInformation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMININFORMATION_H
#define UI_ADMININFORMATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminInformation
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *classLabel;
    QLabel *classText;
    QHBoxLayout *horizontalLayout_5;
    QLabel *usernameLabel;
    QLabel *usernameText;
    QHBoxLayout *horizontalLayout_6;
    QLabel *passwordLabel;
    QLabel *passwordText;
    QCheckBox *pwdCheck;
    QHBoxLayout *horizontalLayout;
    QPushButton *changeInformation;
    QPushButton *flushBtn;

    void setupUi(QWidget *AdminInformation)
    {
        if (AdminInformation->objectName().isEmpty())
            AdminInformation->setObjectName(QString::fromUtf8("AdminInformation"));
        AdminInformation->resize(187, 164);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/myinformation.png"), QSize(), QIcon::Normal, QIcon::Off);
        AdminInformation->setWindowIcon(icon);
        gridLayout = new QGridLayout(AdminInformation);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        classLabel = new QLabel(AdminInformation);
        classLabel->setObjectName(QString::fromUtf8("classLabel"));

        horizontalLayout_4->addWidget(classLabel);

        classText = new QLabel(AdminInformation);
        classText->setObjectName(QString::fromUtf8("classText"));

        horizontalLayout_4->addWidget(classText);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        usernameLabel = new QLabel(AdminInformation);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        horizontalLayout_5->addWidget(usernameLabel);

        usernameText = new QLabel(AdminInformation);
        usernameText->setObjectName(QString::fromUtf8("usernameText"));

        horizontalLayout_5->addWidget(usernameText);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        passwordLabel = new QLabel(AdminInformation);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        horizontalLayout_6->addWidget(passwordLabel);

        passwordText = new QLabel(AdminInformation);
        passwordText->setObjectName(QString::fromUtf8("passwordText"));

        horizontalLayout_6->addWidget(passwordText);

        pwdCheck = new QCheckBox(AdminInformation);
        pwdCheck->setObjectName(QString::fromUtf8("pwdCheck"));

        horizontalLayout_6->addWidget(pwdCheck);


        gridLayout->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        changeInformation = new QPushButton(AdminInformation);
        changeInformation->setObjectName(QString::fromUtf8("changeInformation"));

        horizontalLayout->addWidget(changeInformation);

        flushBtn = new QPushButton(AdminInformation);
        flushBtn->setObjectName(QString::fromUtf8("flushBtn"));

        horizontalLayout->addWidget(flushBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);


        retranslateUi(AdminInformation);

        QMetaObject::connectSlotsByName(AdminInformation);
    } // setupUi

    void retranslateUi(QWidget *AdminInformation)
    {
        AdminInformation->setWindowTitle(QCoreApplication::translate("AdminInformation", "AdminInformation", nullptr));
        classLabel->setText(QCoreApplication::translate("AdminInformation", "\346\210\221\347\232\204\350\272\253\344\273\275\357\274\232", nullptr));
        classText->setText(QCoreApplication::translate("AdminInformation", "identity", nullptr));
        usernameLabel->setText(QCoreApplication::translate("AdminInformation", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        usernameText->setText(QCoreApplication::translate("AdminInformation", "username", nullptr));
        passwordLabel->setText(QCoreApplication::translate("AdminInformation", "\345\257\206\347\240\201\357\274\232", nullptr));
        passwordText->setText(QCoreApplication::translate("AdminInformation", "password", nullptr));
        pwdCheck->setText(QCoreApplication::translate("AdminInformation", "\346\230\276\347\244\272\345\257\206\347\240\201", nullptr));
        changeInformation->setText(QCoreApplication::translate("AdminInformation", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        flushBtn->setText(QCoreApplication::translate("AdminInformation", "\345\210\267\346\226\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminInformation: public Ui_AdminInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMININFORMATION_H
