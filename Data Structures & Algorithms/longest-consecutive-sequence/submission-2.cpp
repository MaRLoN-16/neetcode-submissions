#include <algorithm>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        if(nums.empty()) return 0;
        int mejor = 1;
        int a = 1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i-1] + 1 == nums[i]){
                a++;
                if(a > mejor) mejor = a;
            } 
            else if(nums[i-1] != nums[i])a = 1;
        }
        return mejor;
    }
};
