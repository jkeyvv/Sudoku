#pragma once
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<QString>

#define R 729	//十字链表行数
#define C 324	//十字链表列数

struct Node
{
    Node *up;
    Node *down;
    Node *left;
    Node *right;
    Node *colRoot;	//列首
    int row;		//所在行
    int sum;		//此列节点总数
};

class Sudoku
{
public:
    Sudoku(void);
    virtual ~Sudoku(void);
private:
    Node *nodes,*row,*col,*head;		//可用节点，行首，列首，总头节点
    int nodeCount;						//总节点数
    int *result,resultCount;			//结果,结果行数
    int blanknum;						//空格子的个数

    void init();						//初始化节点
    void cover(Node *t);				//覆盖一列
    void uncover(Node *t);				//取消覆盖
    bool solve(int k=0);				//搜索出结果
    void addNode(int r,int c);			//添加一个节点
    void initdifficulty(char (*)[9]);	//初始化难度
public:
    void resetdata(char (*)[9]);		//生成随机数独
    void change_blanknum(QString);		//改变空格数
    int checkdata(char (*)[9]);			//检查数据
    void cleardata(char (*)[9]);		//清空数据
    void clculate(char (*)[9]);			//完成待计算的数独
};

