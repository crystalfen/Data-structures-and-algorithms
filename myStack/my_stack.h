#ifndef MY_STACK_H
#define MY_STACK_H
#include <iostream>
using namespace std;
#define MAXSIZE 0xffff

//使用Template模板类

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
    bool Empty(); // 判断是否为空
    void Push(type val);
    void Pop(); //出栈
    type Top();
    int Size();

};

#endif // MY_STACK_H
