/********************************************************************************
** Form generated from reading UI file 'NetworkDetect.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKDETECT_H
#define UI_NETWORKDETECT_H

#include <QtCore/QThread>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>

QT_BEGIN_NAMESPACE

class Ui_NetworkDetect
{
public:

    void setupUi(QThread *NetworkDetect)
    {
        if (NetworkDetect->objectName().isEmpty())
            NetworkDetect->setObjectName(QString::fromUtf8("NetworkDetect"));
        //NetworkDetect->resize(400, 300);

        retranslateUi(NetworkDetect);

        QMetaObject::connectSlotsByName(NetworkDetect);
    } // setupUi

    void retranslateUi(QThread *NetworkDetect)
    {
        //NetworkDetect->setWindowTitle(QCoreApplication::translate("NetworkDetect", "NetworkDetect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetworkDetect: public Ui_NetworkDetect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKDETECT_H
