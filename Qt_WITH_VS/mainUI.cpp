#include "mainUI.h"
#include<qsavefile.h>
#include<qdialog.h>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include"qlineedit.h"
#include<qlabel.h>
#include<ctime>
#include"LoginDialog.h"
#include<qtimer.h>
#include<qdatetime.h>
#include<string>
#if defined(_MSC_VER) && (_MSC_VER >= 1600)    
# pragma execution_character_set("utf-8")    
#endif
//extern ADMIN_User AdminUser[SIZE];
extern STUDENT_User StudentUser[SIZE];
extern VISITOR_User VisitorUser[SIZE];
extern TEACHER_User TeacherUser[SIZE];
extern vector<ADMIN_User>AdminUser;
extern int superAdmin;
extern int type;//=1则为管理员 =2则为学生 =3则为教职工 =4则为访客 =5则为未注册的访客
extern int Pos;
int checkList;//表示点击了哪个按钮:1表示学生列表 2表示教职工列表 3表示访客列表 4表示我的信息 5表示添加管理员 6表示退出
mainUI::mainUI(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //设置窗口名
    setWindowTitle("Designed by ZhuJinhong&ChaiHao version2.09(Beta)");
    //在构造函数设计一个显示时间的装置
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(1000);
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    QLabel* permanent = new QLabel;
    permanent->setFrameStyle(QFrame::Box | QFrame::Plain);
    permanent->setText(tr("本次登录的时间为 %1").arg(str));
    permanent->setTextFormat(Qt::RichText);
    permanent->setOpenExternalLinks(true);

    //放到状态栏里
    ui.statusBar->addPermanentWidget(permanent);

    //设置权限
    if (superAdmin != -1)
    {
        ui.addAdmin->setEnabled(false);
    }
    if (type == 5)
    {
        ui.information->setEnabled(false);//未注册用户没有信息
    }
    //展示今日广东新冠疫情状况 使用了爬虫程序GetTodayData.py并打包成.exe
    //如果没有连接到网络就不执行程序，提示网络未连接，仍然显示更新之前的疫情状况
    bool NetworkIsConnected = Ping("www.baidu.com");
    if (NetworkIsConnected)
    {
        QProcess process(this);
        process.startDetached("GetTodayData.exe");
    }
    else
    {
        ui.label->setText(tr("今日广东疫情（未连接到网络）"));
    }
    ifstream ifile;
    ifile.open("today_province_.txt", ios::in);
    string strs;
    QString target;
    for (int i = 0; !ifile.eof(); ++i)
    {
        ifile >> strs;
        target = QString::fromStdString(strs);
        if (target.contains("广东"))
        {
            break;
        }
    }
    QString Total_confirm = target.section(',', 2, 2);
    QString Total_heal = target.section(',', 4, 4);
    QString Total_dead = target.section(',', 5, 5);
    QString New_confirm = target.section(',', 11, 11);
    QString Today_storeConfirm = target.section(',', 16, 16);
    QString Today_heal = target.section(',', 13, 13);
    ui.Data->setText(tr("新增确诊数 %1 人\n新增隔离人数 %2 人\n新增治愈人数 %3 人\n累计确诊人数 %4 人\n累计治愈人数 %5 人\n累计死亡人数 %6 人").arg(New_confirm).arg(Today_storeConfirm).arg(Today_heal).arg(Total_confirm).arg(Total_heal).arg(Total_dead));
    ifile.close();
    
}

bool mainUI::Ping(QString strPingIP)
{
    QProcess pingProcess;
    //用ping命令尝试连接百度 
    QString strArg = "ping " + strPingIP + " -w 500 -n 2";  //strPingIP 为百度地址
    pingProcess.start(strArg, QIODevice::ReadOnly);
    pingProcess.waitForFinished(-1);

    QString p_stdout = QString::fromLocal8Bit(pingProcess.readAllStandardOutput());

    qDebug() << p_stdout;
    bool bPingSuccess = false;

    if (p_stdout.contains("TTL=")) //通过特殊字符串进行判断ping是否成功 有TTL字样则说明网络连接成功 反之则没有
    {
        bPingSuccess = true;
    }
    //失败时 p_stdout为“Ping 请求找不到主机 www.baidu.com。请检查该名称，然后重试。”
    else
    {
        bPingSuccess = false;
    }
    return bPingSuccess;
}
//退出事件
void mainUI::on_logout_clicked()
{
    checkList = 6;
    qApp->quit();
}
//进入学生列表
void mainUI::on_student_clicked()
{
    checkList = 1;
    AdminWidgets* adwid = new AdminWidgets;
    adwid->show();
}
//进入个人信息列表
void mainUI::on_information_clicked()
{
    checkList = 4;
    if (type == 2)//学生
    {
        MyInformation* stu_infor = new MyInformation;
        stu_infor->show();
    }
    else if (type == 1)//管理员
    {
        AdminInformation* admin_infor = new AdminInformation;
        admin_infor->show();
    }
    else if(type == 4)//访客
    {
        VisitorInformation* vis_infor = new VisitorInformation;
        vis_infor->show();
    }
    else if (type == 3)//教职工
    {
        TeacherInformation* tea_infor = new TeacherInformation;
        tea_infor->show();
    }
    else if (type == 5)//未注册访客
    {
        QMessageBox::warning(this, tr("错误"),
            tr("你本不应该在这里"),
            QMessageBox::Yes);
    }
}
//进入教职工列表
void mainUI::on_teacher_clicked()
{
    checkList = 2;
    AdminWidgets* adwid = new AdminWidgets;
    adwid->show();
}
//进入访客列表
void mainUI::on_visitor_clicked()
{
    checkList = 3;
    AdminWidgets* adwid = new AdminWidgets;
    adwid->show();
}
//进入添加管理员列表
void mainUI::on_addAdmin_clicked()
{
    checkList = 5;
    AdminTable* add = new AdminTable;
    add->show();
}