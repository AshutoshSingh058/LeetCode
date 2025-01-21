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
        while(curr!=NULL && curr->next!=NULL){
            N=curr->next;
            curr->next=P;
            P=curr;
            curr=N;
        }
        if(curr!=NULL)curr->next=P;
        return curr;
    }
};