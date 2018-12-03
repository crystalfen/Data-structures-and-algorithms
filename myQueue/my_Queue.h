

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
    int QueueLength();//���еĳ���
    bool Is_empty(); //�ж϶����Ƿ�Ϊ��
    void En_Queue(type val); //��ջ
    type De_Queue(); //��ջ
    type front_element();//ȡ��ͷԪ��
    type rear_element();//ȡ��βԪ��
    void show();//��ʾ����Ԫ��


};

#endif // MY_QUEUE_H
