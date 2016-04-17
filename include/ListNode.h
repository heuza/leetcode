#ifndef _LISTNODE_H
#define _LISTNODE_H
template<class T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode(T n):val(n),next(NULL){};
    ListNode(T n, ListNode<T> *p):val(n),next(p){};
};

ListNode<int>* IntListInit(int s[],int len)
{
    //Initialize
    ListNode<int>* n = new ListNode<int>(1);
    //int initial[]={7,1,2,3,4,5,6,7,6,6,6,3,3,3};
    ListNode<int>* p=n ;
    for(int i =0 ;i<len;i++){
       p->next = new ListNode<int>(s[i]);
       p=p->next; 
    }
    p=n->next;
    delete n;
    return p;
}
void FinalizeList(ListNode<int> * l)
{
    for(ListNode<int>* p = l; p != NULL ;) {
        ListNode<int>* _p = p;
        p = p->next;
        cout<<_p->val<<" ";
        delete _p;
    }
    cout<<endl;
}

#endif //_LISTNODE_H
