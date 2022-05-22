#include "VisitorInformation.h"
extern int type;//=1��Ϊ����Ա =2��Ϊѧ�� =3��Ϊ��ְ�� =4��Ϊ�ÿ� =5��Ϊδע��ķÿ�
extern int Pos;//��ʾ�������е�λ��
//extern ADMIN_User AdminUser[SIZE];
extern vector<ADMIN_User>AdminUser;
extern STUDENT_User StudentUser[SIZE];
extern VISITOR_User VisitorUser[SIZE];
extern TEACHER_User TeacherUser[SIZE];
VisitorInformation::VisitorInformation(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle("�ҵĸ�����Ϣ");
	if (type == 4)
	{
		ui.classText->setText(VisitorUser[Pos].getClass());
		ui.nameText->setText(VisitorUser[Pos].getName());
		ui.usernameText->setText(VisitorUser[Pos].getUsername());
		ui.idText->setText(VisitorUser[Pos].getId());
		ui.ageText->setText(VisitorUser[Pos].getAge());
		ui.buildingText->setText(VisitorUser[Pos].getBuilding());
		ui.roomText->setText(VisitorUser[Pos].getRoom());
		ui.addressText->setText(VisitorUser[Pos].getAddress());
		ui.phoneText->setText(VisitorUser[Pos].getPhone());
		ui.starttimeText->setText(VisitorUser[Pos].getStartTime());
		ui.fintimeText->setText(VisitorUser[Pos].getFinTime());
	}
}

VisitorInformation::~VisitorInformation()
{
}

void VisitorInformation::on_changeusername_clicked()
{
	ChangeUsername* CUser = new ChangeUsername;
	CUser->show();
}
void VisitorInformation::on_changepassword_clicked()
{
	ChangePassword* CPwd = new ChangePassword;
	CPwd->show();
}
void VisitorInformation::on_flushBtn_clicked()
{
	ui.usernameText->setText(VisitorUser[Pos].getUsername());
}