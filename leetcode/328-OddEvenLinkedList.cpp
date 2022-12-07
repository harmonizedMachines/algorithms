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
        ListNode* oddhead = NULL, *evenhead = NULL, *curr = head, *even = NULL, *odd = NULL;
        int cnt = 0;
        while (curr){
            if (cnt % 2 == 0){
                if (!oddhead){
                    odd = curr;
                    oddhead = curr;
                } else {
                    odd->next = curr;
                    if (odd->next){
                        odd = odd->next;
                    }
                }
            } else {
                if (!even){
                    evenhead = curr;
                    even = curr;
                } else {
                    even->next = curr;
                    if (even->next){
                        even = even->next;
                    }
                }
            }
            ++cnt;
            curr = curr->next;
        }
        if (even){
            even->next = NULL;
        }
        if (odd){
            odd->next = evenhead;
        }
        return oddhead;
    }
};