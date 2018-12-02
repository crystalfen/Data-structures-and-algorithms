
#include <iostream>
#include "my_stack.cpp"
#include<stack>
using namespace std;


int main()
{
    my_stack<int> stk;
    stack<int> s;
    for(int i=0; i<50; i++)
    {
        stk.Push(i);
        s.push(i);
    }
    cout<<"栈的大小"<<stk.Size()<<endl;
    //while(!stk.Empty())
    //{

    //    cout<<stk.Top()<<endl;
    //    stk.Pop();
    //}
    while(!s.empty())
    {

       // cout<<s.top()<<endl;
        s.pop();
    }
   // cout<<stk.Top()<<endl;
    cout<<s.top()<<endl; //注意栈空的时候，不能引用top()函数。
    cout<<"mysize()="<<stk.Size()<<"\nmysizeof="<<sizeof(stk)<<endl;
    cout<<"size()="<<s.size()<<"\nsizeof="<<sizeof(s)<<endl;
    return 0;
}
