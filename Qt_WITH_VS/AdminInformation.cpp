#include "AdminInformation.h"
//extern ADMIN_User AdminUser[SIZE];
extern vector<ADMIN_User>AdminUser;
extern int Pos;
extern int type;//= 1则为管理员 = 2则为学生 = 3则为教职工 = 4则为访客 = 5则为未注册的访客
int clickCount;//记录点击次数
int pwdLen;//密码长度
QString HiddenPwd;//由‘*’构成，表示隐藏的密码
AdminInformation::AdminInformation(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle("我的个人信息");
	if (type == 1)
	{
		ui.classText->setText("管理员");
		ui.usernameText->setText(AdminUser[Pos].getUsername());
		pwdLen = AdminUser[Pos].getPassword().size();//获取密码长度，初始化为Size长度的'*'
		HiddenPwd.fill('*', pwdLen);
		ui.passwordText->setText(HiddenPwd);
	}
}

AdminInformation::~AdminInformation()
{
}

void AdminInformation::on_pwdCheck_clicked()
{
	clickCount++;
	if (clickCount & 1)//奇数次，则显示密码
	{
		ui.passwordText->setText(AdminUser[Pos].getPassword());
	}
	else
	{
		ui.passwordText->setText(HiddenPwd);
	}
}

void AdminInformation::on_changeInformation_clicked()
{
	ChangeAdminInformation* CAd = new ChangeAdminInformation;
	CAd->show();
}

void AdminInformation::on_flushBtn_clicked()
{
	ui.usernameText->setText(AdminUser[Pos].getUsername());
	pwdLen = AdminUser[Pos].getPassword().size();
	HiddenPwd.fill('*', pwdLen);
	if (clickCount & 1)//奇数次，则显示密码
	{
		ui.passwordText->setText(AdminUser[Pos].getPassword());
	}
	else
	{
		ui.passwordText->setText(HiddenPwd);
	}
}