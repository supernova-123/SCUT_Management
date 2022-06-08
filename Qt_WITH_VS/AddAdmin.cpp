#include "AddAdmin.h"
#include<algorithm>
//extern ADMIN_User AdminUser[SIZE];
extern vector<ADMIN_User>AdminUser;
extern int Pos;
extern int adscount;
AddAdmin::AddAdmin(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle("添加/删除管理员");
	ui.usernameEdit->setPlaceholderText("请输入用户名...");
	ui.usernameEdit->setClearButtonEnabled(true);
	ui.passwordEdit->setPlaceholderText("请输入密码...");
	ui.passwordEdit->setClearButtonEnabled(true);
}

AddAdmin::~AddAdmin()
{
}

void AddAdmin::on_yesBtn_clicked()
{
	if (adscount >= SIZE)
	{
		QMessageBox::warning(this, tr("提示"), tr("管理员人数已满！"), QMessageBox::Yes);
		return;
	}
	//读取用户名和密码
	QString username = ui.usernameEdit->text();
	QString password = ui.passwordEdit->text();
	if (username.isEmpty() || password.isEmpty())//为空则提示要填用户名和密码
	{
		QMessageBox::warning(this, tr("提示"), tr("请将用户名和密码填写完整"), QMessageBox::Yes);
		return;
	}
	bool check = AdminUser[Pos].UserIsExisted(username);
	if (check)
	{
		QMessageBox::warning(this, tr("提示"), tr("用户已存在，请更换用户名"), QMessageBox::Yes);
		return;
	}
	//加入文件中
	ADMIN_User ad;
	ad.setUsername(username);
	ad.setPassword(password);
	AdminUser.push_back(ad);//加入新管理员
	ad.save();//保存到文件中（往后追加），此处使用C++原始读取操作
	QMessageBox::information(this, tr("提示"), tr("添加成功！"), QMessageBox::Yes);
	ad.read();//重新排序
	close();
}
//删除管理员
void AddAdmin::on_delBtn_clicked()
{
	//读取用户名和密码
	QString username = ui.usernameEdit->text();
	QString password = ui.passwordEdit->text();
	AdminUser[0].read();
	if (username.isEmpty() || password.isEmpty())//为空则提示要填用户名和密码
	{
		QMessageBox::warning(this, tr("提示"), tr("请将用户名和密码填写完整"), QMessageBox::Yes);
		return;
	}
	if (username == AdminUser[Pos].getUsername())
	{
		QMessageBox::warning(this, tr("提示"), tr("不可删除自身用户"), QMessageBox::Yes);
		return;
	}
	int i = 0;
	for (auto it = AdminUser.begin();!AdminUser[i].getUsername().isEmpty()&&it != AdminUser.end();++i)
	{
		if (AdminUser[i].getUsername() == username && AdminUser[i].getPassword() == password)
		{
			AdminUser.erase(it);//删除
			AdminUser[0].total_save();//重新载入文件
			QMessageBox::information(this, tr("提示"), tr("删除成功！"), QMessageBox::Yes);
			AdminUser[0].read();
			close();
			return;
		}
		else
		{
			++it;
		}
	}
	QMessageBox::warning(this, tr("警告"), tr("未找到与填写密码匹配的【%1】！").arg(username), QMessageBox::Ok);
	return;
}
//取消就直接退出
void AddAdmin::on_noBtn_clicked()
{
	close();
}