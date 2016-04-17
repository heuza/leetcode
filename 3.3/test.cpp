#include<iostream>
#include<vector>
using namespace std;
class SS {
    vector< vector<int>* > sset;
    const static int MAX = 3;
    public:
    void push(int v);
    void pop();
    void popat(int);
    int top();
    SS();
};
SS::SS()
{
    sset.push_back(new vector<int>);
}
void SS::push(int v)
{
    if(sset.back()->size() >= MAX){
        sset.push_back(new vector<int>);
    }
    cout<<"sset["<<sset.size()-1<<"].size()="<<sset.back()->size()<<endl;
    cout<<"sset["<<sset.size()-1<<"].push_back("<<v<<")"<<endl;
    sset.back()->push_back(v);
}
void SS::pop()
{
    if(sset.empty() || sset.back()->empty())return;
    cout<<"POP: "<<sset.back()->back()<<endl;
    sset.back()->pop_back();
    if(sset.back()->empty()){
        delete sset.back();
        sset.pop_back();
    }
}
void SS::popat(int idx)
{
    if(sset.size() <= idx )return;
    cout<<"POPAT: "<<sset[idx]->back()<<endl;
    sset[idx]->pop_back();
    if(sset[idx]->empty()){
        delete sset[idx];
        sset.erase(sset.begin()+idx);
    }
}
int main()
{
    SS s;
    for(int i =0;i<10;i++) {
        s.push(i);
    }
    for(int i =0;i<10;i++) {
        s.pop();
        s.popat(2);
    }
    return 0;

}
