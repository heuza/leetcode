#include<iostream>
using namespace std;
#include <ListNode.h>
template<class T>
ListNode<T>* findKth(ListNode<T>* l,int k)
{
    ListNode<T>* front = l;
    ListNode<T>* back = l;
    if(l==NULL)return NULL;
    for(int i =0;i<k;i++) {
        front= front->next;
        if(front==NULL)
            return NULL;
    }
    while(front != NULL){
        back=back->next;
        front = front->next;
    }
    return back;
}
int main()
{
    int initial[]={7,1,2,3,4,5,6,7,6,6,6,3,3,3};
    ListNode<int> *l = IntListInit(initial,sizeof(initial)/sizeof(int));

    ListNode<int>* f;
    f = findKth(l,4);
    cout<<f->val<<endl;
    f = findKth(l,3);
    cout<<f->val<<endl;


    FinalizeList(l);
    return 0;

}
