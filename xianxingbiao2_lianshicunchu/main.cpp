#include <iostream>

using namespace std;


// ���Ա�ĵ�����洢�ṹ
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList; //����LinkList

// ��ȡԪ��
bool GetElem(LinkList L,  int i, ElemType& e)
{
    LinkList p = L->next; //����һ�ڵ�p, pָ������L�ĵ�һ�����
    int j = 1;
    while( p && j!=i ) //p��Ϊ�ջ��߼�����j��û�ﵽiʱ�������
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


//����Ԫ��
bool ListInsert(LinkList& L, int i , ElemType e)
{
   LinkList p = L; //����һ�ڵ�P, Pָ��ͷ���
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

// ͷ�巨����Ԫ��
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

//β�巨����Ԫ��
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

// �����������ɾ��
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
    L->next = NULL; //����һ����ͷ���ĵ�����
    cout<<"һ.����ʼͷ����2��1"<<endl;
    ElemType e = 2;
    HeadInsert(L,e);
    e = 1;
    HeadInsert(L,e);
    printList(L);
    cout<<"��.����ʼβ����4��5"<<endl;
    e = 4;
    TailInsert(L, e);
    e = 5;
    TailInsert(L,e);
    printList(L);
    cout<<"��.�������3��λ���ϲ���3"<<endl;
    int i = 3;
    e = 3;
    bool f =  ListInsert(L, i, e);
    printList(L);
    cout<<"��.��õ�2��Ԫ��"<<endl;
    i = 2;
    int m;
    f = GetElem(L, i, m);
    cout<<"��i��Ԫ����"<<m<<endl;
    cout<<"��.ɾ����3��Ԫ��"<<endl;
    i = 3;
    f = ListDelete(L,i,m);
    cout<<"ɾ���ĵ�3��Ԫ����"<<m<<endl;
    cout<<"ɾ���������Ԫ���У�"<<" ";
    printList(L);
    cout<<"��.ɾ�������б�"<<endl;
    f = false;
    f = ClearList(L);
    cout<<"ɾ���ɹ�����"<<f<<endl;
    printList(L);
    cout << "Hello world!" << endl;
    return 0;
}
