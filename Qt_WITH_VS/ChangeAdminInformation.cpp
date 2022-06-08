#include "ChangeAdminInformation.h"
//extern ADMIN_User AdminUser[SIZE];
extern vector<ADMIN_User>AdminUser;
extern int Pos;
ChangeAdminInformation::ChangeAdminInformation(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle("修改信息");
	QString name = AdminUser[Pos].getUsername();
	QString pwd = AdminUser[Pos].getPassword();
	ui.usernameEdit->setText(name);
	ui.usernameEdit->setClearButtonEnabled(true);
	ui.passwordEdit->setText(pwd);
	ui.passwordEdit->setClearButtonEnabled(true);
}

ChangeAdminInformation::~ChangeAdminInformation()
{
}

void ChangeAdminInformation::on_OK_clicked()
{
	//查找有无重复用户名
	QString name = ui.usernameEdit->text();
	QString pwd = ui.passwordEdit->text();
	for (int i = 0; i < SIZE && !AdminUser[i].getUsername().isEmpty(); ++i)
	{
		if (AdminUser[i].getUsername() == name && i != Pos)
		{
			QMessageBox::warning(this, tr("警告"), tr("用户名重复，请重新输入！"), QMessageBox::Ok);
			return;
		}
	}
	AdminUser[Pos].setUsername(name);
	AdminUser[Pos].setPassword(pwd);
	//保存在文件中
	AdminUser[Pos].total_save();
	QMessageBox::information(this, tr("提示"), tr("修改成功！"), QMessageBox::Ok);
	close();
}

void ChangeAdminInformation::on_NO_clicked()
{
	close();
}