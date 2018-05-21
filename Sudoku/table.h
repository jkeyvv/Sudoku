#ifndef MYTABLE_H
#define MYTABLE_H

#include <QtWidgets/QTableWidget>
#include <QKeyEvent>

class Table : public QTableWidget
{
    Q_OBJECT

public:
    Table(QWidget *parent);
    ~Table();
private slots:
    //按键槽
    virtual void keyPressEvent(QKeyEvent *event);
public:
    //初始化表格
    void inittable();
    //在表格中显示数字
    void displaydata(const char (*)[9]);
    //从表格中获取数据
    void getdata(char (*)[9]);
};
#endif // MYTABLE_H
