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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode*temp = head;

       while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        // attach the remainder
        if (l1) temp->next = l1;
        else temp->next = l2;

        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        ListNode* head = lists[0];
        for(int i=1; i<lists.size(); i++){
            head = merge2Lists(head, lists[i]);
        }

        return head;
    }
};