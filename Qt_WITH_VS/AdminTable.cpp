#include "AdminTable.h"
extern vector<ADMIN_User>AdminUser;
AdminTable::AdminTable(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle("����Ա��Ϣ");

	//����groupbox����
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//����βΪ��λ
	ui.tableWidget->setSortingEnabled(true);
	flushTable();
	//���û�����ĳ����Ԫ���ڵ�����ʱ������ changeMess() ��������
	//�����������������Ϣ��ִ�� findMess() 
	connect(ui.FindEdit, &QLineEdit::returnPressed, this, &AdminTable::findMess);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

AdminTable::~AdminTable()
{
}

void AdminTable::on_ExitBtn_clicked()
{
	close();
}

void AdminTable::flushTable() 
{
	disconnect(ui.tableWidget, &QTableWidget::cellChanged, 0, 0);
	ui.tableWidget->setSortingEnabled(false);
	ui.tableWidget->setRowCount(0);
	for (int i = 0; i <= SIZE && !AdminUser[i].getUsername().isEmpty();++i)
	{
		ui.tableWidget->setRowCount(ui.tableWidget->rowCount() + 1);
		ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(AdminUser[i].getUsername()));
		ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(AdminUser[i].getPassword()));
	}
	ui.tableWidget->setSortingEnabled(true);
}

void AdminTable::findMess()
{
	qint32 count = ui.tableWidget->rowCount();
	bool findSuccess = false;
	if (count > 0)
	{
		for (qint32 i = 0; i < count; ++i)
		{
			QString username = ui.tableWidget->item(i, 0)->text();
			if (username == ui.FindEdit->text())
			{
				findSuccess = true;
				ui.tableWidget->selectRow(i);//������һ��
				break;
			}
		}
		if (findSuccess == false)
		{
			QMessageBox::information(this, "����ʧ��", "��ǰ�����û�С�" + ui.FindEdit->text() + "��");
		}
	}
}

void AdminTable::on_addNdelBtn_clicked()
{
	AddAdmin* add;
	add = new AddAdmin;
	add->show();
}

void AdminTable::on_flushBtn_clicked()
{
	flushTable();
}

void AdminTable::on_modifyBtn_clicked()
{
	ChangeOtherAdmin* chg = new ChangeOtherAdmin;
	chg->show();
}