/********************************************************************************
** Form generated from reading UI file 'AddAdmin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDADMIN_H
#define UI_ADDADMIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddAdmin
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *yesBtn;
    QPushButton *delBtn;
    QPushButton *noBtn;

    void setupUi(QWidget *AddAdmin)
    {
        if (AddAdmin->objectName().isEmpty())
            AddAdmin->setObjectName(QString::fromUtf8("AddAdmin"));
        AddAdmin->resize(259, 105);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/\350\257\225\347\224\250\350\275\254\346\255\243\347\224\263\350\257\267.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddAdmin->setWindowIcon(icon);
        gridLayout = new QGridLayout(AddAdmin);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        usernameEdit = new QLineEdit(AddAdmin);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));

        verticalLayout->addWidget(usernameEdit);

        passwordEdit = new QLineEdit(AddAdmin);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        verticalLayout->addWidget(passwordEdit);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        yesBtn = new QPushButton(AddAdmin);
        yesBtn->setObjectName(QString::fromUtf8("yesBtn"));

        horizontalLayout->addWidget(yesBtn);

        delBtn = new QPushButton(AddAdmin);
        delBtn->setObjectName(QString::fromUtf8("delBtn"));

        horizontalLayout->addWidget(delBtn);

        noBtn = new QPushButton(AddAdmin);
        noBtn->setObjectName(QString::fromUtf8("noBtn"));

        horizontalLayout->addWidget(noBtn);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(AddAdmin);

        QMetaObject::connectSlotsByName(AddAdmin);
    } // setupUi

    void retranslateUi(QWidget *AddAdmin)
    {
        AddAdmin->setWindowTitle(QCoreApplication::translate("AddAdmin", "AddAdmin", nullptr));
        yesBtn->setText(QCoreApplication::translate("AddAdmin", "\347\241\256\345\256\232\346\267\273\345\212\240", nullptr));
        delBtn->setText(QCoreApplication::translate("AddAdmin", "\347\241\256\345\256\232\345\210\240\351\231\244", nullptr));
        noBtn->setText(QCoreApplication::translate("AddAdmin", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddAdmin: public Ui_AddAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDADMIN_H
