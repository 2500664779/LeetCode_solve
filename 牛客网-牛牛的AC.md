题目描述
一年一度的春招就要到来了，牛牛为了备战春招，在家刷了很多道题，所以牛牛非常喜欢AC这两个字母。他现在有一个只包含A和C的字符串，你可以任意修改最多k个字符，让A变成C，或者C变成A。请问修改完之后，最长连续相同字符的长度是多少。
示例1
输入

    1,"AAAC"
输出

    4
说明

    样例一：将最后一位C改成A即可。
备注:

    字符串长度<=10^6，且只包含'A'和'C'，k<=10^6。

** 滑动窗口法 **
```C++
class Solution {
public:
    /**
     * 
     * @param k int整型 
     * @param s string字符串 
     * @return int整型
     */
    int Solve(int k, string s) {
        //先把边界判断了
        if(k >= (s.size()>>1))
            return s.size();

        int Left = 0, Right = 0;
        int res = 1;
        int numberOfA = 0, numberOfC = 0;
        int windowSize = 0;
        //先窗口把A包进去
        while(Right < s.size()){
            if(s[Right] == 'A') numberOfA++;
            if(numberOfA > k){
                while(s[Left] != 'A') ++Left;
                ++Left;
                numberOfA--;
            }
            windowSize = Right - Left + 1;
            res = windowSize > res ? windowSize : res;
            Right++;
        }
        Left = Right = windowSize = numberOfC = 0;
         while(Right < s.size()){
            if(s[Right] == 'C') numberOfC++;
            if(numberOfC > k){
                while(s[Left] != 'C') ++Left;
                ++Left;
                numberOfC--;
            }
            windowSize = Right - Left + 1;
            res = windowSize > res ? windowSize : res;
            Right++;
        }

        return res;
    }
};
```

** 动态规划法 **