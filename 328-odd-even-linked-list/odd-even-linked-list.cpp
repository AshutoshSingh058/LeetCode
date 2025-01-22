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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return head;
        ListNode* odd=head, *even = head->next, *temp= even;
        head=odd;
        while(even && even->next){
            if(odd->next)odd->next=odd->next->next;
            if(even->next)even->next=even->next->next;
            odd= odd->next;
            even= even->next;
            
        }

        odd->next=temp;
        return head;

    }
};