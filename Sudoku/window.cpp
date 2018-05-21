#include "window.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.timer->display("00:00");
    modestate=GAME;					//初始模式为游戏模式
    sudoku.change_blanknum("easy");	//初始化难度为简单
    startstate=false;
    secscout=0;
    data=new char[9][9];
    //初始化计时器
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timekeep()));
    timer->start(1000);		//计时周期为1000毫秒，即一秒
}

Window::~Window()
{
    delete [] data;
}

void Window::start()
{
    sudoku.resetdata(data);
    ui.tableWidget->displaydata(data);
    starttime=QTime::fromString("00:00","mm:ss");
    secscout=0;
    startstate=true;
}

void Window::difficulty(QString str)
{
    //根据难度值改变空格数
    sudoku.change_blanknum(str);
}

void Window::mode(QString str)
{
    if(str==QString("game"))
    {
        sudoku.resetdata(data);
        ui.difficultybox->setEnabled(true);
        ui.startbutton->setEnabled(true);
        modestate=GAME;
    }
    else
    {
        sudoku.cleardata(data);
        ui.tableWidget->displaydata(data);
        ui.difficultybox->setEnabled(false);
        ui.startbutton->setEnabled(false);
        modestate=CALCULATOR;
        startstate=false;
    }
}

void Window::check()
{
    //根据当前模式判断游戏结果或完成填充数独
    if(modestate==GAME)
    {
        ui.tableWidget->getdata(data);
        int n=sudoku.checkdata(data);
        if(n==1)
        {
            message.setText("please fill to full");
            message.exec();
        }
        else if(n==2)
        {
            message.setText("fail");
            message.exec();
        }
        else if(n==3)
        {
            message.setText("win");
            message.exec();
            startstate=false;
        }
        else
        {
            message.setText("error");
            message.exec();
        }
    }
    else
    {
        ui.tableWidget->getdata(data);
        sudoku.clculate(data);
        ui.tableWidget->displaydata(data);
    }
}

void Window::timekeep()
{
    if(startstate)
    {
        //每收到一个timer信号，秒数加一并显示
        QTime throughTime=starttime.addSecs(secscout++);
        ui.timer->display(throughTime.toString("mm:ss"));
    }
    else
        ui.timer->display("00:00");
}

void Window::about()
{
    message.setText("By Hubinary   2014.12.20");
    message.exec();
}
