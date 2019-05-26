#include<iostream>
#include<vector>
using namespace std;
/*
LeetCode 724 Find Pivot Index
Inputs: [1,7,3,6,5,6]
Outputs: 3
Explanations: The sum of the number to the left of index 2(nums[3]=6) is equal to
the sum of numbers to the right of index 3.Alse, 3 is the first index where this occurs.
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==0){
            return -1;
        }
        int left_sum=0;
        int right_sum,total_sum=0;
        for(auto i=0;i <nums.size();i++){
            total_sum += nums[i];
        }
        for(int i=0;i<nums.size();i++){
            right_sum = total_sum-nums[i]-left_sum;
            if(left_sum==right_sum){
                return i;
            }
            else{
                left_sum = left_sum+nums[i];
            }
        }
        return -1;

    }
};

int main(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(7);
    v1.push_back(3);
    v1.push_back(6);
    v1.push_back(5);
    v1.push_back(6);
    int index;
    Solution solve;
    index = solve.pivotIndex(v1);
    cout<<index;
    cout<<"Finished!"<<endl;
    return 0;
}
