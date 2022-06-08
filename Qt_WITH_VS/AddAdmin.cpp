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
	setWindowTitle("���/ɾ������Ա");
	ui.usernameEdit->setPlaceholderText("�������û���...");
	ui.usernameEdit->setClearButtonEnabled(true);
	ui.passwordEdit->setPlaceholderText("����������...");
	ui.passwordEdit->setClearButtonEnabled(true);
}

AddAdmin::~AddAdmin()
{
}

void AddAdmin::on_yesBtn_clicked()
{
	if (adscount >= SIZE)
	{
		QMessageBox::warning(this, tr("��ʾ"), tr("����Ա����������"), QMessageBox::Yes);
		return;
	}
	//��ȡ�û���������
	QString username = ui.usernameEdit->text();
	QString password = ui.passwordEdit->text();
	if (username.isEmpty() || password.isEmpty())//Ϊ������ʾҪ���û���������
	{
		QMessageBox::warning(this, tr("��ʾ"), tr("�뽫�û�����������д����"), QMessageBox::Yes);
		return;
	}
	bool check = AdminUser[Pos].UserIsExisted(username);
	if (check)
	{
		QMessageBox::warning(this, tr("��ʾ"), tr("�û��Ѵ��ڣ�������û���"), QMessageBox::Yes);
		return;
	}
	//�����ļ���
	ADMIN_User ad;
	ad.setUsername(username);
	ad.setPassword(password);
	AdminUser.push_back(ad);//�����¹���Ա
	ad.save();//���浽�ļ��У�����׷�ӣ����˴�ʹ��C++ԭʼ��ȡ����
	QMessageBox::information(this, tr("��ʾ"), tr("��ӳɹ���"), QMessageBox::Yes);
	ad.read();//��������
	close();
}
//ɾ������Ա
void AddAdmin::on_delBtn_clicked()
{
	//��ȡ�û���������
	QString username = ui.usernameEdit->text();
	QString password = ui.passwordEdit->text();
	AdminUser[0].read();
	if (username.isEmpty() || password.isEmpty())//Ϊ������ʾҪ���û���������
	{
		QMessageBox::warning(this, tr("��ʾ"), tr("�뽫�û�����������д����"), QMessageBox::Yes);
		return;
	}
	if (username == AdminUser[Pos].getUsername())
	{
		QMessageBox::warning(this, tr("��ʾ"), tr("����ɾ�������û�"), QMessageBox::Yes);
		return;
	}
	int i = 0;
	for (auto it = AdminUser.begin();!AdminUser[i].getUsername().isEmpty()&&it != AdminUser.end();++i)
	{
		if (AdminUser[i].getUsername() == username && AdminUser[i].getPassword() == password)
		{
			AdminUser.erase(it);//ɾ��
			AdminUser[0].total_save();//���������ļ�
			QMessageBox::information(this, tr("��ʾ"), tr("ɾ���ɹ���"), QMessageBox::Yes);
			AdminUser[0].read();
			close();
			return;
		}
		else
		{
			++it;
		}
	}
	QMessageBox::warning(this, tr("����"), tr("δ�ҵ�����д����ƥ��ġ�%1����").arg(username), QMessageBox::Ok);
	return;
}
//ȡ����ֱ���˳�
void AddAdmin::on_noBtn_clicked()
{
	close();
}