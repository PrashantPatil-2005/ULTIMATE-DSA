#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map <int ,int > mp;
      for(int i=0;i<nums.size();i++){
        int temp=target-nums[i];
        if(mp.count(temp)){
            return {mp[temp],i};
        }
        mp[nums[i]]=i;
      }
        return {-1,-1}; 
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//       int n=nums.size();
//       for(int i=0;i<n;i++){
//         int temp=target-nums[i];
//         for(int j=i+1;j<n;j++){
//         if(nums[j]==temp) return {i,j};
//         }
//       }
//         return {}; 
//     }
// };//O(n^2)