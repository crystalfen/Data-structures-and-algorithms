//创建的循环队列。当front=rear=0时，队列为空。rear总是最后一个元素的下一位置。当数组还剩一个空闲空间时，定义为队满。
//顺序存储结构。
#include "my_Queue.h"
#include <iostream>
using namespace std;
#define MAXSIZE 100

//使用Template模板类

template<typename type>

my_Queue<type>::my_Queue()
{
    //ctor
    maxsize = MAXSIZE;
    front0 = 0;
    rear = 0;
    my_q = new type[maxsize];
    if(my_q == NULL)
    {
        cout<<"动态存储分配失败"<<endl;
        exit(-1);
    }
}

template<typename type>
my_Queue<type>::my_Queue(int mysize)
{
    maxsize = mysize;
    front0 = 0;
    rear = 0;
    my_q = new type[maxsize];
    if(my_q == NULL)
    {
        cout<<"动态存储分配失败"<<endl;
        exit(-1);
    }
}


template<typename type>
my_Queue<type>::~my_Queue()
{
    //dtor
    delete[] my_q;
}

template<typename type>
int my_Queue<type>::QueueLength()
{

    return (rear-front0+maxsize) % maxsize;
}


template<typename type>
bool my_Queue<type>::Is_empty()
{
    if(rear==front0)
        return true;
    else
        return false;
}


template<typename type>
void my_Queue<type>::En_Queue(type val)
{
    //cout<<maxsize<<endl;
    //cout<<"front0="<<front0<<endl;
    //cout<<"rear="<<rear<<endl;
    //cout<<(rear+1)%maxsize<<endl;
    if((rear+1)%maxsize==front0) //队满
    {
        cout<<"队满"<<endl;
        exit(1);
    }
    else
    {
        my_q[rear] = val;
        rear = (rear + 1) % maxsize;
    }
}


template<typename type>
type my_Queue<type>::De_Queue()
{
    if(front0 == rear)
    {
        cout<<"队空"<<endl;
        exit(1);
        return -1;
    }
    else
    {
        type val = my_q[front0];
        front0 = (front0+1) % maxsize;
        return val;
    }

}

template<typename type>
type my_Queue<type>::front_element()
{
    return my_q[front0];
}

template<typename type>
type my_Queue<type>::rear_element()
{
    return my_q[(rear-1)% maxsize];
}

template<typename type>
void my_Queue<type>::show()
{
    if(front0 == rear)
    {
        cout<<"队空"<<endl;
        exit(1);
    }
    else if(front0 < rear)
    {
        for(int i = front0; i < rear; i++)
            cout<<my_q[i]<<" ";
        cout<<endl;
    }
    else
    {
        for(int i = front0; i < maxsize + rear; i++)
        {
            //if(i>=maxsize)
            //   i = i - maxsize;
            cout<<my_q[i % maxsize]<<" ";
        }
        cout<<endl;
    }
}
