#include <iostream>
//#include "my_Queue.h"
#include "my_Queue.cpp"
using namespace std;

int main()
{
    //创建队列对象
    my_Queue<int> q;
    // 判断是否为空
    cout<<"队列为空吗："<<q.Is_empty()<<endl;
    // 入队操作
    for(int i = 0; i < 20; i++)
    {
        q.En_Queue(i);
    }
    cout<<"队列的长度为: "<<q.QueueLength()<<endl;
    cout<<"队列元素有: ";
    q.show();
    cout<<"队头元素: "<<q.front_element()<<endl;
    cout<<"队尾元素: "<<q.rear_element()<<endl;

    //出队操作
    cout<<"元素依次出队: ";
    for(int i = 0; i < 10; i++)
    {
        int val = q.De_Queue();
        cout<<val<<" ";
    }
    cout<<endl;

     cout<<"队列的长度为: "<<q.QueueLength()<<endl;
    cout<<"队列元素有: ";
    q.show();
    cout<<"队头元素: "<<q.front_element()<<endl;
    cout<<"队尾元素: "<<q.rear_element()<<endl;

    return 0;
}
