#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
LeetCode 747 Largest Number At Least Twice of Others
Input: nums = [3,6,1,0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more twice as big as x. The index of value 6 is 1,so we return 1.

*/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        vector<int> v2(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        if(nums[nums.size()-1]>=(nums[nums.size()-2]*2))
        {
            for(int i=0;i<v2.size();i++){
                if(v2[i]==nums[nums.size()-1]){
                    return i;
                }
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> v1;
    v1.push_back(3);
    v1.push_back(6);
    v1.push_back(1);
    v1.push_back(0);
    Solution solve;
    int index;
    index = solve.dominantIndex(v1);
    cout<<index<<endl;
    cout << "Finished!" << endl;
    return 0;
}
