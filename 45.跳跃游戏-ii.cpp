/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        return dp(nums);
    }
private:
    int dp(vector<int>& nums){
        vector<int> Vdp{};
        Vdp.push_back(0);
        for (int i = nums.size() - 2; i >= 0; --i){
            int singleStep = nums[i];
            int minTimes = INT_MAX;
            for (int j = 1; j <= singleStep; ++j){
                if (i + j > nums.size() - 1)
                    continue;
                minTimes = min(minTimes, int(nums.size() - 1 - i - j));
            }
            Vdp.push_back(minTimes + 1);
        }
        return Vdp.back();
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> test{2, 3, 1, 1, 4};
    cout << sol.jump(test);
    getchar();
    getchar();
}