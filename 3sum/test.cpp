#include<map>
#include <unordered_map>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        int target;
        vector< vector<int> > ret;
        sort(nums.begin(),nums.end());
        int l,r;
        int sum;
        for(int i=0;i<nums.size();i++){
            target = -nums[i];
            l=i+1;
            r=nums.size()-1;
            while(l<r){
                sum = nums[l]+nums[r];
                if(sum<target) {
                    l++;
                } else if(sum>target) {
                    r--;
                } else {
                    vector<int> res(3,0);
                    res[0]= nums[i];
                    res[1]= nums[l];
                    res[2]= nums[r];
                    ret.push_back(res);
                    while(l<r&& nums[l] == res[1])l++;
                    while(l<r&& nums[r] == res[2])r--;
                }
                while(i+1<nums.size() && nums[i+1]== nums[i])i++;
            }


        }
        //sort(ret.begin(),ret.end());
        //ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
};
int main() {
        int target=9;
        vector<int> mynumber;
        vector< vector<int> > myresult;
        mynumber.push_back(-1);
        mynumber.push_back(-1);
        mynumber.push_back(0);
        mynumber.push_back(1);
        mynumber.push_back(2);
        mynumber.push_back(4);
        //int testIn[] = {
        //   7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6
        //;
        int testIn[] = {
            0,0,0
        };
        vector<int> testIn2(testIn, testIn+sizeof(testIn)/sizeof(int));
        Solution s1;
        myresult=s1.threeSum(testIn2);
        //myresult=s1.threeSum(mynumber);
        for(int i=0;i<myresult.size();i++) {
            for(int j = 0;j<myresult[i].size();j++)
                cout<<myresult[i][j]<<",";
            cout<<endl;
        }
        return 0;
}
