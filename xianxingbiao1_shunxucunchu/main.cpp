#include <iostream>

using namespace std;

// 线性表的顺序存储结构
#define MAXSIZE 20 //存储空间初始分配量
typedef int ElemType;
typedef struct SqList
{
    ElemType data[MAXSIZE];
    int length; //线性表当前长度
}SqList;

// 获得元素操作
bool GetElem(SqList L, int i, ElemType& e)
{
    if(L.length==0 || i<1 || i>L.length)
        return false;
    e = L.data[i-1];
    return true;
}

// 插入元素
bool ListInsert(SqList& L, int i, ElemType e)
{
    if(L.length == MAXSIZE)
        return false;
    if(i<1 || i>L.length+1)
        return false;
    if(i<L.length) // 若插入到元素不在表尾
    {
        for(int j = L.length; j>i-1; j--) //将要插入位置后面的数据元素都向后移动一位
        {
            L.data[j] = L.data[j-1];
        }
    }
    L.data[i-1] = e;  // 将新元素插入
    L.length++;
    return true;
}

// 删除元素
bool ListDelete(SqList& L, int i , ElemType& e)
{
    if(L.length == 0) return false;
    if( i < 1 || i > L.length)
        return false;
    e = L.data[i-1];
    if(i < L.length) // 如果删除的不是最后一个元素
    {
        for(int j = i; j<L.length; j++)
        {
            L.data[j-1] = L.data[j];
        }
    }
    L.length--;
    return true;

}

void ListPrint(SqList L)
{
    for(int i = 0 ; i < L.length; i++)
        cout<<L.data[i]<<" ";
    cout<<endl;
}

int main()
{
    SqList L1;
    // L1.data = {0, 1, 2, 3, 4};
    L1.length = 0;

    bool f = true;
    int i = 1;
    while(f)
    {

        f = ListInsert(L1,i,i-1);
        i++;
    }

    ListPrint(L1);

    ElemType e;
    f = GetElem(L1, 3, e);
    cout<<e<<endl;

    cout<<"删除第8个元素"<<endl;
    f = ListDelete(L1, 8, e);
    cout<<e<<endl;
    ListPrint(L1);
    // cout << "Hello world!" << endl;
    return 0;
}
