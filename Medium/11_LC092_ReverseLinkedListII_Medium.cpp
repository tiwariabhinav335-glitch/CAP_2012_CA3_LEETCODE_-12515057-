// LeetCode provides the ListNode definition.
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* before = &dummy;

        for (int i = 1; i < left; i++) {
            before = before->next;
        }

        ListNode* current = before->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* nextNode = current->next;
            current->next = nextNode->next;
            nextNode->next = before->next;
            before->next = nextNode;
        }

        return dummy.next;
    }
};
