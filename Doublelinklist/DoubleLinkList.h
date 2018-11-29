#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H
#include <iostream>

using namespace std;
typedef int ElemType;

//双向链表的存储方式
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
    void CreatLinkList(int n); //创建n个元素的双向链表
    void ListInsert(int i, int e); //在第i个元素插入节点
    void TraverseLinkList();
    bool IsEmpty();
    int GetLength();
    int GetValue(int i); //获得第i个元素的值
    void deleteNode(int i);  //删除第i个元素的那一节点
    void deleteLinkList(); //删除整个链表

protected:

private:
    Node *head;
};

#endif // DOUBLELINKLIST_H
