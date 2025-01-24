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
    

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0, n=0;
        ListNode* dnode = new ListNode(-1);
        ListNode* temp = dnode;
        while(l1 && l2){
            n=(l1->val)+ (l2->val)+ carry;
            carry= n/10;
            n=n%10;
            ListNode * newNode= new ListNode(n);
            temp->next=newNode;
            temp= temp->next;
            l1=l1->next; l2=l2->next;

        }
        while(l1){
            n=(l1->val)+ carry;
            carry= n/10;
            n=n%10;
            ListNode * newNode= new ListNode(n);
            temp->next=newNode;
            temp= temp->next;
            l1=l1->next;
        }
        while(l2){
            n=(l2->val)+ carry;
            carry= n/10;
            n=n%10;
            ListNode * newNode= new ListNode(n);
            temp->next=newNode;
            temp= temp->next;
            l2=l2->next;
        }

        if(carry!=0){
            ListNode * newNode= new ListNode(carry);
            temp->next=newNode;
        }

        

        return (dnode->next);
    }
};