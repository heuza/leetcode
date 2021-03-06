#include<map>
#include <unordered_map>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int _target;
        vector< vector<int> > ret;
        sort(nums.begin(),nums.end());
        int l,r;
        int sum;
        int min_sum=65535;
        for(int i=0;i<nums.size();i++){
            _target = target-nums[i];
            l=i+1;
            r=nums.size()-1;
            while(l<r){
                sum = nums[l]+nums[r];
                if(abs(sum-_target)<abs(min_sum))
                    min_sum=sum-_target;
                if(sum<_target) {
                    l++;
                } else if(sum>_target) {
                    r--;
                } else {
                    return target;
                }
                while(i+1<nums.size() && nums[i+1]== nums[i])i++;
            }


        }
        return min_sum+target;
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
            1,1,-1
        };
        vector<int> testIn2(testIn, testIn+sizeof(testIn)/sizeof(int));
        Solution s1;
        int res = s1.threeSumClosest(testIn2,1);
        cout<<"rest = "<<res<<endl;
        return 0;
}
