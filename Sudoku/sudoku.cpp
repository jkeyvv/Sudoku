#include "sudoku.h"

Sudoku::Sudoku(void)
{
    nodes=new Node[R*C];
    row=new Node[R];
    col=new Node[C+1];
    result=new int[R];
}

Sudoku::~Sudoku(void)
{
    delete []nodes;
    delete []row;
    delete []col;
    delete []result;
}

void Sudoku::init()
{
    int i;
    //将各列连起来,col[colNum]为总头节点
    for(i=0;i<=C;i++)
    {
        col[i].up=col[i].down=col+i;
        col[i].left=col + (i+C)%(1+C);
        col[i].right=col + (i+1)%(1+C);
        col[i].sum=0;
    }
    head=col+C;
    //将各行节点数清零
    for(i=0;i<R;i++)
    {
        row[i].up=row[i].down=row[i].left=row[i].right=row[i].colRoot=row+i;
    }
    nodeCount=0;//总节点数清零
}

void Sudoku::addNode(int r,int c)
{
    nodes[nodeCount].up=col[c].up;
    nodes[nodeCount].down=col+c;
    nodes[nodeCount].left=row[r].left;
    nodes[nodeCount].right=row+r;
    nodes[nodeCount].row=r;
    nodes[nodeCount].colRoot=col+c;
    col[c].up=col[c].up->down=row[r].left=row[r].left->right=nodes+nodeCount++;
    col[c].sum++;
}

void Sudoku::cover(Node *t)
{
    Node *p,*q;
    t->left->right=t->right;
    t->right->left=t->left;
    for(p=t->down;p!=t;p=p->down)
    {
        for(q=p->right;q!=p;q=q->right)
        {
            q->up->down=q->down;
            q->down->up=q->up;
            q->colRoot->sum--;
        }
    }
}

void Sudoku::uncover(Node *t)
{
    Node *p,*q;
    for(p=t->up;p!=t;p=p->up)
    {
        for(q=p->left;q!=p;q=q->left)
        {
            q->up->down=q->down->up=q;
            q->colRoot->sum++;
        }
    }
    t->left->right=t->right->left=t;
}

bool Sudoku::solve(int k)
{
    //是否还有未覆盖的列
    if(head->right==head)
    {
        //记录完成覆盖所用行数
        resultCount=k;
        return true;
    }
    Node *pMin,*p,*q;
    //找到节点数最少的一列,并覆盖
    for(pMin=head->right,p=pMin->right;p!=head;p=p->right)
    {
        if(pMin->sum>p->sum)
            pMin=p;
    }
    cover(pMin);
    for(p=pMin->down;p!=pMin;p=p->down)
    {
        result[k]=p->row;
        //选定此列上的一个节点，将此节点所在行上所有节点的对应列进行覆盖
        for(q=p->right;q!=p;q=q->right)
            cover(q->colRoot);
        if(solve(k+1))
            return true;
        //如果不能成功，则取消覆盖
        for(q=p->left;q!=p;q=q->left)
            uncover(q->colRoot);
    }
    uncover(pMin);
    return false;
}

int getRowIndex(int rowNum)
{
    int num = rowNum%9;
    int rowIndex = rowNum / 81;
    return 81 + rowIndex*9 + num;
}

int getColIndex(int rowNum)
{
    int num = rowNum%9;
    int index = rowNum/9;	//位置
    int colIndex = index%9;
    return 162 + colIndex*9+num;
}

int getSquareIndex(int rowNum)
{
    int num = rowNum%9;
    int index = rowNum/9;	//位置
    int rowIndex = index / 9;
    int colIndex = index%9;
    int squareIndex = int(rowIndex/3)*3 + colIndex/3;
    return 243 + squareIndex*9+num;
}

void Sudoku::resetdata(char data[][9])
{
    init();
    int i,j;
    char firstrow[9];//数独第一行
    //生成数组元素在0-8的随机数组
    srand((int)time(0));
    for(int i=0;i<9;i++)
    {
        firstrow[i]=i;
    }
    std::random_shuffle(firstrow,firstrow+9);
    //插入全部节点
    for(i=0;i<R;i++)
    {
        if(i>=81 || i%9==firstrow[i/9])
        {
            int rowIndex = i;
            int colIndex = i/9;
            addNode(rowIndex,colIndex);			//位置冲突
            addNode(rowIndex,getRowIndex(i));	//行冲突
            addNode(rowIndex,getColIndex(i));	//列冲突
            addNode(rowIndex,getSquareIndex(i));//块冲突
        }
    }

    if(solve())
    {
        for(i=0;i<81;i++)
        {
            j=result[i];
            data[j/81][(j%81)/9]=j%9+1;
        }
    }
    initdifficulty(data);
}

void Sudoku::change_blanknum(QString str)
{
    int tmp[9];
    //生成数组元素在0-8的随机数组
    srand((int)time(0));
    for(int i=0;i<10;i++)
    {
        tmp[i]=i;
    }
    std::random_shuffle(tmp,tmp+9);

    if(str==QString("easy"))
        blanknum=tmp[1]+25;//简单难度，空格数在25-34
    else if(str==QString("hard"))
        blanknum=tmp[1]+35;//困难难度，空格数在35-44
    else
        blanknum=tmp[1]+45;//专家难度，空格数在45-54
}

void Sudoku::initdifficulty(char data[][9])
{
    int i;
    char blank[81];
    //生成数组元素在0-80的随机数组
    srand((int)time(0));
    for(i=0;i<81;i++)
    {
        blank[i]=i;
    }
    std::random_shuffle(blank,blank+81);
    //取随机数组前blanknum元素生成数独里的空格
    for(i=0;i<=blanknum;i++)
    {
        data[blank[i]/9][blank[i]%9]=0;
    }
}

int Sudoku::checkdata(char (*data)[9])
{
    init();
    int i;
    for(i=0;i<R;i++)
    {
        if(data[i/81][(i%81)/9]==i%9+1)
        {
            int rowIndex = i;
            int colIndex = i/9;
            addNode(rowIndex,colIndex);			//位置冲突
            addNode(rowIndex,getRowIndex(i));	//行冲突
            addNode(rowIndex,getColIndex(i));	//列冲突
            addNode(rowIndex,getSquareIndex(i));//块冲突
        }
    }

    if(nodeCount<320)
        return 1;		//未填完
    for(i=0;i<C;i++)
    {
        if(col[i].sum != 1)
            return 2;	//填写有误
    }
    return 3;			//填写正确
}

void Sudoku::clculate(char (*data)[9])
{
    init();
    int i,j;
    for(i=0;i<R;i++)
    {
        //没有数字的添加全部节点，有数字的添加四个节点
        if(data[i/81][(i%81)/9]==0 || data[i/81][(i%81)/9]==i%9+1)
        {
            int rowIndex = i;
            int colIndex = i/9;
            addNode(rowIndex,colIndex);			//位置冲突
            addNode(rowIndex,getRowIndex(i));	//行冲突
            addNode(rowIndex,getColIndex(i));	//列冲突
            addNode(rowIndex,getSquareIndex(i));//块冲突
        }
    }

    if(solve())
    {
        for(i=0;i<81;i++)
        {
            j=result[i];
            data[j/81][(j%81)/9]=j%9+1;
        }
    }
}

void Sudoku::cleardata(char (*data)[9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            data[i][j]=0;
        }
    }
}
