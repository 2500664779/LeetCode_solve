### 题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。

多创建一个栈,用来保存栈中的最小值.仍然需要保持一个后入先出的顺序.

```C++
class Solution {
public:
    void push(int value) {
        if(minStack.empty() || value < minStack.top())
            minStack.push(value);
        else
            minStack.push(minStack.top());
        dataStack.push(value);
    }
    void pop() {
        dataStack.pop();
        minStack.pop();
    }
    int top() {
        return dataStack.top();
    }
    int min() {
        return minStack.top();
    }
private:
    stack<int> dataStack;
    stack<int> minStack;
};
```