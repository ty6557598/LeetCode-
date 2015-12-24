/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public://合并排序后的单链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;//可以包容所有的链表为空的情况了
        if(l2==NULL) return l1;
        ListNode *p = l1; ListNode *q = l2;
        ListNode*head = new ListNode(-1);//此处要注意这种生成节点的方式，运用了类构造函数的思想
        ListNode *cur = head;//此处不能以head后移的，这样将无法返回指针。需要再指定一个指针用来移动
        while(p!=NULL && q!=NULL){
            if(p->val<=q->val){
                cur->next = p;
                p = p->next;
                cur = cur->next;
                }
            else {
                cur->next = q;
                q = q->next;
                cur = cur->next;
                }
             }
        if(p==NULL) cur->next = q;
        if(q==NULL) cur->next = p;
        return head->next;
    }
};
