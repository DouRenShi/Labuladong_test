/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //反转链表的m到n个节点,返回头节点，递归实现
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr || head->next == nullptr) return head;

        //base case
        if(m == 1){
            return reverseN(head,n-m+1);//反转前n-m+1个节点
        }
        //以head->next为起点，反转m-1到n-1之间的节点
        head->next =  reverseBetween(head->next,m-1,n-1);
        return head;
    }
    
    ListNode* successor = nullptr;//后驱节点
    //反转链表的前n个节点，返回链表的头节点，递归实现
    ListNode* reverseN(ListNode* head, int n){
        if(head == nullptr || head->next == nullptr) return head;
        //base case
        if(n == 1){
            //记录第n+1个节点到successor
            successor = head->next;
            return head;
        }
        //以head->next为起点，反转前n-1个节点
        ListNode* last = reverseN(head->next,n-1);
        head->next->next = head;
        //让反转之后的head节点和后面的节点连接起来
        head->next = successor;
        return last;
    }
};