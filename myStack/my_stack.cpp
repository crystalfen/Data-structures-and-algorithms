#include "my_stack.h"
#include <iostream>
using namespace std;
#define MAXSIZE 0xffff

// π”√Templateƒ£∞Â¿‡

template<typename type>

my_stack<type>::my_stack()
{
    //ctor
    top = -1;
    maxsize = MAXSIZE;
    my_s = new type[maxsize];
    if(my_s == NULL)
    {
        cout<<"∂ØÃ¨¥Ê¥¢∑÷≈‰ ß∞‹"<<endl;
        exit(-1);
    }
}

template<typename type>
my_stack<type>::my_stack(int size)
{
    top = -1;
    maxsize = size;
    my_s = new type[maxsize];
    if(my_s == NULL)
    {
        cout<<"∂ØÃ¨¥Ê¥¢∑÷≈‰ ß∞‹"<<endl;
        exit(-1);
    }
}

template<typename type>
my_stack<type>::~my_stack()
{
    //dtor
    delete[] my_s;
}

template<typename type>
bool my_stack<type>::Empty()
{
    if(top==-1)
        return true;
    else
        return false;
}

template<typename type>
type my_stack<type>::Top()
{
    if(top!=-1)
    {
        return my_s[top];
    }
    else
    {
        cout<<"’ªø’"<<endl;
        exit(1);
    }
}

template<typename type>
void my_stack<type>::Push(type val)
{
    if(top<maxsize-1)
    {
        my_s[++top] = val;
    }
    else
    {
        cout<<"’ª¬˙"<<endl;
        exit(1);
    }
}

template<typename type>
void my_stack<type>::Pop()
{
     if(top>=0)
    {
       top--;
    }
    else
    {
        cout<<"’ªø’"<<endl;
        exit(1);
    }
}


template<typename type>
int my_stack<type>::Size()
{
    return top+1;
}
