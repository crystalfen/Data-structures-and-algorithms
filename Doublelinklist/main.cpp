#include <iostream>
#include "DoubleLinkList.h"
//#include "DoubleLinkList.h"
using namespace std;







int main()
{
    DoubleLinkList dl; //创建一个双链表对象
    int position, value, n;
    bool flag =false;

    cout<< "请输入需要创建双向链表的节点个数"<<endl;
    cin>>n;
    dl.CreatLinkList(n);

    cout << "打印链表值如下：";
    dl.TraverseLinkList();

    cout << "请输入插入结点的位置和值：";
    cin >> position >> value;
    dl.ListInsert(position, value);


    cout << "打印链表值如下：";
    dl.TraverseLinkList();

    cout << "请输入要删除结点的位置：";
    cin >> position;
    dl.deleteNode(position);

    cout << "打印链表值如下：";
    dl.TraverseLinkList();

    dl.deleteLinkList();

    flag = dl.IsEmpty();

    if (flag)
        cout << "删除链表成功！" << endl;
    else
        cout << "删除链表失败！" << endl;

    return 0;
}


