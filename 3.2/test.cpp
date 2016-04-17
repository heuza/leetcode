#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class minStack{
    vector<int> stk;
    vector<int> mstk;
    int head;
    int mhead;
    public:
        int pop();
        int top();
        int min();
        void push(int); 
        minStack(){
            head = -1;
            mhead = -1;
        };
};
void minStack::push(int val){
    if(mhead >=0) {
        if(val<= mstk[head]) {
            mstk.push_back(val);
            mhead++;
        }
    } else {
        mstk.push_back(val);
        mhead++;
    }
    stk.push_back(val);
    head++;
}
int minStack::top(){
    if(head>=0) return stk[head];
    return 0;
}
int minStack::pop(){
    if(head>=0) {
        if(mstk[mhead] == stk[head]) {
            mstk.pop_back();
            mhead--;
        }
        stk.pop_back();
        head--;
    }
    return 0;
}
int minStack::min(){
    if(mhead>=0){
        return mstk[mhead];
    }
    return 0;
}
int main()
{
    return 0;

}
