#include "ChangeOtherAdmin.h"
extern vector<ADMIN_User>AdminUser;
ChangeOtherAdmin::ChangeOtherAdmin(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle("�޸�ָ������Ա��Ϣ");
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
		QMessageBox::warning(this, tr("��ʾ"), tr("δ�ҵ��û��� %1 ��").arg(oldname), QMessageBox::Ok);
		return;
	}
	int check2 = AdminUser[0].UserIsExisted(newname);
	if (check2 && oldname != newname)
	{
		QMessageBox::warning(this, tr("��ʾ"), tr("�Ѵ��ڸ��û���������û�����"), QMessageBox::Ok);
		return;
	}
	--p;//ȡ������ֵΪp+1���������
	//ǰ��Ķ�ͨ���ģ��ͷŵ�������
	AdminUser[p].setUsername(newname); AdminUser[p].setPassword(newpwd);
	AdminUser[0].total_save();//���浽�ļ���
	QMessageBox::information(this, tr("��ʾ"), tr("����ɹ���"), QMessageBox::Ok);
	close();
}