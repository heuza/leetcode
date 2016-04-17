#include<iostream>
#include<TreeNode.h>
#include<queue>
using namespace std;
#define MAXN 5
char g[MAXN][MAXN] = {
    0,1,0,0,0,
    1,0,1,0,0,
    0,1,0,1,0,
    0,0,1,0,1,
    0,0,0,1,0,
};
bool route(int s, int d,char g[MAXN][MAXN], int n)
{
    char visited[n] ;
    memset(visited,0,n);
    queue<char> myq;
    myq.push(s);
    int cur;
    while(!myq.empty()){
        cur = myq.front();
        if(cur == d)return true;
        visited[cur] = 1;
        for(int i =0;i<n;i++){
            if(g[cur][i] && visited[i] != 1)
                myq.push(i);
        }
        myq.pop();
    }
    return false;
}
int main()
{
    cout<<route(0,4,g,5)<<endl;
    return 0;
}
