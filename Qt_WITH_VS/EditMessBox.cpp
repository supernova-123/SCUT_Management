#include "EditMessBox.h"
extern int checkList;
//extern ADMIN_User AdminUser[SIZE];
extern vector<ADMIN_User>AdminUser;
extern STUDENT_User StudentUser[SIZE];
extern VISITOR_User VisitorUser[SIZE];
extern TEACHER_User TeacherUser[SIZE];
extern int Pos;
extern int type;//=1则为管理员 =2则为学生 =3则为教职工 =4则为访客 =5则为未注册的访客
EditMessBox::EditMessBox()
{
    ui.setupUi(this);
    /*
     * QVBoxLayout 局部工具中放置 QFormLayout 和 QHBoxLayout
     * QFormLayout 中放置多个单行输入框
     * QHBoxLayout 中放置两个按钮
    */
    setWindowTitle("添加人员信息");
    QVBoxLayout* VBox = new QVBoxLayout;
    QFormLayout* FormLayout = new QFormLayout;
    qclass = new QComboBox;
    qclass->addItem("学生");
    qclass->addItem("教职工");
    qclass->addItem("访客");
    //人性化操作：选择不同的身份，则在添加信息时切换身份的初始项
    switch (checkList)
    {
    case 1:
        qclass->setCurrentIndex(0); break;
    case 2:
        qclass->setCurrentIndex(1); break;
    default:
        qclass->setCurrentIndex(2);
        break;
    }
    qclass->setEnabled(false);//进入哪种名单就只能选择添加哪种身份
    qid = new QLineEdit;
    qname = new QLineEdit;
    qbuilding = new QLineEdit;
    qroom = new QLineEdit;
    qphone = new QLineEdit;
    qaddress = new QLineEdit;
    qpassword = new QLineEdit;
    qusername = new QLineEdit;
    qage = new QLineEdit;
    if (checkList != 3)
    {
        qstayReason = new QComboBox;
        qstayReason->addItem("自愿留校");
        qstayReason->addItem("隔离");
        qstayReason->addItem("居住地疫情无法离校");
    }
    else
    {
        qvisReason = new QLineEdit;
    }
    qstartTime = new QDateEdit(QDate::currentDate(), this);
    qstartTime->setMinimumDate(QDate::currentDate().addDays(-365 * 3));
    qstartTime->setMaximumDate(QDate::currentDate().addDays(365 * 3));
    qfinTime = new QDateEdit(QDate::currentDate().addDays(1), this);
    qfinTime->setMinimumDate(QDate::currentDate().addDays(-365 * 3));
    qfinTime->setMaximumDate(QDate::currentDate().addDays(365 * 3));
    qcode = new QComboBox;
    qcode->addItem("红码");
    qcode->addItem("黄码");
    qcode->addItem("绿码24小时核酸");
    qcode->addItem("绿码48小时核酸");
    qcode->addItem("绿码72小时核酸");
    qcode->addItem("绿码");
    qcode->setCurrentIndex(5);
    FormLayout->addRow("身份：", qclass);
    FormLayout->addRow("姓名：", qname);
    if (checkList == 1)
        FormLayout->addRow("学号/身份证号：", qid);
    else if (checkList == 2)FormLayout->addRow("工号/身份证号：", qid);
    else FormLayout->addRow("身份证号：", qid);
    FormLayout->addRow("年龄：", qage);
    if (checkList == 1)
    {
        FormLayout->addRow("楼栋：", qbuilding);
        FormLayout->addRow("房号：", qroom);
    }
    else if(checkList == 2)
    {
        FormLayout->addRow("所属机构：", qbuilding);
        FormLayout->addRow("校内住址/办公室：", qroom);
    }
    else
    {
        FormLayout->addRow("所属机构/楼栋：", qbuilding);
        FormLayout->addRow("校内住址/办公室：", qroom);
    }
    FormLayout->addRow("家庭地址：", qaddress);
    FormLayout->addRow("联系方式：", qphone);
    FormLayout->addRow("留校起始时间：", qstartTime);
    FormLayout->addRow("离校时间：", qfinTime);
    if (checkList == 2 || checkList == 1)
        FormLayout->addRow("留校原因：", qstayReason);
    else
        FormLayout->addRow("来访原因：", qvisReason);
    FormLayout->addRow("健康码状态：", qcode);
    FormLayout->addRow("用户名：", qusername);
    FormLayout->addRow("密码：", qpassword);
    FormLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);
    QHBoxLayout* HBox = new QHBoxLayout;
    submit = new QPushButton("提交");
    cancel = new QPushButton("取消");
    HBox->addWidget(submit);
    HBox->addWidget(cancel);
    VBox->addLayout(FormLayout, 4);
    VBox->addLayout(HBox, 1);
    this->setLayout(VBox);
    //点击提交按钮时，将新人员信息保存到文件中
    QObject::connect(submit, &QPushButton::clicked, this, &EditMessBox::saveMess);
    //点击取消按钮时，关闭添加信息窗口
    QObject::connect(cancel, &QPushButton::clicked, this, &EditMessBox::close);
}
// 当用户添加提交按钮时，保存信息
void EditMessBox::saveMess() {
    
    User* us;
    switch (checkList)
    {
    case 1:
        us = new STUDENT_User; break;
    case 2:
        us = new TEACHER_User; break;
    default:
        us = new VISITOR_User;
        break;
    }
    if (this->qname->text().isEmpty() || this->qbuilding->text().isEmpty() || this->qaddress->text().isEmpty() ||
        this->qusername->text().isEmpty() || this->qpassword->text().isEmpty() || this->qroom->text().isEmpty() || 
        this->qphone->text().isEmpty() || this->qid->text().isEmpty() || this->qage->text().isEmpty())
    {
        QMessageBox::warning(this, tr("提示"), tr("请将信息填写完整！"), QMessageBox::Yes);
        return;
    }
    us->setClass(this->qclass->currentText());
    us->setId(this->qid->text());
    us->setName(this->qname->text());
    us->setAge(this->qage->text());
    //判断隔离的条件：如果既是学生又需要隔离，则必须入住C4，否则要手动修改 如果是学生之外的需要隔离，必须入住大学城中心酒店
    if (this->qbuilding->text() != "C4" && this->qclass->currentText() == "学生" && (this->qstayReason
        ->currentText() == "隔离" || this->qcode->currentText() == "红码"))
    {
        int click = QMessageBox::warning(this, tr("提示"),
            tr("红码或隔离的学生需要入住C4\n选择“是”将确定保存，系统自动修改为C4和隔离状态\n"
                "选择“否”将返回填写页面"),
            QMessageBox::Yes, QMessageBox::No);
        if (click == QMessageBox::Yes)
        {
            us->setBuilding("C4");
            us->setStayReason("隔离");
        }
        else return;
    }
    else if (this->qclass->currentText() != "学生" && (this->qstayReason
        ->currentText() == "隔离" || this->qcode->currentText() == "红码") && this->qbuilding->text() != "大学城中心酒店")
    {
        int click = QMessageBox::warning(this, tr("提示"),
            tr("红码或隔离的教职工和访客需要入住大学城中心酒店\n选择“是”将确定保存，系统自动修改为中心酒店和隔离状态\n"
                "选择“否”将返回填写页面"),
            QMessageBox::Yes, QMessageBox::No);
        if (click == QMessageBox::Yes)
        {
            us->setBuilding("大学城中心酒店");
            us->setStayReason("隔离");
        }
        else return;
    }
    else us->setBuilding(this->qbuilding->text());
    us->setRoom(this->qroom->text());
    us->setPhone(this->qphone->text());
    us->setAddress(this->qaddress->text());
    us->setStartTime(this->qstartTime->date().toString(Qt::ISODate));
    //如果出现了离校起始时间比结束时间还晚的，视为逻辑错误，引导用户重新填写
    if (this->qstartTime->date().toString(Qt::ISODate) > this->qfinTime->date().toString(Qt::ISODate))
    {
        QMessageBox::warning(this, tr("警告！"),
            tr("请选择合适的离校日期！"),
            QMessageBox::Yes);
        return;
    }
    else us->setFinTime(this->qfinTime->date().toString(Qt::ISODate));
    if (checkList != 3)
        us->setStayReason(this->qstayReason->currentText());
    else us->setStayReason(this->qvisReason->text());
    us->setCode(this->qcode->currentText());
    if (us->UserIsExisted(this->qusername->text()))
    {
        QMessageBox::warning(this, tr("提示：未能成功注册"),
            tr("用户名重复，请改用其他用户名"),
            QMessageBox::Yes);
        return;
    }
    us->setUsername(this->qusername->text());
    us->setPassword(this->qpassword->text());
    QFile* file;
    //根据不同类型放入不同的文件
    if (checkList == 1)
        file = new QFile(studentList);
    else if (checkList == 2)
        file = new QFile(teacherList);
    else if (checkList == 3)
        file = new QFile(visitorList);
    else file = new QFile(others);
    file->open(QIODevice::WriteOnly | QIODevice::Append);
    QDataStream dataStr(file);
    dataStr << us->getClass() << us->getName() << us->getId() << us->getAge() << us->getBuilding()
        << us->getRoom() << us->getAddress() << us->getPhone() << us->getStartTime() << us->getFinTime() << us->getStayReason()
        << us->getCode() << us->getUsername() << us->getPassword();
    //重新读入数组
    if (checkList == 1)
    {
        StudentUser[0].read();
    }
    else if (checkList == 2)
    {
        TeacherUser[0].read();
    }
    else
    {
        VisitorUser[0].read();
    }
    file->close();
    this->close();
    emitCloseBox();
}
void EditMessBox::emitCloseBox()
{
    emit closeBox();
}
EditMessBox::~EditMessBox()
{
}
