#include <iostream>
#include "DoubleLinkList.h"
//#include "DoubleLinkList.h"
using namespace std;







int main()
{
    DoubleLinkList dl; //����һ��˫�������
    int position, value, n;
    bool flag =false;

    cout<< "��������Ҫ����˫������Ľڵ����"<<endl;
    cin>>n;
    dl.CreatLinkList(n);

    cout << "��ӡ����ֵ���£�";
    dl.TraverseLinkList();

    cout << "������������λ�ú�ֵ��";
    cin >> position >> value;
    dl.ListInsert(position, value);


    cout << "��ӡ����ֵ���£�";
    dl.TraverseLinkList();

    cout << "������Ҫɾ������λ�ã�";
    cin >> position;
    dl.deleteNode(position);

    cout << "��ӡ����ֵ���£�";
    dl.TraverseLinkList();

    dl.deleteLinkList();

    flag = dl.IsEmpty();

    if (flag)
        cout << "ɾ������ɹ���" << endl;
    else
        cout << "ɾ������ʧ�ܣ�" << endl;

    return 0;
}


