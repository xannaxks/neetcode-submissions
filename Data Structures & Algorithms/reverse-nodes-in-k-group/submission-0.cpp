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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* head_original = head;
        for(;;)
        {
            std::vector<ListNode*> buffer;
            for(int i = 0; i < k; i ++)
            {
                if(head == nullptr)
                    goto end;
                buffer.emplace_back(head);
                head = head->next;
            }
            for(int i = 0, j = buffer.size() - 1; i < j; i ++, j--)
            {
                swap(buffer[i]->val, buffer[j]->val);
            }
        }
        end:;
        return head_original;
    }
};
