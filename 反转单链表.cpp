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
//输入链表头节点，将链表反转，返回新的头节点（递归实现）
    ListNode* reverseList(ListNode* head) {
        //1:截止条件
        if(head == nullptr || head->next == nullptr)return head;
        //2:子任务
        ListNode *last = reverseList(head->next);
        //3:递归结束，收尾工作
        head->next->next = head;
        head->next = nullptr;
        //4:返回头节点
        return last;
    }
};