#include "widget.h"
#include "ui_widget.h"
#include "register_page.h"//这个地方得自己添加，如果想要于这个页面联系的话
#include "login_success_page.h"//同上

#include<QDesktopWidget>
#include<QStyle>
#include<QRect>//用来自动获取屏幕大小相关的头文件

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//下边这几句是用来自动获取屏幕大小并且使窗口这么大的
    QDesktopWidget *desktopWidget=QApplication::desktop();
    QRect deskReck = desktopWidget->availableGeometry();
    int appH = deskReck.height();
    int appW = deskReck.width();
    this->setFixedSize(appW,appH);
    setGeometry(0,0,appW,appH);
}

Widget::~Widget()
{
    delete ui;
}

//信号和槽不是一个名词，是指“信号”“槽”，信号指的是操作组件时组件发出的信号（如点击按钮），而槽指的是槽函数，将信号于槽函数绑定，就能够实现功能
void Widget::on_QQregister_clicked()//这个玩意叫槽函数，是通过在ui设计界面里对注册按钮右键-转到槽之后生成的，槽函数里边可以写逻辑
{
    //qDebug("fuck,register");//这句话是用来在调试框显示信息的，现在给注释掉了

    register_page *rg = new register_page;//创建指针类，其实也可以用普通类，然后用.函数()的形式调用
    rg->setGeometry(this->geometry());//保证窗口大小不变的
    rg->show();
    this->close();
}

void Widget::on_QQlogin_clicked()//点击登录的时候
{
    QString userName = ui->QQuserid->text();
    QString passwd = ui->QQpassword->text();

    if(userName=="123"&&passwd=="456")//id和密码都是123时才跳转
    {
    login_success_page *lg = new login_success_page;
    lg->show();
    this->close();
    }
}
