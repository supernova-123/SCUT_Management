/********************************************************************************
** Form generated from reading UI file 'AdminWidgets.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWIDGETS_H
#define UI_ADMINWIDGETS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWidgets
{
public:

    void setupUi(QWidget *AdminWidgets)
    {
        if (AdminWidgets->objectName().isEmpty())
            AdminWidgets->setObjectName(QString::fromUtf8("AdminWidgets"));
        AdminWidgets->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/\344\272\272\345\221\230\345\210\227\350\241\250.png"), QSize(), QIcon::Normal, QIcon::Off);
        AdminWidgets->setWindowIcon(icon);

        retranslateUi(AdminWidgets);

        QMetaObject::connectSlotsByName(AdminWidgets);
    } // setupUi

    void retranslateUi(QWidget *AdminWidgets)
    {
        AdminWidgets->setWindowTitle(QCoreApplication::translate("AdminWidgets", "AdminWidgets", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWidgets: public Ui_AdminWidgets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIDGETS_H
