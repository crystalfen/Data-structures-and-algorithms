

#ifndef MY_QUEUE_H
#define MY_QUEUE_H
#define MAXSIZE 100


template<typename type>
class my_Queue
{
    type* my_q;
    int maxsize;
    int front0, rear;
public:
    my_Queue();
    my_Queue(int mysize);
    virtual ~my_Queue();
    int QueueLength();//队列的长度
    bool Is_empty(); //判断队列是否为空
    void En_Queue(type val); //入栈
    type De_Queue(); //出栈
    type front_element();//取队头元素
    type rear_element();//取队尾元素
    void show();//显示队列元素


};

#endif // MY_QUEUE_H
