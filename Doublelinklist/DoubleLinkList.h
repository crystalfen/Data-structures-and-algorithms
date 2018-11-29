#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H
#include <iostream>

using namespace std;
typedef int ElemType;

//˫������Ĵ洢��ʽ
//typedef sturct Node
//{
//    ElemType data;
//    struct Node *pre;
//    struct Node *next;
//}Node;

class Node
{
public:
    int data;
    Node *pre, *next;
};

class DoubleLinkList
{
public:
    DoubleLinkList();
    virtual ~DoubleLinkList();
    void CreatLinkList(int n); //����n��Ԫ�ص�˫������
    void ListInsert(int i, int e); //�ڵ�i��Ԫ�ز���ڵ�
    void TraverseLinkList();
    bool IsEmpty();
    int GetLength();
    int GetValue(int i); //��õ�i��Ԫ�ص�ֵ
    void deleteNode(int i);  //ɾ����i��Ԫ�ص���һ�ڵ�
    void deleteLinkList(); //ɾ����������

protected:

private:
    Node *head;
};

#endif // DOUBLELINKLIST_H
