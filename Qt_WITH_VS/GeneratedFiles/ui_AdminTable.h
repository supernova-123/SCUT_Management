/********************************************************************************
** Form generated from reading UI file 'AdminTable.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINTABLE_H
#define UI_ADMINTABLE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminTable
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addNdelBtn;
    QPushButton *modifyBtn;
    QLineEdit *FindEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *flushBtn;
    QPushButton *ExitBtn;

    void setupUi(QWidget *AdminTable)
    {
        if (AdminTable->objectName().isEmpty())
            AdminTable->setObjectName(QString::fromUtf8("AdminTable"));
        AdminTable->resize(317, 390);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/\346\225\231\350\201\214\345\267\245\344\277\241\346\201\257\345\217\230\346\233\264.png"), QSize(), QIcon::Normal, QIcon::Off);
        AdminTable->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(AdminTable);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(AdminTable);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget = new QTableWidget(groupBox);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setFrameShape(QFrame::StyledPanel);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addNdelBtn = new QPushButton(groupBox);
        addNdelBtn->setObjectName(QString::fromUtf8("addNdelBtn"));

        horizontalLayout->addWidget(addNdelBtn);

        modifyBtn = new QPushButton(groupBox);
        modifyBtn->setObjectName(QString::fromUtf8("modifyBtn"));

        horizontalLayout->addWidget(modifyBtn);


        verticalLayout_2->addLayout(horizontalLayout);

        FindEdit = new QLineEdit(groupBox);
        FindEdit->setObjectName(QString::fromUtf8("FindEdit"));

        verticalLayout_2->addWidget(FindEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        flushBtn = new QPushButton(groupBox);
        flushBtn->setObjectName(QString::fromUtf8("flushBtn"));

        horizontalLayout_2->addWidget(flushBtn);

        ExitBtn = new QPushButton(groupBox);
        ExitBtn->setObjectName(QString::fromUtf8("ExitBtn"));

        horizontalLayout_2->addWidget(ExitBtn);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(groupBox);


        retranslateUi(AdminTable);

        QMetaObject::connectSlotsByName(AdminTable);
    } // setupUi

    void retranslateUi(QWidget *AdminTable)
    {
        AdminTable->setWindowTitle(QCoreApplication::translate("AdminTable", "AdminTable", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AdminTable", "\347\256\241\347\220\206\345\221\230\344\277\241\346\201\257", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AdminTable", "\347\224\250\346\210\267\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AdminTable", "\345\257\206\347\240\201", nullptr));
        addNdelBtn->setText(QCoreApplication::translate("AdminTable", "\346\267\273\345\212\240/\345\210\240\351\231\244\347\256\241\347\220\206\345\221\230", nullptr));
        modifyBtn->setText(QCoreApplication::translate("AdminTable", "\344\277\256\346\224\271\346\214\207\345\256\232\347\256\241\347\220\206\345\221\230", nullptr));
        FindEdit->setPlaceholderText(QCoreApplication::translate("AdminTable", "\350\276\223\345\205\245\350\246\201\346\237\245\346\211\276\347\232\204\347\224\250\346\210\267\345\220\215\357\274\214\346\214\211Enter\347\241\256\350\256\244...", nullptr));
        flushBtn->setText(QCoreApplication::translate("AdminTable", "\345\210\267\346\226\260", nullptr));
        ExitBtn->setText(QCoreApplication::translate("AdminTable", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminTable: public Ui_AdminTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINTABLE_H
