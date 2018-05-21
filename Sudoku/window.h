#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QTimer>
#include <QTime>
#include "ui_window.h"
#include "sudoku.h"

#define GAME true			//游戏模式
#define CALCULATOR false	//数独计算器模式

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    ~Window();
private:
    Ui::WindowClass ui;			//主窗口
private:
    Sudoku sudoku;
    QMessageBox message;
    bool modestate;				//模式状态
    bool startstate;			//开始状态
    char (*data)[9];			//指向存储表格内数据的二维数组的指针
    //用于计时
    QTimer *timer;				//计时器
    QTime starttime;			//开始时间
    int secscout;				//开始后经历的秒数

public slots:
    void start();				//开始按钮槽
    void timekeep();			//计时槽
    void check();				//提交按钮槽（用于检查填写）
    void about();				//关于按钮槽
    void mode(QString);			//模式按钮槽
    void difficulty(QString);	//难度按钮槽
};

#endif // WINDOW_H
