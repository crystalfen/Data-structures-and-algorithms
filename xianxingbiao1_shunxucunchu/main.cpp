#include <iostream>

using namespace std;

// ���Ա��˳��洢�ṹ
#define MAXSIZE 20 //�洢�ռ��ʼ������
typedef int ElemType;
typedef struct SqList
{
    ElemType data[MAXSIZE];
    int length; //���Ա�ǰ����
}SqList;

// ���Ԫ�ز���
bool GetElem(SqList L, int i, ElemType& e)
{
    if(L.length==0 || i<1 || i>L.length)
        return false;
    e = L.data[i-1];
    return true;
}

// ����Ԫ��
bool ListInsert(SqList& L, int i, ElemType e)
{
    if(L.length == MAXSIZE)
        return false;
    if(i<1 || i>L.length+1)
        return false;
    if(i<L.length) // �����뵽Ԫ�ز��ڱ�β
    {
        for(int j = L.length; j>i-1; j--) //��Ҫ����λ�ú��������Ԫ�ض�����ƶ�һλ
        {
            L.data[j] = L.data[j-1];
        }
    }
    L.data[i-1] = e;  // ����Ԫ�ز���
    L.length++;
    return true;
}

// ɾ��Ԫ��
bool ListDelete(SqList& L, int i , ElemType& e)
{
    if(L.length == 0) return false;
    if( i < 1 || i > L.length)
        return false;
    e = L.data[i-1];
    if(i < L.length) // ���ɾ���Ĳ������һ��Ԫ��
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

    cout<<"ɾ����8��Ԫ��"<<endl;
    f = ListDelete(L1, 8, e);
    cout<<e<<endl;
    ListPrint(L1);
    // cout << "Hello world!" << endl;
    return 0;
}
