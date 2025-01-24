// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:

//     ListNode* findMiddle(ListNode* head){
//         if(!head || !head->next){
//             return head;
//         }
//         ListNode* fast=head->next, *slow= head;

//         while(!fast && !fast->next){
//             fast=fast->next->next;
//             slow= slow->next;
//         }
//         return slow;
//     }

//     ListNode* Merge(ListNode* leftnode, ListNode* rightnode){
//         ListNode * dummyNode= new ListNode(-1);
//         ListNode *ptr =dummyNode;
//         while(leftnode && rightnode){
//             if(leftnode->val <= rightnode->val){
//                 ptr->next=leftnode;              
//                 leftnode=leftnode->next;
//             }
//             else {
//                 ptr->next=rightnode;
//                 rightnode=rightnode->next;
//             }
//             ptr= ptr->next;
//         }
        
//         if(leftnode){
//             ptr->next=leftnode;
//         }
//         else {
//             ptr->next= rightnode;
//         }

//         return (dummyNode->next);
//     }

//     // ListNode* MergeSort(ListNode* head){
//     //     if(!head || !head->next)return head;
//     //     ListNode* middle= findMiddle(head);
//     //     ListNode *lefthead= head;
//     //     ListNode *righthead = middle->next;
//     //     middle->next=nullptr;
//     //     lefthead=MergeSort(lefthead);
//     //     righthead= MergeSort(righthead);
//     //     return Merge(lefthead, righthead);
//     // }

//     ListNode* sortList(ListNode* head) {
//         if(!head || !head->next)return head;

//         ListNode* middle= findMiddle(head);
//         ListNode *lefthead= head;
//         ListNode *righthead = middle->next;
//         middle->next=nullptr;
//         lefthead=sortList(lefthead);
//         righthead= sortList(righthead);
//         return Merge(lefthead, righthead);

//         return head;
//     }
// };

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
    private:
    // Helper to find the middle of the list
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while(l1 && l2){
            if(l1->val<=l2->val){
                current->next=l1;
                l1=l1->next;
            }else{
                current->next=l2;
                l2=l2->next;
            }
            current=current->next;
        }
        if(l1) current->next=l1;
        if(l2) current->next=l2;
        return dummy->next;

    }
public:
    ListNode* sortList(ListNode* head) {
        /* Bruteforce:-
        Extract all the values from the linked list into a vector/array.
        Sort the vector/array using any efficient sorting algorithm.
        Reconstruct the linked list using the sorted array.*/

        //Optimised using merge sort, first find mid, divide into two halves, sort botht eh halves and then merge 
        if (!head || !head->next) return head;
        ListNode* mid = getMiddle(head);
        ListNode* left= head;
        ListNode* right= mid->next;

        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        // now lets merge
        return merge(left,right);

    }
};