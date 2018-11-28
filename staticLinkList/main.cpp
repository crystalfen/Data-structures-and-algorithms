#include <iostream>

using namespace std;
typedef int ElemType;

#define MAXSIZE 1000 //�����������󳤶���1000

//���Ա�ľ�̬��ʽ�洢�ṹ
typedef struct
{
    ElemType data;
    int cur;
}Component, StaticLinkList[MAXSIZE];

//��ʼ����̬����.��һά����space�и���������һ��������
bool InitList(StaticLinkList space)
{
    for(int i = 0 ; i < MAXSIZE - 1; i++)
    {
        space[i].cur = i + 1;
    }
    space[MAXSIZE-1].cur = 0;
    return true;
}

/*�ڶ�̬�����У��ڵ��������ͷ���ͨ��new��delete������ɵģ��ھ�̬����
�У������������飬��������̬����Ľڵ�������ͷ����⣬
����������Ҫ�Լ�ʵ������������*/

// �����ÿռ�����ǿգ��򷵻ط���Ľڵ��±꣬���򷵻�0
int new_SLL(StaticLinkList space)
{
    int i = space[0].cur; //��ǰ�����һ��Ԫ�ص�cur���ֵ
    if(space[0].cur)
        space[0].cur = space[i].cur; //��֮ǰ���õĵ�ַ����һ����ַ������ǰ�ı��õ�ַ
    return i;
}

// ���±�Ϊk�Ŀ��нڵ���յ���������
void delete_SLL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

//��L�е�i��Ԫ��֮ǰ�����µ�����Ԫ��e
void ListInsert(StaticLinkList &L, int i, ElemType e )
{
    int k = new_SLL(L); //��ÿ��з������±�
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

//ɾ����L�еĵ�i������
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


//��ʼ��������̬�����Ѿ����ڡ��������������L�е�����Ԫ�ظ���
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
    cout<<"������̬����"<<endl;
    StaticLinkList SL;
    bool f = false;
    f = InitList(SL);
    int len = ListLength(SL);
    cout<<"���������:"<<len<<endl;
    ListPrint(SL);
    ListInsert(SL,1,1);
    ListInsert(SL,2,2);
    cout<<"����Ԫ��1,2"<<endl;
    len = ListLength(SL);
    cout<<"���������:"<<len<<endl;
    ListPrint(SL);
    cout<<"ɾ��Ԫ��1"<<endl;
    ListDelete(SL, 1);
    len = ListLength(SL);
    cout<<"���������:"<<len<<endl;
    ListPrint(SL);
    return 0;
}
