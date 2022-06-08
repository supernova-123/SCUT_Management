#include "TeacherInformation.h"
extern int type;//=1则为管理员 =2则为学生 =3则为教职工 =4则为访客 =5则为未注册的访客
extern int Pos;//表示在数组中的位置
//extern ADMIN_User AdminUser[SIZE];
extern vector<ADMIN_User>AdminUser;
extern STUDENT_User StudentUser[SIZE];
extern TEACHER_User TeacherUser[SIZE];
TeacherInformation::TeacherInformation(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle("我的个人信息");
	if (type == 3)
	{
		ui.classText->setText(TeacherUser[Pos].getClass());
		ui.nameText->setText(TeacherUser[Pos].getName());
		ui.usernameText->setText(TeacherUser[Pos].getUsername());
		ui.idText->setText(TeacherUser[Pos].getId());
		ui.ageText->setText(TeacherUser[Pos].getAge());
		ui.buildingText->setText(TeacherUser[Pos].getBuilding());
		ui.roomText->setText(TeacherUser[Pos].getRoom());
		ui.addressText->setText(TeacherUser[Pos].getAddress());
		ui.phoneText->setText(TeacherUser[Pos].getPhone());
		ui.starttimeText->setText(TeacherUser[Pos].getStartTime());
		ui.fintimeText->setText(TeacherUser[Pos].getFinTime());
	}
}

TeacherInformation::~TeacherInformation()
{
}

void TeacherInformation::on_changeusername_clicked()
{
	ChangeUsername* CUser = new ChangeUsername;
	CUser->show();
}
void TeacherInformation::on_changepassword_clicked()
{
	ChangePassword* CPwd = new ChangePassword;
	CPwd->show();
}
void TeacherInformation::on_flushBtn_clicked()
{
	ui.usernameText->setText(TeacherUser[Pos].getUsername());
}