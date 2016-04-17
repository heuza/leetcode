#ifndef _TREENODE_H_
#define _TREENODE_H_
#include<queue>
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int k):val(k),left(NULL),right(NULL),parent(NULL){};
};
TreeNode* InitTree(int number[],int len,int index){
    TreeNode* l;
    TreeNode* r;
    if(index >= len || number[index] == 0)
        return NULL;
    //std::cout<<"index="<<index<<": "<<number[index]<<" ";
    //std::cout<<number[index]<<" ";
    TreeNode* root = new TreeNode(number[index]);
    l = InitTree(number, len, index*2+1);
    r = InitTree(number, len, index*2+2);
    root->left = l;
    root->right = r;
    return root;
}
class TreeOP {
    public:
    virtual void operate( TreeNode* p )=0;
};
void BFS(TreeNode* t, TreeOP* op){
    std::queue<TreeNode*> myq;
    myq.push(t);
    TreeNode* curr;
    while(!myq.empty()){
        curr = myq.front();
        if(curr){
        //if(curr->left != NULL)
            myq.push(curr->left);
        //if(curr->right != NULL)
            myq.push(curr->right);
        op->operate(curr);
        //std::cout<<curr->val<<" ";
        } else {
        std::cout<<"null ";
        }
        myq.pop();
    }
}
#endif //_TREENODE_H_
