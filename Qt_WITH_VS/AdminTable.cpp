#include "AdminTable.h"
extern vector<ADMIN_User>AdminUser;
AdminTable::AdminTable(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle("管理员信息");

	//设置groupbox属性
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//以行尾为单位
	ui.tableWidget->setSortingEnabled(true);
	flushTable();
	//当用户更改某个单元格内的内容时，调用 changeMess() 函数处理
	//当向输入框内输入信息后，执行 findMess() 
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
				ui.tableWidget->selectRow(i);//高亮这一行
				break;
			}
		}
		if (findSuccess == false)
		{
			QMessageBox::information(this, "查找失败", "当前表格中没有【" + ui.FindEdit->text() + "】");
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