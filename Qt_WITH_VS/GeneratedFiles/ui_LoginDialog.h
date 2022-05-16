/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *Username;
    QLineEdit *Password;
    QVBoxLayout *verticalLayout;
    QLabel *UsernameLabel;
    QLabel *PasswordLabel;
    QPushButton *Login;
    QHBoxLayout *horizontalLayout;
    QRadioButton *checkAdmin;
    QRadioButton *checkStu;
    QRadioButton *checkTea;
    QRadioButton *checkVis;
    QRadioButton *checkNone;
    QPushButton *Exit;
    QLabel *Welcome;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(400, 245);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/\347\231\273\345\275\225.png"), QSize(), QIcon::Normal, QIcon::Off);
        LoginDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(LoginDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(LoginDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277\";"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        Username = new QLineEdit(frame);
        Username->setObjectName(QString::fromUtf8("Username"));

        verticalLayout_4->addWidget(Username);

        Password = new QLineEdit(frame);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setEchoMode(QLineEdit::Password);

        verticalLayout_4->addWidget(Password);


        gridLayout_2->addLayout(verticalLayout_4, 1, 1, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        UsernameLabel = new QLabel(frame);
        UsernameLabel->setObjectName(QString::fromUtf8("UsernameLabel"));
        UsernameLabel->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277\";"));

        verticalLayout->addWidget(UsernameLabel);

        PasswordLabel = new QLabel(frame);
        PasswordLabel->setObjectName(QString::fromUtf8("PasswordLabel"));
        PasswordLabel->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277\";"));

        verticalLayout->addWidget(PasswordLabel);


        gridLayout_2->addLayout(verticalLayout, 1, 0, 1, 1);

        Login = new QPushButton(frame);
        Login->setObjectName(QString::fromUtf8("Login"));
        Login->setStyleSheet(QString::fromUtf8("font: 10pt \"\347\255\211\347\272\277\";"));

        gridLayout_2->addWidget(Login, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkAdmin = new QRadioButton(frame);
        checkAdmin->setObjectName(QString::fromUtf8("checkAdmin"));
        checkAdmin->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277\";"));

        horizontalLayout->addWidget(checkAdmin);

        checkStu = new QRadioButton(frame);
        checkStu->setObjectName(QString::fromUtf8("checkStu"));
        checkStu->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277\";"));

        horizontalLayout->addWidget(checkStu);

        checkTea = new QRadioButton(frame);
        checkTea->setObjectName(QString::fromUtf8("checkTea"));

        horizontalLayout->addWidget(checkTea);

        checkVis = new QRadioButton(frame);
        checkVis->setObjectName(QString::fromUtf8("checkVis"));
        checkVis->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277\";"));

        horizontalLayout->addWidget(checkVis);

        checkNone = new QRadioButton(frame);
        checkNone->setObjectName(QString::fromUtf8("checkNone"));

        horizontalLayout->addWidget(checkNone);


        gridLayout_2->addLayout(horizontalLayout, 2, 1, 1, 2);

        Exit = new QPushButton(frame);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setStyleSheet(QString::fromUtf8("font: 75 10pt \"\347\255\211\347\272\277\";"));

        gridLayout_2->addWidget(Exit, 3, 2, 1, 1);

        Welcome = new QLabel(frame);
        Welcome->setObjectName(QString::fromUtf8("Welcome"));
        Welcome->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));

        gridLayout_2->addWidget(Welcome, 0, 0, 1, 3);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "LoginDialog", nullptr));
        label_3->setText(QCoreApplication::translate("LoginDialog", "\346\202\250\347\232\204\350\272\253\344\273\275", nullptr));
        Username->setText(QString());
        Password->setText(QString());
        UsernameLabel->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        PasswordLabel->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        Login->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        checkAdmin->setText(QCoreApplication::translate("LoginDialog", "\347\256\241\347\220\206\345\221\230", nullptr));
        checkStu->setText(QCoreApplication::translate("LoginDialog", "\345\255\246\347\224\237", nullptr));
        checkTea->setText(QCoreApplication::translate("LoginDialog", "\346\225\231\350\201\214\345\267\245", nullptr));
        checkVis->setText(QCoreApplication::translate("LoginDialog", "\350\256\277\345\256\242", nullptr));
        checkNone->setText(QCoreApplication::translate("LoginDialog", "\346\234\252\346\263\250\345\206\214\350\256\277\345\256\242", nullptr));
        Exit->setText(QCoreApplication::translate("LoginDialog", "\351\200\200\345\207\272", nullptr));
        Welcome->setText(QCoreApplication::translate("LoginDialog", "           \346\254\242\350\277\216\346\235\245\345\210\260SCUT\347\225\231\346\240\241\344\272\272\345\221\230\347\256\241\347\220\206\347\263\273\347\273\237\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
