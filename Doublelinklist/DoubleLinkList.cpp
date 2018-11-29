#include "DoubleLinkList.h"

DoubleLinkList::DoubleLinkList()
{
    //ctor
    head = new Node;
    head->data = 0;
    head->pre = NULL;
    head->next = NULL;
}

DoubleLinkList::~DoubleLinkList()
{
    //dtor

    delete head;

}

void DoubleLinkList::CreatLinkList(int n)
{
    if(n<0)
    {
        cout<<"�������������"<<endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        int i = 1;
        Node *ptemp = head;
        Node *pnew;
        while(n-- > 0)
        {
            cout<<"�������"<<i<<"�����:";
            int e;
            cin>>e;
            pnew = new Node;
            pnew->data = e;
            pnew->next = NULL;
            pnew->pre = ptemp;
            ptemp->next = pnew;
            ptemp = pnew;
            i++;
        }

    }
}

int DoubleLinkList::GetLength()
{
    int len = 0;
    Node *p = head;
    while(p->next)
    {
        len++;
        p = p->next;
    }
    return len;

}

void DoubleLinkList::ListInsert(int i, int e)
{
    if(i<=0 || i > GetLength())
    {
        cout<<"�������ݴ���"<<endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        Node *p = head;
        Node *pnew;
        int j = 1;
        while(j<=i-1)
        {
            p = p->next;
            j++;
        }
        pnew = new Node;
        pnew->data = e;
        if(p->next != NULL)
            p->next->pre = pnew;
        pnew->next = p->next;
        pnew->pre = p;
        p->next = pnew;

    }
}

int DoubleLinkList::GetValue(int i)
{

    Node *p = head;
    while(i-->0)
    {
        p=p->next;
    }
    return p->data;
}

void DoubleLinkList::deleteNode(int i)
{
    if(i <= 0 || i > GetLength())
    {
        cout<<"ɾ���Ľڵ㲻����"<<endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        Node *p = head;
        while(--i > 0)
        {
            p = p->next;
        }
        Node *deln = p->next;
        if(deln->next != NULL) //ɾ�����������β�ڵ㣬��Ҫ�࿼��һ��
            deln->next->pre = p;
        p->next = deln->next;
        delete(deln);


    }
}

bool DoubleLinkList::IsEmpty()
{
    if(head->next == NULL)
        return true;
    else
        return false;
}

void DoubleLinkList::TraverseLinkList()
{
    Node *p = head->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;

}

void DoubleLinkList::deleteLinkList()
{
    for(int i = 1; i <= GetLength(); i++)
        deleteNode(i);
}
