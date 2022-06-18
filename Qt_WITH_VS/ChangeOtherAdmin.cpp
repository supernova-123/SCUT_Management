#include "ChangeOtherAdmin.h"
extern vector<ADMIN_User>AdminUser;
ChangeOtherAdmin::ChangeOtherAdmin(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle("修改指定管理员信息");
	ui.newnameedit->setPlaceholderText("用户名应不长于35个字符");
	ui.newpwdedit->setPlaceholderText("密码应不长于35个字符");
	//限制用户名和密码长度
	ui.newnameedit->setMaxLength(35);
	ui.newpwdedit->setMaxLength(35);
}

ChangeOtherAdmin::~ChangeOtherAdmin()
{
}

void ChangeOtherAdmin::on_no_clicked()
{
	close();
}

void ChangeOtherAdmin::on_ok_clicked()
{
	QString oldname = ui.oldnameedit->text();
	QString newname = ui.newnameedit->text();
	QString newpwd = ui.newpwdedit->text();

	int p = AdminUser[0].UserIsExisted(oldname);
	if (!p)
	{
		QMessageBox::warning(this, tr("提示"), tr("未找到用户【 %1 】").arg(oldname), QMessageBox::Ok);
		return;
	}
	int check2 = AdminUser[0].UserIsExisted(newname);
	if (check2 && oldname != newname)
	{
		QMessageBox::warning(this, tr("提示"), tr("已存在该用户，请更换用户名！"), QMessageBox::Ok);
		return;
	}
	--p;//取消返回值为p+1带来的误差
	//前面的都通过的，就放到数组里
	AdminUser[p].setUsername(newname); AdminUser[p].setPassword(newpwd);
	buildHash(newname.length(), AdminUser[p].hash, newname);
	AdminUser[0].total_save();//保存到文件中
	QMessageBox::information(this, tr("提示"), tr("保存成功！"), QMessageBox::Ok);
	close();
}