#include <iostream>
//#include "my_Queue.h"
#include "my_Queue.cpp"
using namespace std;

int main()
{
    //�������ж���
    my_Queue<int> q;
    // �ж��Ƿ�Ϊ��
    cout<<"����Ϊ����"<<q.Is_empty()<<endl;
    // ��Ӳ���
    for(int i = 0; i < 20; i++)
    {
        q.En_Queue(i);
    }
    cout<<"���еĳ���Ϊ: "<<q.QueueLength()<<endl;
    cout<<"����Ԫ����: ";
    q.show();
    cout<<"��ͷԪ��: "<<q.front_element()<<endl;
    cout<<"��βԪ��: "<<q.rear_element()<<endl;

    //���Ӳ���
    cout<<"Ԫ�����γ���: ";
    for(int i = 0; i < 10; i++)
    {
        int val = q.De_Queue();
        cout<<val<<" ";
    }
    cout<<endl;

     cout<<"���еĳ���Ϊ: "<<q.QueueLength()<<endl;
    cout<<"����Ԫ����: ";
    q.show();
    cout<<"��ͷԪ��: "<<q.front_element()<<endl;
    cout<<"��βԪ��: "<<q.rear_element()<<endl;

    return 0;
}
