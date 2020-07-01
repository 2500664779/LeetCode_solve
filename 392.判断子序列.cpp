/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */
/*
 ```C++
 */
#include"all_include"
// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = -1;
        for (auto c : s){
            size_t next_find = t.substr(index + 1).find_first_of(c);
            if (next_find == string::npos)
                return false;
            index = next_find + index + 1;
        }
        return true;
    }
};
// @lc code=end

/*题解注意点及知识点
 ```
 采用贪心算法,遍历s中的char
 对于每一个char,从t中上一个找到的char的位置之后找当前char
 如果没找到则表示不是子序列
 如果对于s中每一个char都找得到的话,则表示,能够子序列匹配.
 */