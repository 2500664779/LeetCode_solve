/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        total_water = 0;
        for (int i = 0; i < height.size(); ++i){
            sum_of_hill = 0;
            last_pop = -1;
            /*如果栈空,或者栈顶指向的元素比当前操作数指向的元素大,则直接压栈并不进行任何操作*/
            if (stk.empty() || height[stk.top()] > height[i]){
                stk.push(i);
                continue;
            }

            /*这里显然是栈不空,并且栈顶指向的元素<=当前操作数指向的元素*/
            /*则需要进行弹出操作,弹出操作一定涉及到雨水计算*/
            /*需要弹出到栈空或者栈顶指向元素>当前操作数指向元素*/
            while (!stk.empty() && height[stk.top()] <= height[i]){
                sum_of_hill += height[stk.top()];
                last_pop = stk.top();
                stk.pop();
            }

            /*如果弹出到栈空,则说明用最后一个弹出的操作数进行操作,同时需要注意把多加上的hill减掉*/
            /*此时所有弹出的操作数指向元素肯定是比当前操作数指向元素小*/
            if (stk.empty()){
                cur_water = (i - last_pop) * height[last_pop] - sum_of_hill;
                total_water += cur_water;
            }
            else{
                cur_water = height[i] * (i - stk.top() - 1) - sum_of_hill;
                total_water += cur_water;
            }
        }
        /*for循环结束之后不用判断栈中是否有元素,因为最小栈(栈低->顶 = 大->小)就保证了最后非空的时候*/
        /*这些元素一定是连在一起的非零顶,而且是递减的*/
        return total_water;
    }
private:
    int last_pop;
    int sum_of_hill;
    int cur_water;
    int total_water;
    stack<int> stk;
};
// @lc code=end

