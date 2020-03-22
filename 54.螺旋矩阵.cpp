/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (39.16%)
 * Likes:    322
 * Dislikes: 0
 * Total Accepted:    47.2K
 * Total Submissions: 120.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return vector<int>{};
        vector<int> result{};
        printCirclely(matrix, result, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
        return result;
    }
private:
    void printCirclely(vector<vector<int>>& matrix, vector<int>& toOut,
                       int lR, int lC, int rR, int rC)
    {
        if(lR > rR || lC > rC)
            return;
        if(lR == rR){
            while(lC <= rC)
                toOut.push_back(matrix[lR][lC++]);
            return;
        }else
        if(lC == rC){
            while(lR <= rR)
                toOut.push_back(matrix[lR++][lC]);
            return;
        }
        int i = lR, j = lC;
        while(j < rC){
            toOut.push_back(matrix[i][j++]);
        }
        while(i < rR){
            toOut.push_back(matrix[i++][j]);
        }
        while (j > lC){
            toOut.push_back(matrix[i][j--]);
        }
        while(i > lR){
            toOut.push_back(matrix[i--][j]);
        }
        printCirclely(matrix, toOut, lR + 1, lC + 1, rR - 1, rC - 1);
    }
};
// @lc code=end

