#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class _MyQueue 
{
    stack<T> front_stk;
    stack<T> back_stk;
public:
    _MyQueue(){};
    void enqueue(T t);
    T dequeue();
};

template<typename T>
void _MyQueue<T>::enqueue(T t)
{
    back_stk.push(t);
    if(front_stk.empty()) {
        cout<<"eq flush!"<<endl;
        while(!back_stk.empty()) {
            front_stk.push(back_stk.top());
            back_stk.pop();
        }
    }
}

template<typename T>
T _MyQueue<T>::dequeue()
{
    if(front_stk.empty()) {
        cout<<"deq flush!"<<endl;
        while(!back_stk.empty()) {
            front_stk.push(back_stk.top());
            back_stk.pop();
        }
    }
    T t= front_stk.top();
    front_stk.pop();
    return t;
}
int main()
{
    _MyQueue<int> q;
    for(int i =0;i<10;i++){
        q.enqueue(i);
        if(i%2) cout<<q.dequeue()<<endl;
    }
    for(int i =0;i<5;i++)
    {
        cout<<q.dequeue()<<endl;
    }
    return 0;

}
