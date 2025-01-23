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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head ,* P=NULL, *N=NULL;
        while(curr ){
            N=curr->next;
            curr->next=P;
            P=curr;
            curr=N;
        }
        // if(curr!=NULL)curr->next=P;
        return P;
    }

    // ListNode* reverseList(ListNode* head) {
        
    //     if(head==NULL || head->next==NULL) return head;

    //     ListNode* newHead= reverseList(head->next);

    //     ListNode* front= head->next;
    //     front->next= head;
    //     head->next=NULL;

    //     return newHead;
    // }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next)return nullptr;

        head = reverseList(head);
        ListNode* temp = head;
        if(n==1){
            return reverseList(head->next);
        }
        while(n--){
            if(n==1)temp->next=temp->next->next;
            if(temp)temp=temp->next;
        }
        
        head = reverseList(head);

        return head;
    }
};