#include<iostream>
#include<vector>
using namespace std;
vector< vector<int> > ts;
void MoveHanoi3(int n,int s,int b, int d)
{
    //for(int i=0;i<ts.size();i++){
    //    cout<<"ts["<<i<<"]={";
    //    for(int j=0;j<ts[i].size();j++) {
    //        cout<<ts[i][j]<<",";
    //    }
    //    cout<<"}\n";
    //}
    if(n == 1){
        if(ts[s].empty()) return;
        ts[d].push_back(ts[s].back());
        ts[s].pop_back();
        for(int i=0;i<ts.size();i++){
            cout<<"ts["<<i<<"]={";
            for(int j=0;j<ts[i].size();j++) {
                cout<<ts[i][j]<<",";
            }
            cout<<"}\n";
        }
    } 
    else {
        if(ts[s].empty()) return;
        MoveHanoi3(n-1,s,d,b);
        ts[d].push_back(ts[s].back());
        ts[s].pop_back();
        for(int i=0;i<ts.size();i++){
            cout<<"ts["<<i<<"]={";
            for(int j=0;j<ts[i].size();j++) {
                cout<<ts[i][j]<<",";
            }
            cout<<"}\n";
        }
        MoveHanoi3(n-1,b,s,d);
    }
}
void MoveHanoi2(int n,int s,int b, int d)
{
    //for(int i=0;i<ts.size();i++){
    //    cout<<"ts["<<i<<"]={";
    //    for(int j=0;j<ts[i].size();j++) {
    //        cout<<ts[i][j]<<",";
    //    }
    //    cout<<"}\n";
    //}
    if(n == 1){
        if(ts[s].empty()) return;
        ts[d].push_back(ts[s].back());
        ts[s].pop_back();
        for(int i=0;i<ts.size();i++){
            cout<<"ts["<<i<<"]={";
            for(int j=0;j<ts[i].size();j++) {
                cout<<ts[i][j]<<",";
            }
            cout<<"}\n";
        }
    } 
    else {
        if(ts[s].empty()) return;
        MoveHanoi2(n-1,s,d,b);
        ts[d].push_back(ts[s].back());
        ts[s].pop_back();
        for(int i=0;i<ts.size();i++){
            cout<<"ts["<<i<<"]={";
            for(int j=0;j<ts[i].size();j++) {
                cout<<ts[i][j]<<",";
            }
            cout<<"}\n";
        }
        MoveHanoi2(n-1,b,d,s);
    }
}
int main()
{
    int tower[]={4,3,2,1,0};
    vector<int> towerV[3]={vector<int>(tower, tower+sizeof(tower)/sizeof(int)),};
    vector< vector<int> > tower_set(towerV,towerV+sizeof(towerV)/sizeof(vector<int>));
    ts = tower_set;
    cout<<tower_set.size()<<endl;
    for(int i=0;i<ts.size();i++){
        cout<<"ts["<<i<<"]={";
        for(int j=0;j<ts[i].size();j++) {
            cout<<ts[i][j]<<",";
        }
        cout<<"}\n";
    }
    MoveHanoi2(5,0,2,1);
    //for(int i=0;i<8;i=i+2)
    //    MoveHanoi3(5,i,i+2,i+1);
    return 0;
}
