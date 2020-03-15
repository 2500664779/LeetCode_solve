### 题目描述
输入一个链表，输出该链表中倒数第k个结点。

> **思路：** 主要是考虑一下边界条件，以及非法输入。

```C++
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(!pListHead || !k)
            return NULL;
        ListNode *slow = pListHead, *fast = pListHead;
        
        for (int i = 0; i < k; ++i){
            if(!fast)
                return NULL;
            fast = fast->next;
        }
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
```