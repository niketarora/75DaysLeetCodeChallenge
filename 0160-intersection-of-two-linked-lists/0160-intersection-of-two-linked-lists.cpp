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
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int lenA = 0, lenB = 0;
        while(tempA != NULL){
            lenA++;
            tempA = tempA->next;
        }
        while(tempB != NULL){
            lenB++;
            tempB = tempB->next;
        }
        tempA = headA;
        tempB = headB;
        if(lenA>lenB){
            int n = lenA-lenB;
            for(int i=0; i<n; i++){
                tempA=tempA->next;
            }
        }
        else{
            int n = lenB-lenA;
            for(int i=0; i<n; i++){
                tempB=tempB->next;
            }
        }
        while(tempA != tempB){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
    }
};