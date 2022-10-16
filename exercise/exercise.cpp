#include <string>
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> Fmax(nums), Fmin(nums);
        int ans = *nums.begin();
        for (int i = 1; i < nums.size(); i++)
        {
            Fmax[i] = max(nums[i], max(Fmax[i - 1] * nums[i], Fmin[i - 1] * nums[i]));
            Fmin[i] = min(nums[i], min(Fmax[i - 1] * nums[i], Fmin[i - 1] * nums[i]));
            ans = max(Fmax[i], ans);
        }
        return ans;
    }
};