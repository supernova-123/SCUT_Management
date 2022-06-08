#include "mainUI.h"
#include "LoginDialog.h"
#include <QtWidgets/QApplication>
#include<qsavefile.h>
#include<qdialog.h>
#include<qstring.h>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include"qlineedit.h"
#include"Login.h"
#include "AdminWidgets.h"
#include"MyInformation.h"
#if defined(_MSC_VER) && (_MSC_VER >= 1600)    
# pragma execution_character_set("utf-8")    
#endif
//extern ADMIN_User AdminUser[SIZE];
extern vector<ADMIN_User>AdminUser;
extern STUDENT_User StudentUser[SIZE];
extern VISITOR_User VisitorUser[SIZE];
extern TEACHER_User TeacherUser[SIZE];
extern int type;//=1则为管理员 =2则为学生 =3则为教职工 =4则为访客 =5则为未注册的访客
extern int Pos;
int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    LoginDialog dlg;
    dlg.setWindowTitle("登录界面");
    ADMIN_User adus;
    STUDENT_User nmus;
    if (dlg.exec() == QDialog::Accepted)
    {
        mainUI w;
        w.show();
        return a.exec();
    }
    else return 0;
}
