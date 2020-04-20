### 题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
#### 输出描述:

> 对应每个测试案例，输出两个数，小的先输出。

```C++
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        unordered_set<int> st;
        for(int i = 0; i < array.size(); ++i){
            if(st.find(array[i]) != st.end()){
                int num1 = array[i] < sum - array[i] ? array[i] : sum - array[i];
                int num2 = array[i] < sum - array[i] ? sum - array[i] : array[i];
                if(res.size() == 0 || res[0] * res[1] > num1 * num2){
                    if(res.size() == 0){
                        res.push_back(num1);
                        res.push_back(num2);
                    }
                    else{
                        res[0] = num1;
                        res[1] = num2;
                    }
                }
            }
            st.emplace(sum - array[i]);
        }
        return res;
    }
};
```