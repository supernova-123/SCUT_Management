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
	setWindowTitle("�޸��û���");
	ui.usernameEdit->setPlaceholderText("�������µ��û���");
	ui.usernameEdit->setClearButtonEnabled(true);
}

ChangeUsername::~ChangeUsername()
{
}

void ChangeUsername::on_OK_clicked()
{
	QString qusername = ui.usernameEdit->text();
	if (type == 2)//ѧ��
	{
		bool check = StudentUser[Pos].UserIsExisted(qusername);
		if (check)
		{
			QMessageBox::warning(this, tr("��ʾ"), tr("�û����ѱ�ʹ��\n�������һ���û���"), QMessageBox::Ok);
			return;
		}
		//û�����д�����飬Ȼ��д���ĵ�
		StudentUser[Pos].setUsername(qusername);
		StudentUser[Pos].save();
	}
	else if (type == 3)//��ְ��
	{
		//for (int i = 0; i < SIZE && !TeacherUser[i].getUsername().isEmpty(); ++i)//�����ڲ���
		//{
		//	if (qusername == TeacherUser[i].getUsername())
		//	{
		//		if (i != Pos)
		//			QMessageBox::warning(this, tr("��ʾ"), tr("�û����ѱ�ʹ��\n�������һ���û���"), QMessageBox::Ok);
		//		else
		//			QMessageBox::warning(this, tr("��ʾ"), tr("���û�����������û����ظ�\n�������һ���û���"), QMessageBox::Ok);
		//		return;
		//	}
		//}
		bool check = TeacherUser[Pos].UserIsExisted(qusername);
		if (check)
		{
			QMessageBox::warning(this, tr("��ʾ"), tr("�û����ѱ�ʹ��\n�������һ���û���"), QMessageBox::Ok);
			return;
		}
		//û�����д�����飬Ȼ��д���ĵ�
		TeacherUser[Pos].setUsername(qusername);
		TeacherUser[Pos].save();
	}
	else//�ÿ�
	{
		bool check = VisitorUser[Pos].UserIsExisted(qusername);
		if (check)
		{
			QMessageBox::warning(this, tr("��ʾ"), tr("�û����ѱ�ʹ��\n�������һ���û���"), QMessageBox::Ok);
			return;
		}
		//û�����д�����飬Ȼ��д���ĵ�
		VisitorUser[Pos].setUsername(qusername);
		VisitorUser[Pos].save();
	}
	QMessageBox::information(this, tr("��ʾ"), tr("�޸ĳɹ���"), QMessageBox::Ok);
	close();
}

void ChangeUsername::on_NO_clicked()
{
	close();
}