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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backSeek(candidates, target, candidates.size() - 1);
        return res;
    }
private:
    vector<vector<int>> res{};
    vector<int> tmp{};

    void backSeek(vector<int> & candidates, int target, int pos){
        
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        if (candidates[pos] > target)
            return;
        tmp.push_back(candidates[pos]);
        for (int i = pos; i >= 0; --i){
            backSeek(candidates, target - candidates[i], i);
        }
        tmp.pop_back();
    }
};

// @lc code=end

int main(){
    Solution sol;
    vector<int> ve{2, 3, 6, 7};

    auto x = sol.combinationSum(ve, 7);
}