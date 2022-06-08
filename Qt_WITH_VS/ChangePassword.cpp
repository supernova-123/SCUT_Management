#include "ChangePassword.h"
extern int Pos;
extern int type;
extern vector<ADMIN_User>AdminUser;
extern TEACHER_User TeacherUser[SIZE];
extern STUDENT_User StudentUser[SIZE];
extern VISITOR_User VisitorUser[SIZE];
ChangePassword::ChangePassword(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle("修改密码");
	ui.oldPasswordEdit->setClearButtonEnabled(true);
	ui.newPasswordEdit->setClearButtonEnabled(true);
	ui.confirmPasswordEdit->setClearButtonEnabled(true);
}

ChangePassword::~ChangePassword()
{
}

void ChangePassword::on_OK_clicked()
{
	QString oldPwd = ui.oldPasswordEdit->text();
	QString newPwd = ui.newPasswordEdit->text();
	QString confirmNewPwd = ui.confirmPasswordEdit->text();
	//创建User对象的指针，根据不同的type指向不同的对象
	User* us;
	if (type == 2) us = &StudentUser[Pos];
	else if (type == 3)us = &TeacherUser[Pos];
	else us = &VisitorUser[Pos];
	if (oldPwd.isEmpty() || newPwd.isEmpty() || confirmNewPwd.isEmpty())
	{
		QMessageBox::warning(this, tr("错误"), tr("密码不能为空！"), QMessageBox::Ok);
		return;
	}
	if (oldPwd != us->getPassword())
	{
		QMessageBox::warning(this, tr("错误"), tr("输入的旧密码与实际密码不一致！"), QMessageBox::Ok);
		return;
	}
	else if (newPwd != confirmNewPwd)
	{
		QMessageBox::warning(this, tr("错误"), tr("两次输入的新密码不一致！"), QMessageBox::Ok);
		return;
	}
	us->setPassword(newPwd);
	us->save();
	QMessageBox::information(this, tr("提示"), tr("修改成功！"), QMessageBox::Ok);
	close();
}

void ChangePassword::on_NO_clicked()
{
	close();
}