/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
/*
```
*/
#include"all_include"
// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2) return false;
        int half_sum = total / 2;
        vector<vector<bool>> dp;
        dp.resize(nums.size() + 1);
        for (int i = 0; i <= nums.size(); ++i){
            dp[i].resize(half_sum + 1);
            for (int j = 0; j <= half_sum; ++j){
                dp[i][j] = j == 0 ? true : false;
            }
        }

        for (int i = 1; i <= nums.size(); ++i){
            auto num = nums[i - 1];
            for (int j = 1; j <= half_sum; ++j){
                if (j<num)
                    continue;
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num];
            }
        }

        return dp[nums.size()][half_sum];
    }
};
// @lc code=end

/*题解注意点及知识点
 ```
没啥大问题,主要还是dp[i][j]的含义需要搞清楚
这里dp[i][j]就表示用前i个数凑出j是否可能,i从1开始
当j==0时,一律为true表示用任意多个数都可以凑出0这个数(不加就行了)
状态转移方程:dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num];
表示用前i个数凑出j,可以用前i-1个数凑出j或者是用前i-1个数凑出j-num(这里num表示第i个数大小)
还可以继续优化,比如说将双重vector改成bool**,
以及将nums.size()+1 * half_sum+1 的空间节约成1*half_sum+1的空间.
 */