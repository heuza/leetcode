#include<iostream>
#include<TreeNode.h>
#include<vector>
#include<list>
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
struct NodeLevel{
    int level;
    TreeNode* p;
    NodeLevel(int l):level(l),p(NULL){};
    NodeLevel():level(0),p(NULL){};
    NodeLevel(int l,TreeNode* _p):level(l),p(_p){};
};
vector< list<TreeNode*> > LevelLink( TreeNode* p )
{
    int level =0;
    list<TreeNode*> l;
    vector< list<TreeNode*> > ret;
    queue<NodeLevel> myq;
    NodeLevel element(level,p);
    element.p = p;
    myq.push(element);
    NodeLevel cur;
    ret.push_back(l);
    while(!myq.empty()) {
        cur = myq.front();
        if(cur.p->left){
            NodeLevel element(cur.level+1,cur.p->left);
            element.p = cur.p->left;
            myq.push(element);
        }
        if(cur.p->right){
            NodeLevel element(cur.level+1,cur.p->right);
            element.p = cur.p->right;
            myq.push(element);
        }
        if(cur.level == level) {
            ret[level].push_back(cur.p);
        } else {
            level++;
            ret.push_back(l);
            ret[level].push_back(cur.p);
        }
        myq.pop();
    }
    return ret;
}
int main()
{
    int tree[] = {1,2,3,0,0,4,5};
    TreeNode* p;
    p = InitTree(tree,sizeof(tree)/sizeof(int),0);
    vector< list<TreeNode*> > t;
    list<TreeNode*>::iterator il ;
    t = LevelLink(p);
    for(int i = 0;i< t.size();i++){
        for(il=t[i].begin();il!=t[i].end();il++){
            cout<<(*il)->val<<" ";
        }
        cout<<endl;
    }
    return 0;

}
