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
    std::optional<std::stack<ListNode*>> get_segment(ListNode*& current, ListNode*& first, int sz)
    {
        std::stack<ListNode*> result;

        while (sz--)
        {
            if (current == nullptr)
                return std::nullopt;

            if (result.empty())
                first = current;

            result.push(current);

            current = current->next;
        }

        return result;
    }

    void reverse_segment(
        std::stack<ListNode*>& segment,
        ListNode*& prev,
        ListNode*& current,
        ListNode*& prev_segment_last,
        ListNode*& current_segment_last
    )
    {
        while (!segment.empty())
        {
            prev = current;
            current = segment.top();

            segment.pop();

            if (prev && current)
                prev->next = current;
            else
            {
                if (prev_segment_last)
                    prev_segment_last->next = current;
            }

            current_segment_last = current;
        }
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev_segment_last = nullptr;
        ListNode* current_segment_last = nullptr;
        ListNode* prev = nullptr;
        ListNode* current = nullptr;
        ListNode* first = nullptr;
		 ListNode*  original_head = head;

        ListNode* result = nullptr;

        std::stack<ListNode*> segment;

        while (head)
        {
            std::optional<std::stack<ListNode*>> get_segment_result = get_segment(head, first, k);

            if (get_segment_result == std::nullopt)
            {
                if(prev_segment_last)
                    prev_segment_last->next = first;
                else
                    return original_head;
                break;
            }

            segment = std::move(*get_segment_result);

            if (!prev_segment_last) 
                result = segment.top();
            

            current = nullptr;
            prev = nullptr;
            current_segment_last = nullptr;

            reverse_segment(segment, prev, current, prev_segment_last, current_segment_last);

            prev_segment_last = current_segment_last;
            prev_segment_last->next = nullptr;
        }

        return result;
    }
};