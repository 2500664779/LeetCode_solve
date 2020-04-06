### 题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。


> 直接用系统sort然后前k个(笑,这样肯定不是题要考你的部分),看了看网上的解法,partition算法平均时间复杂度还是O(N),不过前k个数不一定是万全排列好的.
```C++
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k > input.size())return { };
        sort(input.begin(), input.end());
        return vector<int> {input.begin(),input.begin()+k};
    }
};
```