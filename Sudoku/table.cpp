#include "table.h"

Table::Table(QWidget *parent)
    : QTableWidget(parent)
{
    inittable();
}

Table::~Table()
{
}
//初始化表格
void Table::inittable()
{
    setRowCount(9);
    setColumnCount(9);
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            QTableWidgetItem * newItem = new QTableWidgetItem();
            newItem->setTextAlignment(Qt::AlignCenter);//表格内数字居中
            //设置表格元素背景颜色
            if(i>=3 && i<=5 && (j<=2 || j>=6)||j>=3 && j<=5 && (i<=2 || i>=6))
            {
                newItem->setBackgroundColor(Qt::yellow);
            }
            else
            {
                newItem->setBackgroundColor(Qt::cyan);
            }
            setItem(i,j,newItem);
        }
    }
}
//在表格中显示数字
void Table::displaydata(const char data[][9])
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            item(i,j)->setFlags(Qt::ItemFlag(63));//设置可编辑状态
            if(data[i][j] >= 1 && data[i][j] <= 9)
            {
                item(i,j)->setText(QString::number(data[i][j]));
                item(i,j)->setTextColor(Qt::blue);
                item(i,j)->setFlags(Qt::ItemFlag(64));//设置不可编辑状态
            }
            else
            {
                item(i,j)->setText(QString(' '));
            }
        }
    }
}
//从表格中读取数据
void Table::getdata(char data[][9])
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            data[i][j] = (char)(item(i,j)->text().toInt());
        }
    }
}
//按键槽
void Table::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_1:
    case Qt::Key_2:
    case Qt::Key_3:
    case Qt::Key_4:
    case Qt::Key_5:
    case Qt::Key_6:
    case Qt::Key_7:
    case Qt::Key_8:
    case Qt::Key_9:
            currentItem()->setText(event->text());
            currentItem()->setTextColor(Qt::red);
        break;
    case Qt::Key_0:
    case Qt::Key_Space:
    case Qt::Key_Delete:
            currentItem()->setText(QString(' '));
        break;
    default:
        QTableWidget::keyPressEvent(event);
    }
}
