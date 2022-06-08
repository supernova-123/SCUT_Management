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
int type;//=1��Ϊ����Ա =2��Ϊѧ�� =3��Ϊ��ְ�� =4��Ϊ�ÿ� =5��Ϊδע��ķÿ�
int Pos;//��ʾ�������е�λ��
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
	//�ڳ�ʼҳ�湹���ʱ��¼����Ա
	stucount = StudentUser[0].read();
	viscount = VisitorUser[0].read();
	adscount = AdminUser[0].read();
	teacount = TeacherUser[0].read();
	int a = 0;
}

LoginDialog::~LoginDialog()
{

}

//��¼��ť����¼�
void LoginDialog::on_Login_clicked()
{
	// �ж��û����������Ƿ���ȷ��
	// ��������򵯳�����Ի���	
	if (ui.checkAdmin->isChecked())
	{
		bool success = 0;
		for (int i = 0; i < adscount; ++i)
		{
			if (ui.Username->text() == (AdminUser[i].getUsername()) &&
				ui.Password->text() == (AdminUser[i].getPassword()))
			{
				//�ж��ǲ��ǳ�������Ա
				if (ui.Username->text() == AdminUser[0].getUsername()) superAdmin = -1;
				success = 1;
				type = 1;
				Pos = i;
				accept();
			}
		}
		if (!success)
		{
			QMessageBox::warning(this, tr("���棡"),
				tr("�û������������"),
				QMessageBox::Yes);
		}
	}
	else if (ui.checkStu->isChecked())//ѧ��
	{
		bool success = 0;
		for (int i = 0; i < stucount; ++i)
		{
			if (ui.Username->text() == (StudentUser[i].getUsername()) &&
				ui.Password->text() == (StudentUser[i].getPassword()) && 
				StudentUser[i].getClass() == "ѧ��")
			{
				success = 1;
				type = 2;
				Pos = i;
				accept();
			}
		}
		if (!success)
		{
			QMessageBox::warning(this, tr("���棡"),
				tr("�û������������"),
				QMessageBox::Yes);
		}
	}
	else if (ui.checkTea->isChecked())//��ְ��
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
			QMessageBox::warning(this, tr("���棡"),
				tr("�û������������"),
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
			QMessageBox::warning(this, tr("���棡"),
				tr("�û������������"),
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
		QMessageBox::warning(this, tr("���棡"),
			tr("��ѡ�����ĵ�¼��ݣ�"),
			QMessageBox::Yes);
	}
}

void LoginDialog::on_Exit_clicked()
{
	close();
}