#ifndef MY_STACK_H
#define MY_STACK_H
#include <iostream>
using namespace std;
#define MAXSIZE 0xffff

//ʹ��Templateģ����

template<typename type>
class my_stack
{
    int top;
    type* my_s;
    int maxsize;

public:
    my_stack();
    my_stack(int size);
    virtual ~my_stack();
    bool Empty(); // �ж��Ƿ�Ϊ��
    void Push(type val);
    void Pop(); //��ջ
    type Top();
    int Size();

};

#endif // MY_STACK_H
