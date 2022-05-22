#include "AdminInformation.h"
//extern ADMIN_User AdminUser[SIZE];
extern vector<ADMIN_User>AdminUser;
extern int Pos;
extern int type;//= 1��Ϊ����Ա = 2��Ϊѧ�� = 3��Ϊ��ְ�� = 4��Ϊ�ÿ� = 5��Ϊδע��ķÿ�
int clickCount;//��¼�������
int pwdLen;//���볤��
QString HiddenPwd;//�ɡ�*�����ɣ���ʾ���ص�����
AdminInformation::AdminInformation(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle("�ҵĸ�����Ϣ");
	if (type == 1)
	{
		ui.classText->setText("����Ա");
		ui.usernameText->setText(AdminUser[Pos].getUsername());
		pwdLen = AdminUser[Pos].getPassword().size();//��ȡ���볤�ȣ���ʼ��ΪSize���ȵ�'*'
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
	if (clickCount & 1)//�����Σ�����ʾ����
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
	if (clickCount & 1)//�����Σ�����ʾ����
	{
		ui.passwordText->setText(AdminUser[Pos].getPassword());
	}
	else
	{
		ui.passwordText->setText(HiddenPwd);
	}
}