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
	setWindowTitle("�޸�����");
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
	//����User�����ָ�룬���ݲ�ͬ��typeָ��ͬ�Ķ���
	User* us;
	if (type == 2) us = &StudentUser[Pos];
	else if (type == 3)us = &TeacherUser[Pos];
	else us = &VisitorUser[Pos];
	if (oldPwd.isEmpty() || newPwd.isEmpty() || confirmNewPwd.isEmpty())
	{
		QMessageBox::warning(this, tr("����"), tr("���벻��Ϊ�գ�"), QMessageBox::Ok);
		return;
	}
	if (oldPwd != us->getPassword())
	{
		QMessageBox::warning(this, tr("����"), tr("����ľ�������ʵ�����벻һ�£�"), QMessageBox::Ok);
		return;
	}
	else if (newPwd != confirmNewPwd)
	{
		QMessageBox::warning(this, tr("����"), tr("��������������벻һ�£�"), QMessageBox::Ok);
		return;
	}
	us->setPassword(newPwd);
	us->save();
	QMessageBox::information(this, tr("��ʾ"), tr("�޸ĳɹ���"), QMessageBox::Ok);
	close();
}

void ChangePassword::on_NO_clicked()
{
	close();
}