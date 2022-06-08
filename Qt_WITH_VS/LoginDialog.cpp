#include "mainUI.h"
#include<qsavefile.h>
#include<qdialog.h>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include"qlineedit.h"
#include<qstring.h>
#include "LoginDialog.h"
#include"Login.h"
int type;//=1则为管理员 =2则为学生 =3则为教职工 =4则为访客 =5则为未注册的访客
int Pos;//表示在数组中的位置
extern vector<ADMIN_User>AdminUser;
extern STUDENT_User StudentUser[SIZE];
extern VISITOR_User VisitorUser[SIZE];
extern TEACHER_User TeacherUser[SIZE];
extern int stucount; extern int viscount; extern int adscount; extern int teacount;
extern int superAdmin;
LoginDialog::LoginDialog(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//在初始页面构造的时候录入人员
	stucount = StudentUser[0].read();
	viscount = VisitorUser[0].read();
	adscount = AdminUser[0].read();
	teacount = TeacherUser[0].read();
	int a = 0;
}

LoginDialog::~LoginDialog()
{

}

//登录按钮点击事件
void LoginDialog::on_Login_clicked()
{
	// 判断用户名和密码是否正确，
	// 如果错误则弹出警告对话框	
	if (ui.checkAdmin->isChecked())
	{
		bool success = 0;
		for (int i = 0; i < adscount; ++i)
		{
			if (ui.Username->text() == (AdminUser[i].getUsername()) &&
				ui.Password->text() == (AdminUser[i].getPassword()))
			{
				//判断是不是超级管理员
				if (ui.Username->text() == AdminUser[0].getUsername()) superAdmin = -1;
				success = 1;
				type = 1;
				Pos = i;
				accept();
			}
		}
		if (!success)
		{
			QMessageBox::warning(this, tr("警告！"),
				tr("用户名或密码错误！"),
				QMessageBox::Yes);
		}
	}
	else if (ui.checkStu->isChecked())//学生
	{
		bool success = 0;
		for (int i = 0; i < stucount; ++i)
		{
			if (ui.Username->text() == (StudentUser[i].getUsername()) &&
				ui.Password->text() == (StudentUser[i].getPassword()) && 
				StudentUser[i].getClass() == "学生")
			{
				success = 1;
				type = 2;
				Pos = i;
				accept();
			}
		}
		if (!success)
		{
			QMessageBox::warning(this, tr("警告！"),
				tr("用户名或密码错误！"),
				QMessageBox::Yes);
		}
	}
	else if (ui.checkTea->isChecked())//教职工
	{
		bool success = 0;
		for (int i = 0; i < teacount; ++i)
		{
			if (ui.Username->text() == (TeacherUser[i].getUsername()) &&
				ui.Password->text() == (TeacherUser[i].getPassword()))
			{
				success = 1;
				type = 3;
				Pos = i;
				accept();
			}
		}
		if (!success)
		{
			QMessageBox::warning(this, tr("警告！"),
				tr("用户名或密码错误！"),
				QMessageBox::Yes);
		}
	}
	else if (ui.checkVis->isChecked())
	{
		bool success = 0;
		for (int i = 0; i < viscount; ++i)
		{
			if (ui.Username->text() == (VisitorUser[i].getUsername()) &&
				ui.Password->text() == (VisitorUser[i].getPassword()))
			{
				type = 4;
				Pos = i;
				success = 1;
				accept();
			}
		}
		if (!success)
		{
			QMessageBox::warning(this, tr("警告！"),
				tr("用户名或密码错误！"),
				QMessageBox::Yes);
		}
	}
	else if (ui.checkNone->isChecked())
	{
		type = 5;
		accept();
	}
	else
	{
		QMessageBox::warning(this, tr("警告！"),
			tr("请选择您的登录身份！"),
			QMessageBox::Yes);
	}
}

void LoginDialog::on_Exit_clicked()
{
	close();
}