#include "ChangeUsername.h"
extern STUDENT_User StudentUser[SIZE];
extern VISITOR_User VisitorUser[SIZE];
extern TEACHER_User TeacherUser[SIZE];
extern int Pos;
extern int type;
ChangeUsername::ChangeUsername(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle("修改用户名");
	ui.usernameEdit->setPlaceholderText("请输入新的用户名");
	ui.usernameEdit->setClearButtonEnabled(true);
}

ChangeUsername::~ChangeUsername()
{
}

void ChangeUsername::on_OK_clicked()
{
	QString qusername = ui.usernameEdit->text();
	if (type == 2)//学生
	{
		bool check = StudentUser[Pos].UserIsExisted(qusername);
		if (check)
		{
			QMessageBox::warning(this, tr("提示"), tr("用户名已被使用\n请更换另一个用户名"), QMessageBox::Ok);
			return;
		}
		//没问题就写入数组，然后写入文档
		StudentUser[Pos].setUsername(qusername);
		StudentUser[Pos].save();
	}
	else if (type == 3)//教职工
	{
		//for (int i = 0; i < SIZE && !TeacherUser[i].getUsername().isEmpty(); ++i)//数组内查重
		//{
		//	if (qusername == TeacherUser[i].getUsername())
		//	{
		//		if (i != Pos)
		//			QMessageBox::warning(this, tr("提示"), tr("用户名已被使用\n请更换另一个用户名"), QMessageBox::Ok);
		//		else
		//			QMessageBox::warning(this, tr("提示"), tr("新用户名不可与旧用户名重复\n请更换另一个用户名"), QMessageBox::Ok);
		//		return;
		//	}
		//}
		bool check = TeacherUser[Pos].UserIsExisted(qusername);
		if (check)
		{
			QMessageBox::warning(this, tr("提示"), tr("用户名已被使用\n请更换另一个用户名"), QMessageBox::Ok);
			return;
		}
		//没问题就写入数组，然后写入文档
		TeacherUser[Pos].setUsername(qusername);
		TeacherUser[Pos].save();
	}
	else//访客
	{
		bool check = VisitorUser[Pos].UserIsExisted(qusername);
		if (check)
		{
			QMessageBox::warning(this, tr("提示"), tr("用户名已被使用\n请更换另一个用户名"), QMessageBox::Ok);
			return;
		}
		//没问题就写入数组，然后写入文档
		VisitorUser[Pos].setUsername(qusername);
		VisitorUser[Pos].save();
	}
	QMessageBox::information(this, tr("提示"), tr("修改成功！"), QMessageBox::Ok);
	close();
}

void ChangeUsername::on_NO_clicked()
{
	close();
}