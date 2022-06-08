#include "ChangeAdminInformation.h"
//extern ADMIN_User AdminUser[SIZE];
extern vector<ADMIN_User>AdminUser;
extern int Pos;
ChangeAdminInformation::ChangeAdminInformation(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle("�޸���Ϣ");
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
	//���������ظ��û���
	QString name = ui.usernameEdit->text();
	QString pwd = ui.passwordEdit->text();
	for (int i = 0; i < SIZE && !AdminUser[i].getUsername().isEmpty(); ++i)
	{
		if (AdminUser[i].getUsername() == name && i != Pos)
		{
			QMessageBox::warning(this, tr("����"), tr("�û����ظ������������룡"), QMessageBox::Ok);
			return;
		}
	}
	AdminUser[Pos].setUsername(name);
	AdminUser[Pos].setPassword(pwd);
	//�������ļ���
	AdminUser[Pos].total_save();
	QMessageBox::information(this, tr("��ʾ"), tr("�޸ĳɹ���"), QMessageBox::Ok);
	close();
}

void ChangeAdminInformation::on_NO_clicked()
{
	close();
}