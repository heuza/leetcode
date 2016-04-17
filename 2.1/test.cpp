#include<iostream>
#include<unordered_set>
using namespace std;
template<class T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode(T n):val(n),next(NULL){};
};
template<class T>
void removeDuplicate(ListNode<T>* l)
{
    unordered_set<T> mset;
    ListNode<T>* p = l;
    ListNode<T>* last = l;
    pair<typename unordered_set<T>::iterator,bool> ret;
    while(p!=NULL) {
        ret = mset.insert(p->val);
        cout<<"bool "<<ret.second<<endl;
        if(!ret.second){
            last->next = p->next;
            delete p;
            p= last->next;
        } else {
            last = p;
            p= p->next;
        }
    }
}
class obj{
    public:
    int val1;
    int val2;
    obj(obj& o):val1(o.val1),val2(o.val2){};
    obj(const obj& o):val1(o.val1),val2(o.val2){};
    obj(int v1, int v2):val1(v1),val2(v2){};
};
int main()
{
    //Initialize
    ListNode<int>* n = new ListNode<int>(1);
    int initial[]={7,1,2,3,4,5,6,7,6,6,6,3,3,3};
    ListNode<int>* p=n ;
    for(int i =0 ;i<sizeof(initial)/sizeof(int);i++){
       p->next = new ListNode<int>(initial[i]);
       p=p->next; 
    }

    //Test Template
    //ListNode<obj>* n = new ListNode<obj>(obj(1,1));
    //obj o(1,1);

    //Main Body
    removeDuplicate(n);




    //Finalize
    for(ListNode<int>* p = n; p != NULL ;) {
        ListNode<int>* _p = p;
        p = p->next;
        cout<<_p->val<<" ";
        delete _p;
    }
    cout<<endl;

    return 0;
}
