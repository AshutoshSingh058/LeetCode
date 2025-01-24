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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // int intersectVal=0;
        // cin>>intersectVal;
        // int skipA=0, skipB=0;
        // cin>>skipA;
        // cin>>skipB;
        
        ListNode* t1=headA, *t2= headB;
        
        // while(skipA && t1)t1=t1->next;
        // while(skipB && t2)t2=t2->next;

        bool flag=true, check= true;
        while(t1 && t2 && t1!=t2){
            t1=t1->next;
            t2=t2->next;
            if(t1==nullptr && flag){t1=headB; flag=false;}
            if(t2==nullptr && check){t2= headA; check= false;}
        }
        // if(t1)cout<<t1->val<<endl;
        // if(t2)cout<<t2->val<<endl;
        if(t1==t2)return t1;
        else return nullptr;
    }
};