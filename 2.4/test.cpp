#include<iostream>
using namespace std;
#include<ListNode.h>
ListNode<int>* partition(ListNode<int> * l, int x)
{
    ListNode<int>* front;
    ListNode<int>* back;
    ListNode<int>* p1;
    ListNode<int>* p2;
    front = new ListNode<int>(-1);
    back = new ListNode<int>(-1);
    p1 = front;
    p2 = back;
    while(l){
        if(l->val < x) {
            p1->next = l;
            l = l->next;
            p1=p1->next;
        } else {
            p2->next = l;
            l = l->next;
            p2 =p2->next;
        }
    }
    p1->next = back->next;
    delete back;
    p1 = front->next;
    delete front;
    return p1;
}
int main()
{
    int s[]={5,4,3,2,1,6,7,8};
    ListNode<int>* l = IntListInit(s,sizeof(s)/sizeof(int));
    l = partition(l,4);
    FinalizeList(l);
    return 0;
}
