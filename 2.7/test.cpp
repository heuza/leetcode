#include<iostream>
using namespace std;
#include<ListNode.h>
bool isPalindrome(ListNode<int> *l)
{
    ListNode<int>* _reverse = NULL;
    ListNode<int>* reverse = _reverse;
    ListNode<int> *p = l;
    int len = 0;
    while(p) {
        reverse = new ListNode<int>(p->val,reverse);
        p = p->next;
        len++;
    }
    p = l;
    _reverse = reverse;
    while(p!=NULL && _reverse != NULL) {
        if(p->val!= _reverse->val) {
            FinalizeList(reverse);
            return false;
        }
        p = p->next;
        _reverse = _reverse->next;
    }
    return true;
}
int main()
{
    int s[] = {1,2,3,4,5,4,3,2,1};
    ListNode<int>* l = IntListInit(s,sizeof(s)/sizeof(int));
    bool ret = isPalindrome(l);
    cout<<"isPalindrome="<<ret<<endl;
    FinalizeList(l);
    int s2[] = {1,2,3,4,4,3,2,1};
    l = IntListInit(s2,sizeof(s2)/sizeof(int));
    ret = isPalindrome(l);
    cout<<"isPalindrome="<<ret<<endl;
    FinalizeList(l);
    return 0;
}
