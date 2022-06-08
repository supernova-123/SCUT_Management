/********************************************************************************
** Form generated from reading UI file 'ChangeAdminInformation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEADMININFORMATION_H
#define UI_CHANGEADMININFORMATION_H

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

class Ui_ChangeAdminInformation
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *OK;
    QPushButton *NO;

    void setupUi(QWidget *ChangeAdminInformation)
    {
        if (ChangeAdminInformation->objectName().isEmpty())
            ChangeAdminInformation->setObjectName(QString::fromUtf8("ChangeAdminInformation"));
        ChangeAdminInformation->resize(201, 149);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/\344\277\256\346\224\271\344\277\241\346\201\257.png"), QSize(), QIcon::Normal, QIcon::Off);
        ChangeAdminInformation->setWindowIcon(icon);
        gridLayout = new QGridLayout(ChangeAdminInformation);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        usernameLabel = new QLabel(ChangeAdminInformation);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        horizontalLayout->addWidget(usernameLabel);

        usernameEdit = new QLineEdit(ChangeAdminInformation);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));

        horizontalLayout->addWidget(usernameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        passwordLabel = new QLabel(ChangeAdminInformation);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        horizontalLayout_2->addWidget(passwordLabel);

        passwordEdit = new QLineEdit(ChangeAdminInformation);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));

        horizontalLayout_2->addWidget(passwordEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        OK = new QPushButton(ChangeAdminInformation);
        OK->setObjectName(QString::fromUtf8("OK"));

        horizontalLayout_3->addWidget(OK);

        NO = new QPushButton(ChangeAdminInformation);
        NO->setObjectName(QString::fromUtf8("NO"));

        horizontalLayout_3->addWidget(NO);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(ChangeAdminInformation);

        QMetaObject::connectSlotsByName(ChangeAdminInformation);
    } // setupUi

    void retranslateUi(QWidget *ChangeAdminInformation)
    {
        ChangeAdminInformation->setWindowTitle(QCoreApplication::translate("ChangeAdminInformation", "ChangeAdminInformation", nullptr));
        usernameLabel->setText(QCoreApplication::translate("ChangeAdminInformation", "\347\224\250\346\210\267\345\220\215", nullptr));
        passwordLabel->setText(QCoreApplication::translate("ChangeAdminInformation", "\345\257\206\347\240\201", nullptr));
        OK->setText(QCoreApplication::translate("ChangeAdminInformation", "\347\241\256\350\256\244", nullptr));
        NO->setText(QCoreApplication::translate("ChangeAdminInformation", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeAdminInformation: public Ui_ChangeAdminInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEADMININFORMATION_H
