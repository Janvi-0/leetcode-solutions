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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int pos = 1;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;
        int maxDist = -1;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr != nullptr && curr->next != nullptr) {
            ListNode* next = curr->next;
            bool isCritical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);

            if (isCritical) {
                if (first == -1) {
                    first = pos;
                } else {
                    minDist = min(minDist, pos - last);
                    maxDist = pos - first;
                }
                last = pos;
            }
            prev = curr;
            curr = next;
            pos++;
        }
        if (minDist == INT_MAX) {
            return {-1, -1};
        }
        return {minDist, maxDist};
    }
};