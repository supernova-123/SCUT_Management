#include "VisitorInformation.h"
extern int type;//=1则为管理员 =2则为学生 =3则为教职工 =4则为访客 =5则为未注册的访客
extern int Pos;//表示在数组中的位置
//extern ADMIN_User AdminUser[SIZE];
extern vector<ADMIN_User>AdminUser;
extern STUDENT_User StudentUser[SIZE];
extern VISITOR_User VisitorUser[SIZE];
extern TEACHER_User TeacherUser[SIZE];
VisitorInformation::VisitorInformation(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle("我的个人信息");
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