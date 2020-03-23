/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (36.61%)
 * Likes:    921
 * Dislikes: 0
 * Total Accepted:    210.9K
 * Total Submissions: 575.7K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start
typedef struct TrieNode *Position;
struct TrieNode{
    int times;//表示这个节点经历的个数
    map<char, Position> Map{};
    TrieNode(int i) : times(i){};
    TrieNode(){};
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];
        for (int i = 0; i < strs.size(); ++i){
            if(strs[i] == "")
                return "";
            insertKey(&TrieTree, strs[i]);
        }
        string result{""};
        Position p = &TrieTree;
        while(p->Map.size() == 1){
            char ch = (*(p->Map.begin())).first;
            Position p_next = p->Map[ch];
            if(p_next->times != strs.size())
                return result;
            result += string(1, ch);
            p = p_next;
        }
        return result;
    }
private:
    void insertKey(TrieNode* pTree, const string &key){
        for (int i = 0; i < key.size(); ++i){
            auto it = pTree->Map.find(key[i]);
            if(it == pTree->Map.end()){
                Position p = new TrieNode(0);
                pTree->Map.emplace(pair<char, Position>(key[i], p));
            }
            pTree = pTree->Map[key[i]];
            ++pTree->times;
        }
    }

    TrieNode TrieTree{};
};
// @lc code=end

