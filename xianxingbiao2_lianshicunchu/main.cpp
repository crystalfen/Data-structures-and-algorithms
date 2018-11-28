#include <iostream>

using namespace std;


// 线性表的单链表存储结构
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList; //定义LinkList

// 获取元素
bool GetElem(LinkList L,  int i, ElemType& e)
{
    LinkList p = L->next; //定义一节点p, p指向链表L的第一个结点
    int j = 1;
    while( p && j!=i ) //p不为空或者计数器j还没达到i时，向后移
    {
        p=p->next;
        j++;
    }
    if(p)
    {
        e = p->data;
        return true;
    }
    else
    {
        return false;
    }

}


//插入元素
bool ListInsert(LinkList& L, int i , ElemType e)
{
   LinkList p = L; //定义一节点P, P指向头结点
   int j = 1;
   while(p && j <i )
   {
       p=p->next;
       j++;
   }
   if(!p || j>i)
    return false;
   LinkList s = new Node;
   s->data = e;
   s->next = p->next;
   p->next = s;
   return true;
}


bool ListDelete(LinkList& L, int i, ElemType& e)
{
    LinkList p = L;
    int j = 1;
    while(p->next && j < i)
    {
        p = p->next;
        j++;
    }
    if(!(p->next) || j > i)
        return false;
    LinkList q;
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return true;
}

// 头插法插入元素
void HeadInsert(LinkList& L, ElemType e)
{
    LinkList p=L;
    LinkList q, s;
    q = L->next;
    s = new Node;
    s->data = e;
    p->next = s;
    s->next = q;

}

//尾插法插入元素
void TailInsert(LinkList& L, ElemType e)
{
    LinkList p = L;
    while(p->next)
    {
        p=p->next;
    }
    LinkList s = new Node;
    s->data = e;
    s->next = NULL;
    p->next = s;
}

// 单链表的整表删除
bool ClearList(LinkList& L)
{
    LinkList p = L->next ;
    while(p)
    {
        LinkList q = p->next;
        free(p);
        p = q;

    }
    L->next = NULL;
    return true;
}

void printList(LinkList L)
{
    LinkList p = L->next;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}


int main()
{
    LinkList L = new Node;
    L->next = NULL; //建立一个带头结点的单链表
    cout<<"一.链表开始头插入2和1"<<endl;
    ElemType e = 2;
    HeadInsert(L,e);
    e = 1;
    HeadInsert(L,e);
    printList(L);
    cout<<"二.链表开始尾插入4和5"<<endl;
    e = 4;
    TailInsert(L, e);
    e = 5;
    TailInsert(L,e);
    printList(L);
    cout<<"三.在链表第3个位置上插入3"<<endl;
    int i = 3;
    e = 3;
    bool f =  ListInsert(L, i, e);
    printList(L);
    cout<<"四.获得第2个元素"<<endl;
    i = 2;
    int m;
    f = GetElem(L, i, m);
    cout<<"第i个元素是"<<m<<endl;
    cout<<"五.删除第3个元素"<<endl;
    i = 3;
    f = ListDelete(L,i,m);
    cout<<"删除的第3个元素是"<<m<<endl;
    cout<<"删除后的链表元素有："<<" ";
    printList(L);
    cout<<"六.删除整个列表"<<endl;
    f = false;
    f = ClearList(L);
    cout<<"删除成功了吗："<<f<<endl;
    printList(L);
    cout << "Hello world!" << endl;
    return 0;
}
