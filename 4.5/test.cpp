#include<iostream>
#include<TreeNode.h>
using namespace std;
bool isBST(TreeNode* t,int MAX, int MIN){
    bool ret = true;
    if(t->left) {
        if(t->left < t->val){
            ret &= isBst(t->left,t->val, MIN);
        } else {
            return false;
        }
    }
    if(t->right) {
        if( t->right > t->val){
            ret &= isBst(t->right,MAX, t->val);
        } else {
            return false;
        }
    }
    return ret;
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
