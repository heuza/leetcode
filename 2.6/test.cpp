#include<iostream>
#include<unordered_set>
using namespace std;
#include<ListNode.h>
ListNode<int>* circly(ListNode<int>* l)
{
    unordered_set<uint64_t> mset;
    pair< unordered_set<uint64_t>::iterator, bool> ret;
    ListNode<int>* last = l;
    while(l){
        ret = mset.insert((uint64_t)l);
        if(ret.second) {
            last = l;
            l=l->next;
        } else {
            cout<<"l->val="<<l->val<<endl;
            last->next = NULL;
            return l;
        }
    }
    return NULL;
}
int main()
{
    int s[] = {1,2,3,4,5,6,7};
    ListNode<int>* l = IntListInit(s,sizeof(s)/sizeof(int));
    ListNode<int>* t=l;
    while(t->next)t=t->next;
    t->next = l->next->next->next; //4
    circly(l);

    FinalizeList(l);
    return 0;

}
