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
 //思路：
//  可见本函数有递归性质，可以拆分为子问题；
//  可以先反转前K个节点，后递归调用本函数，其中头节点为第K+1个节点，然后把他们连接起来；
//  需要完成的函数：
//  反转前K个节点；
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next==nullptr) return head;
        
        //base case如果节点不满k个，则不反转
        ListNode* a,*b;//ab是为了划定区间
        a = head; b = head;
        for(int i=0; i<k; i++){
            if(b==nullptr)
                return a;
            b=b->next;
        }//一个循环下来，b已经指向了第k+1个节点

        //反转 [a,b) 之间的节点
        ListNode* newhead = reverse(a,b);
        //子问题划分(递归调用)
        a->next = reverseKGroup(b,k);

        return newhead;
    }
    //子函数：反转[a,b)之间的节点(迭代实现)
    ListNode* reverse(ListNode* a,ListNode* b){
        //迭代实现
        if(a == nullptr) return a;
        ListNode* pre,*cur,*nex;
        pre = nullptr;cur = nex = a;
        while(cur!=b){
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};