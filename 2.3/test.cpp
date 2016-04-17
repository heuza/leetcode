#include<iostream>
using namespace std;
#include<ListNode.h>
template<typename T>
void delNode(ListNode<T>* n)
{
    if(n == NULL)return;
    ListNode<T>* p = n->next;
    if(p == NULL)return;
    n->val = p->val;
    n->next = p->next;
    delete p;
}
int main()
{
    int s[]={1,2,3,4,5,6};
    ListNode<int>* l = IntListInit(s,sizeof(s)/sizeof(int));
    ListNode<int>* p = l->next->next;//3
    delNode(p);
    FinalizeList(l);
    return 0;

}
