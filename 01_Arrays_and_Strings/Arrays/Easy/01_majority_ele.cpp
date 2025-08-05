#include<bits/stdc++.h>
class Solution {
public:
    int majorityElement(std::vector<int>& num) {
    int votes=1,majority=num[0];
    for (int i = 1; i < num.size(); i++) {
      if (votes == 0) {
        votes++;
        majority = num[i];
      } else if (majority == num[i]) {
        votes++;
      } else
        votes--;
    }
    return majority;
    }
};


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//        int n = nums.size();
//         unordered_map<int, int> m;
        
//         for(int i = 0; i < n; i++){
//             m[nums[i]]++;
//         }
//         n = n/2;
//         for(auto x: m){
//             if(x.second > n){
//                 return x.first;
//             }
//         }
//         return 0; 
       
//     }
// };

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         return nums[n/2];
//     }
// };