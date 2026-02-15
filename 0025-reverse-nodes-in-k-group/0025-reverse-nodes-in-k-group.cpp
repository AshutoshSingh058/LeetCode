class Solution {
public:
    // Reverse a segment from node to end, return new head
    ListNode* reverseGroup(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPrev = dummy;  // tail of already-processed part

        while (true) {
            // Step 1: Check if k nodes remain
            ListNode* kth = getKth(groupPrev, k);
            if (!kth) break;

            ListNode* groupNext = kth->next;  // node after this group
            ListNode* groupStart = groupPrev->next;

            // Step 2: Isolate and reverse the group
            kth->next = nullptr;
            groupPrev->next = reverseGroup(groupStart);

            // Step 3: Reconnect — groupStart is now the tail after reversal
            groupStart->next = groupNext;

            // Step 4: Move groupPrev to end of reversed group (= groupStart)
            groupPrev = groupStart;
        }

        return dummy->next;
    }

private:
    // Walk k steps from node, return that node or nullptr if not enough
    ListNode* getKth(ListNode* node, int k) {
        while (node && k--) node = node->next;
        return node;
    }
};
