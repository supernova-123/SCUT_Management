/********************************************************************************
** Form generated from reading UI file 'ChangeUsername.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEUSERNAME_H
#define UI_CHANGEUSERNAME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeUsername
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *usernameEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *OK;
    QPushButton *NO;

    void setupUi(QWidget *ChangeUsername)
    {
        if (ChangeUsername->objectName().isEmpty())
            ChangeUsername->setObjectName(QString::fromUtf8("ChangeUsername"));
        ChangeUsername->resize(236, 85);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/\347\224\250\346\210\267\345\220\215.png"), QSize(), QIcon::Normal, QIcon::Off);
        ChangeUsername->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(ChangeUsername);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        usernameEdit = new QLineEdit(ChangeUsername);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));
        usernameEdit->setEchoMode(QLineEdit::Normal);

        verticalLayout->addWidget(usernameEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        OK = new QPushButton(ChangeUsername);
        OK->setObjectName(QString::fromUtf8("OK"));

        horizontalLayout->addWidget(OK);

        NO = new QPushButton(ChangeUsername);
        NO->setObjectName(QString::fromUtf8("NO"));

        horizontalLayout->addWidget(NO);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ChangeUsername);

        QMetaObject::connectSlotsByName(ChangeUsername);
    } // setupUi

    void retranslateUi(QWidget *ChangeUsername)
    {
        ChangeUsername->setWindowTitle(QCoreApplication::translate("ChangeUsername", "ChangeUsername", nullptr));
        OK->setText(QCoreApplication::translate("ChangeUsername", "\347\241\256\350\256\244", nullptr));
        NO->setText(QCoreApplication::translate("ChangeUsername", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeUsername: public Ui_ChangeUsername {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEUSERNAME_H
