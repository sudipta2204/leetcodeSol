/*
 * Problem #18: 4Sum
 * Difficulty: Medium
 *
 * ----- Description -----
 *
 * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 * 
 * 
 * 	0 <= a, b, c, d < n
 * 	a, b, c, and d are distinct.
 * 	nums[a] + nums[b] + nums[c] + nums[d] == target
 * 
 * 
 * You may return the answer in any order.
 * 
 *  
 * Example 1:
 * 
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * 
 * Example 2:
 * 
 * Input: nums = [2,2,2,2,2], target = 8
 * Output: [[2,2,2,2]]
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= nums.length <= 200
 * 	-109 <= nums[i] <= 109
 * 	-109 <= target <= 109
 *
 * ----- Solution -----
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size();){
                int p=j+1;
                int q= nums.size()-1;
                while(p<q){
                    long long sum= 1LL* nums[i]+nums[j]+nums[p]+nums[q];
                    if(sum>target){
                        q--;
                    }else if(sum<target){
                        p++;
                    }else{
                        ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                        p++;
                        q--;
                    while(p<q && nums[p]==nums[p-1]){
                        p++;
                    }
                    while(p<q && nums[q]==nums[q+1]){
                        q--;
                    }
                    }
                }
                j++;
                while(j<nums.size() && nums[j]==nums[j-1]){
                j++;
                }
            }
        }
        return ans;
    }
};