/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (60.46%)
 * Likes:    900
 * Dislikes: 0
 * Total Accepted:    208.7K
 * Total Submissions: 345.2K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2)
            return l1 ? l1 : l2;
        ListNode *preHead = (ListNode *)new ListNode(0);
        ListNode *pNewEnd = preHead;
        while (l1 && l2){
            if(l1->val <= l2->val){
                ListNode * nextNode = l1->next;
                insertNodeAfter(pNewEnd, l1);
                l1 = nextNode;
            }else{
                ListNode * nextNode = l2->next;
                insertNodeAfter(pNewEnd, l2);
                l2 = nextNode;
            }
            pNewEnd = pNewEnd -> next;
        }
        pNewEnd->next = (l1 == NULL ? l2 : l1);
        return preHead->next;
    }
private:
void insertNodeAfter(ListNode * where, ListNode * Node){
    Node->next = where->next;
    where->next = Node;
}
};
// @lc code=end

