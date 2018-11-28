#include <iostream>

using namespace std;
typedef int ElemType;

#define MAXSIZE 1000 //假设链表的最大长度是1000

//线性表的静态链式存储结构
typedef struct
{
    ElemType data;
    int cur;
}Component, StaticLinkList[MAXSIZE];

//初始化静态链表.将一维数组space中各分量链成一备用链表
bool InitList(StaticLinkList space)
{
    for(int i = 0 ; i < MAXSIZE - 1; i++)
    {
        space[i].cur = i + 1;
    }
    space[MAXSIZE-1].cur = 0;
    return true;
}

/*在动态链表中，节点的申请和释放是通过new和delete函数完成的，在静态链表
中，操作的是数组，不存在像动态链表的节点申请和释放问题，
所以我们需要自己实现这两个函数*/

// 若备用空间链表非空，则返回分配的节点下标，否则返回0
int new_SLL(StaticLinkList space)
{
    int i = space[0].cur; //当前数组第一个元素的cur存的值
    if(space[0].cur)
        space[0].cur = space[i].cur; //把之前备用的地址的下一个地址用作当前的备用地址
    return i;
}

// 将下标为k的空闲节点回收到备用链表
void delete_SLL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

//在L中第i个元素之前插入新的数据元素e
void ListInsert(StaticLinkList &L, int i, ElemType e )
{
    int k = new_SLL(L); //获得空闲分量的下标
    if(k)
    {
        L[k].data = e;
        int j = MAXSIZE - 1;
        for(int m = 1; m<i;m++)
        {
            j=L[j].cur;
        }
        L[k].cur = L[j].cur;
        L[j].cur = k;
    }
}

//删除在L中的第i个数据
void ListDelete(StaticLinkList &L, int i)
{
    int k = MAXSIZE - 1;
    for(int j = 1; j <= i-1; j++)
    {
        k=L[k].cur;
    }
    int j = L[k].cur;
    L[k].cur = L[j].cur;
    delete_SLL(L, j);
}


//初始条件：静态链表已经存在。操作结果：返回L中的数据元素个数
int ListLength(StaticLinkList L)
{
    int num = 0;
    int i = MAXSIZE - 1;
    while(i)
    {
        i = L[i].cur;
        num++;
    }
    return num-1;
}

void ListPrint(StaticLinkList L)
{
    int i = MAXSIZE - 1;
    i = L[i].cur;
    while(i)
    {
        cout<<L[i].data<<" ";
        i = L[i].cur;

    }
    cout<<"tail"<<endl;
}


int main()
{
    cout<<"创建静态链表"<<endl;
    StaticLinkList SL;
    bool f = false;
    f = InitList(SL);
    int len = ListLength(SL);
    cout<<"输出链表长度:"<<len<<endl;
    ListPrint(SL);
    ListInsert(SL,1,1);
    ListInsert(SL,2,2);
    cout<<"插入元素1,2"<<endl;
    len = ListLength(SL);
    cout<<"输出链表长度:"<<len<<endl;
    ListPrint(SL);
    cout<<"删除元素1"<<endl;
    ListDelete(SL, 1);
    len = ListLength(SL);
    cout<<"输出链表长度:"<<len<<endl;
    ListPrint(SL);
    return 0;
}
