#include "MyInformation.h"
extern int type;//=1则为管理员 =2则为学生 =3则为教职工 =4则为访客 =5则为未注册的访客
extern int Pos;//表示在数组中的位置
//extern ADMIN_User AdminUser[SIZE];
extern vector<ADMIN_User>AdminUser;
extern STUDENT_User StudentUser[SIZE];
extern VISITOR_User VisitorUser[SIZE];
extern TEACHER_User TeacherUser[SIZE];
MyInformation::MyInformation(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle("我的个人信息");
	if (type == 2)
	{
		ui.classText->setText(StudentUser[Pos].getClass());
		ui.nameText->setText(StudentUser[Pos].getName());
		ui.usernameText->setText(StudentUser[Pos].getUsername());
		ui.idText->setText(StudentUser[Pos].getId());
		ui.ageText->setText(StudentUser[Pos].getAge());
		ui.buildingText->setText(StudentUser[Pos].getBuilding());
		ui.roomText->setText(StudentUser[Pos].getRoom());
		ui.addressText->setText(StudentUser[Pos].getAddress());
		ui.phoneText->setText(StudentUser[Pos].getPhone());
		ui.starttimeText->setText(StudentUser[Pos].getStartTime());
		ui.fintimeText->setText(StudentUser[Pos].getFinTime());
	}
}

MyInformation::~MyInformation()
{
}
void MyInformation::on_changeusername_clicked()
{
	ChangeUsername* CUser = new ChangeUsername;
	CUser->show();
	//ui.usernameText->setText(StudentUser[Pos].getUsername());
}
void MyInformation::on_changepassword_clicked()
{
	ChangePassword* CPwd = new ChangePassword;
	CPwd->show();
}
void MyInformation::on_flushBtn_clicked()
{
	ui.usernameText->setText(StudentUser[Pos].getUsername());
}
