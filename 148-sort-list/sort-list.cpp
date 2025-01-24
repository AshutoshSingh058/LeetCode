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

    ListNode* findMiddle(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* fast=head->next, *slow= head;

        while(fast && fast->next){
            fast=fast->next->next;
            slow= slow->next;
        }
        return slow;
    }

    ListNode* Merge(ListNode* leftnode, ListNode* rightnode){
        ListNode * dummyNode= new ListNode(-1);
        ListNode *ptr =dummyNode;
        while(leftnode && rightnode){
            if(leftnode->val <= rightnode->val){
                dummyNode->next=leftnode;              
                leftnode=leftnode->next;
            }
            else {
                dummyNode->next=rightnode;
                rightnode=rightnode->next;
            }
            dummyNode= dummyNode->next;
        }
        
        if(leftnode){
            dummyNode->next=leftnode;
        }
        else {
            dummyNode->next= rightnode;
        }

        return (ptr->next);
    }

    ListNode* MergeSort(ListNode* head){
        if(!head || !head->next)return head;

        ListNode* middle= findMiddle(head);
        ListNode *lefthead= head;
        ListNode *righthead = middle->next;
        middle->next=nullptr;
        lefthead=MergeSort(lefthead);
        righthead= MergeSort(righthead);
        return Merge(lefthead, righthead);
    }

    ListNode* sortList(ListNode* head) {
        head = MergeSort(head);

        return head;
    }
};