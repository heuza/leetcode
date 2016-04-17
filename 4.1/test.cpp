#include<iostream>
#include<TreeNode.h>
using namespace std;
struct TreeHeight{
    int highest;
    int lowest;
    TreeHeight():highest(0),lowest(0){}
};
TreeHeight calTree(TreeNode* t){
    TreeHeight h,l,r;
    if(t == NULL)
        return h;
    l = calTree(t->left);
    r = calTree(t->right);
    h.highest = (l.highest> r.highest)?l.highest+1:r.highest+1;
    if(l.lowest !=0 && r.lowest != 0)
        h.lowest = (l.lowest> r.lowest)?r.lowest+1:l.lowest+1;
    else {
        h.lowest = r.lowest+1;
    }
    return h;
}
bool isBalance(TreeNode* t){
    TreeHeight h = calTree(t);
    return (h.highest - h.lowest) < 2;
}
class MyTOP: public TreeOP
{
    public:
    //void operate(TreeNode* p){ cout<<p->val<<" ";}
    virtual void operate( TreeNode* p );
};
void MyTOP::operate( TreeNode* p)
{
    cout<<p->val<<" ";
}

int main()
{
    int tree[] = {1,2,3,0,0,4,5};
    TreeNode* p;
    p = InitTree(tree,sizeof(tree)/sizeof(int),0);
    MyTOP op;
    BFS(p,&op);
    return 0;

}
