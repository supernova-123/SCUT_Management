/********************************************************************************
** Form generated from reading UI file 'ChangePassword.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORD_H
#define UI_CHANGEPASSWORD_H

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

class Ui_ChangePassword
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *oldPasswordLabel;
    QLineEdit *oldPasswordEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *newPasswordLabel;
    QLineEdit *newPasswordEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *confirmPasswordLabel;
    QLineEdit *confirmPasswordEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *OK;
    QPushButton *NO;
    QLabel *label;

    void setupUi(QWidget *ChangePassword)
    {
        if (ChangePassword->objectName().isEmpty())
            ChangePassword->setObjectName(QString::fromUtf8("ChangePassword"));
        ChangePassword->resize(259, 146);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/\344\277\256\346\224\271\345\257\206\347\240\201.png"), QSize(), QIcon::Normal, QIcon::Off);
        ChangePassword->setWindowIcon(icon);
        gridLayout = new QGridLayout(ChangePassword);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        oldPasswordLabel = new QLabel(ChangePassword);
        oldPasswordLabel->setObjectName(QString::fromUtf8("oldPasswordLabel"));

        horizontalLayout->addWidget(oldPasswordLabel);

        oldPasswordEdit = new QLineEdit(ChangePassword);
        oldPasswordEdit->setObjectName(QString::fromUtf8("oldPasswordEdit"));
        oldPasswordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(oldPasswordEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        newPasswordLabel = new QLabel(ChangePassword);
        newPasswordLabel->setObjectName(QString::fromUtf8("newPasswordLabel"));

        horizontalLayout_2->addWidget(newPasswordLabel);

        newPasswordEdit = new QLineEdit(ChangePassword);
        newPasswordEdit->setObjectName(QString::fromUtf8("newPasswordEdit"));
        newPasswordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(newPasswordEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        confirmPasswordLabel = new QLabel(ChangePassword);
        confirmPasswordLabel->setObjectName(QString::fromUtf8("confirmPasswordLabel"));

        horizontalLayout_3->addWidget(confirmPasswordLabel);

        confirmPasswordEdit = new QLineEdit(ChangePassword);
        confirmPasswordEdit->setObjectName(QString::fromUtf8("confirmPasswordEdit"));
        confirmPasswordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(confirmPasswordEdit);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        OK = new QPushButton(ChangePassword);
        OK->setObjectName(QString::fromUtf8("OK"));

        horizontalLayout_4->addWidget(OK);

        NO = new QPushButton(ChangePassword);
        NO->setObjectName(QString::fromUtf8("NO"));

        horizontalLayout_4->addWidget(NO);


        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        label = new QLabel(ChangePassword);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);


        retranslateUi(ChangePassword);

        QMetaObject::connectSlotsByName(ChangePassword);
    } // setupUi

    void retranslateUi(QWidget *ChangePassword)
    {
        ChangePassword->setWindowTitle(QCoreApplication::translate("ChangePassword", "ChangePassword", nullptr));
        oldPasswordLabel->setText(QCoreApplication::translate("ChangePassword", "\346\227\247\345\257\206\347\240\201\357\274\232", nullptr));
        newPasswordLabel->setText(QCoreApplication::translate("ChangePassword", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        confirmPasswordLabel->setText(QCoreApplication::translate("ChangePassword", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        OK->setText(QCoreApplication::translate("ChangePassword", "\347\241\256\350\256\244", nullptr));
        NO->setText(QCoreApplication::translate("ChangePassword", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("ChangePassword", "\346\263\250\346\204\217\357\274\232\345\277\230\350\256\260\345\257\206\347\240\201\357\274\214\350\257\267\345\222\250\350\257\242\347\256\241\347\220\206\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePassword: public Ui_ChangePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
