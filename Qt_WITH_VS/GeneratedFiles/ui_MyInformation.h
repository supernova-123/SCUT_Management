/********************************************************************************
** Form generated from reading UI file 'MyInformation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYINFORMATION_H
#define UI_MYINFORMATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyInformation
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *calssLabel;
    QLabel *nameLabel;
    QLabel *usernameLabel;
    QLabel *idLabel;
    QLabel *ageLabel;
    QLabel *buildingLabel;
    QLabel *roomLabel;
    QLabel *addressLabel;
    QLabel *phoneLabel;
    QLabel *starttimeLabel;
    QLabel *fintimeLabel;
    QVBoxLayout *verticalLayout_2;
    QLabel *classText;
    QLabel *nameText;
    QLabel *usernameText;
    QLabel *idText;
    QLabel *ageText;
    QLabel *buildingText;
    QLabel *roomText;
    QLabel *addressText;
    QLabel *phoneText;
    QLabel *starttimeText;
    QLabel *fintimeText;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *changeusername;
    QPushButton *changepassword;
    QPushButton *flushBtn;
    QLabel *label;

    void setupUi(QWidget *MyInformation)
    {
        if (MyInformation->objectName().isEmpty())
            MyInformation->setObjectName(QString::fromUtf8("MyInformation"));
        MyInformation->resize(280, 270);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/myinformation.png"), QSize(), QIcon::Normal, QIcon::Off);
        MyInformation->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(MyInformation);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        calssLabel = new QLabel(MyInformation);
        calssLabel->setObjectName(QString::fromUtf8("calssLabel"));

        verticalLayout->addWidget(calssLabel);

        nameLabel = new QLabel(MyInformation);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        verticalLayout->addWidget(nameLabel);

        usernameLabel = new QLabel(MyInformation);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        verticalLayout->addWidget(usernameLabel);

        idLabel = new QLabel(MyInformation);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));

        verticalLayout->addWidget(idLabel);

        ageLabel = new QLabel(MyInformation);
        ageLabel->setObjectName(QString::fromUtf8("ageLabel"));

        verticalLayout->addWidget(ageLabel);

        buildingLabel = new QLabel(MyInformation);
        buildingLabel->setObjectName(QString::fromUtf8("buildingLabel"));

        verticalLayout->addWidget(buildingLabel);

        roomLabel = new QLabel(MyInformation);
        roomLabel->setObjectName(QString::fromUtf8("roomLabel"));

        verticalLayout->addWidget(roomLabel);

        addressLabel = new QLabel(MyInformation);
        addressLabel->setObjectName(QString::fromUtf8("addressLabel"));

        verticalLayout->addWidget(addressLabel);

        phoneLabel = new QLabel(MyInformation);
        phoneLabel->setObjectName(QString::fromUtf8("phoneLabel"));

        verticalLayout->addWidget(phoneLabel);

        starttimeLabel = new QLabel(MyInformation);
        starttimeLabel->setObjectName(QString::fromUtf8("starttimeLabel"));

        verticalLayout->addWidget(starttimeLabel);

        fintimeLabel = new QLabel(MyInformation);
        fintimeLabel->setObjectName(QString::fromUtf8("fintimeLabel"));

        verticalLayout->addWidget(fintimeLabel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        classText = new QLabel(MyInformation);
        classText->setObjectName(QString::fromUtf8("classText"));

        verticalLayout_2->addWidget(classText);

        nameText = new QLabel(MyInformation);
        nameText->setObjectName(QString::fromUtf8("nameText"));

        verticalLayout_2->addWidget(nameText);

        usernameText = new QLabel(MyInformation);
        usernameText->setObjectName(QString::fromUtf8("usernameText"));

        verticalLayout_2->addWidget(usernameText);

        idText = new QLabel(MyInformation);
        idText->setObjectName(QString::fromUtf8("idText"));

        verticalLayout_2->addWidget(idText);

        ageText = new QLabel(MyInformation);
        ageText->setObjectName(QString::fromUtf8("ageText"));

        verticalLayout_2->addWidget(ageText);

        buildingText = new QLabel(MyInformation);
        buildingText->setObjectName(QString::fromUtf8("buildingText"));

        verticalLayout_2->addWidget(buildingText);

        roomText = new QLabel(MyInformation);
        roomText->setObjectName(QString::fromUtf8("roomText"));

        verticalLayout_2->addWidget(roomText);

        addressText = new QLabel(MyInformation);
        addressText->setObjectName(QString::fromUtf8("addressText"));

        verticalLayout_2->addWidget(addressText);

        phoneText = new QLabel(MyInformation);
        phoneText->setObjectName(QString::fromUtf8("phoneText"));

        verticalLayout_2->addWidget(phoneText);

        starttimeText = new QLabel(MyInformation);
        starttimeText->setObjectName(QString::fromUtf8("starttimeText"));

        verticalLayout_2->addWidget(starttimeText);

        fintimeText = new QLabel(MyInformation);
        fintimeText->setObjectName(QString::fromUtf8("fintimeText"));

        verticalLayout_2->addWidget(fintimeText);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        changeusername = new QPushButton(MyInformation);
        changeusername->setObjectName(QString::fromUtf8("changeusername"));

        horizontalLayout_2->addWidget(changeusername);

        changepassword = new QPushButton(MyInformation);
        changepassword->setObjectName(QString::fromUtf8("changepassword"));

        horizontalLayout_2->addWidget(changepassword);

        flushBtn = new QPushButton(MyInformation);
        flushBtn->setObjectName(QString::fromUtf8("flushBtn"));

        horizontalLayout_2->addWidget(flushBtn);


        verticalLayout_3->addLayout(horizontalLayout_2);

        label = new QLabel(MyInformation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);


        retranslateUi(MyInformation);

        QMetaObject::connectSlotsByName(MyInformation);
    } // setupUi

    void retranslateUi(QWidget *MyInformation)
    {
        MyInformation->setWindowTitle(QCoreApplication::translate("MyInformation", "MyInformation", nullptr));
        calssLabel->setText(QCoreApplication::translate("MyInformation", "\346\210\221\347\232\204\350\272\253\344\273\275\357\274\232", nullptr));
        nameLabel->setText(QCoreApplication::translate("MyInformation", "\345\247\223\345\220\215\357\274\232", nullptr));
        usernameLabel->setText(QCoreApplication::translate("MyInformation", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        idLabel->setText(QCoreApplication::translate("MyInformation", "\345\255\246\345\217\267\357\274\232", nullptr));
        ageLabel->setText(QCoreApplication::translate("MyInformation", "\345\271\264\351\276\204\357\274\232", nullptr));
        buildingLabel->setText(QCoreApplication::translate("MyInformation", "\346\245\274\346\240\213/\346\211\200\345\234\250\345\215\225\344\275\215\357\274\232", nullptr));
        roomLabel->setText(QCoreApplication::translate("MyInformation", "\346\210\277\345\217\267/\345\212\236\345\205\254\345\256\244\357\274\232", nullptr));
        addressLabel->setText(QCoreApplication::translate("MyInformation", "\345\256\266\345\272\255\345\234\260\345\235\200\357\274\232", nullptr));
        phoneLabel->setText(QCoreApplication::translate("MyInformation", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", nullptr));
        starttimeLabel->setText(QCoreApplication::translate("MyInformation", "\347\225\231\346\240\241\350\265\267\345\247\213\346\227\266\351\227\264\357\274\232", nullptr));
        fintimeLabel->setText(QCoreApplication::translate("MyInformation", "\347\246\273\346\240\241\346\227\266\351\227\264\357\274\232", nullptr));
        classText->setText(QCoreApplication::translate("MyInformation", "identity", nullptr));
        nameText->setText(QCoreApplication::translate("MyInformation", "name", nullptr));
        usernameText->setText(QCoreApplication::translate("MyInformation", "username", nullptr));
        idText->setText(QCoreApplication::translate("MyInformation", "id", nullptr));
        ageText->setText(QCoreApplication::translate("MyInformation", "age", nullptr));
        buildingText->setText(QCoreApplication::translate("MyInformation", "building", nullptr));
        roomText->setText(QCoreApplication::translate("MyInformation", "room", nullptr));
        addressText->setText(QCoreApplication::translate("MyInformation", "address", nullptr));
        phoneText->setText(QCoreApplication::translate("MyInformation", "phonenumber", nullptr));
        starttimeText->setText(QCoreApplication::translate("MyInformation", "starttime", nullptr));
        fintimeText->setText(QCoreApplication::translate("MyInformation", "fintime", nullptr));
        changeusername->setText(QCoreApplication::translate("MyInformation", "\344\277\256\346\224\271\347\224\250\346\210\267\345\220\215", nullptr));
        changepassword->setText(QCoreApplication::translate("MyInformation", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        flushBtn->setText(QCoreApplication::translate("MyInformation", "\345\210\267\346\226\260", nullptr));
        label->setText(QCoreApplication::translate("MyInformation", "\346\263\250\346\204\217\357\274\232\344\277\256\346\224\271\345\205\266\344\273\226\344\277\241\346\201\257\350\257\267\345\220\221\347\256\241\347\220\206\345\221\230\347\224\263\350\257\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyInformation: public Ui_MyInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYINFORMATION_H
