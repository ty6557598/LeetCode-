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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return NULL;//链表如果确实为空的话可以返回NULL，其他vector之类的统统都不行
        ListNode *p = head;
        unsigned int size = 0,temp=0,i=2;
       while(p!=NULL){//这样写可以指向最后一个链表，如果是p->next!=NULL,只能指向倒数第二个链表单元
           p = p->next;
           size++;
       }
       p = head;
       temp = size - n +1;//temp这个值还是比较小的，没有可能超出的
       if(temp==1) {head = head->next; return head;}//这些地方真的是要很小心才行啊
       else if(temp>1 && temp<=size){
        while(p!=NULL && i<temp){
            p = p->next;
            i++;
            }
           p->next = p->next->next;
         return head;  //然后就是此处需要考虑p与p->next的区别，p->next为本节点的下一个节点是某节点；p为p指针指向下下个节点，此处完全错误
           }
       }
};
