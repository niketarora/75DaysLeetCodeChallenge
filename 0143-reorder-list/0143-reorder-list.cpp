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
        //Method - 1 itrative way
        ListNode* prev = NULL;
        ListNode* next = head;
        ListNode* curr = head;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tail = slow->next;
        slow->next = NULL;
        ListNode* a = head;
        ListNode* b = reverseList(tail);
        ListNode* c = new ListNode(0);
        ListNode* ta = a;
        ListNode* tb = b;
        ListNode* tc = c;
        while(ta && tb){
            tc->next = ta;
            tc = tc->next;
            ta = ta->next;
            tc->next = tb;
            tb = tb->next;
            tc = tc->next;
        }
        tc->next = ta;
        head = c->next;
        return;
    }
};