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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        int groupSize = 1;
        while (head) {
            ListNode* start = head;
            int count = 0;
            while (count < groupSize && head) {
                head = head->next;
                count++;
            }
            if (count % 2 == 0) {
                ListNode* curr = start;
                ListNode* next = head;
                ListNode* rev = next;
                for (int i = 0; i < count; i++) {
                    ListNode* tmp = curr->next;
                    curr->next = rev;
                    rev = curr;
                    curr = tmp;
                }
                prev->next = rev;
                prev = start;
            } else {
                for (int i = 0; i < count; i++) {
                    prev = prev->next;
                }
            }
            groupSize++;
        }
        return dummy.next;
    }
};
