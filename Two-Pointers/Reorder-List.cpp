//Step 1: Find the middle node using fast & slow pointers
//Step 2: Disconnect the right half the linked list
//Step 3: Reverse the right half
//Step 4: Keep alternating nodes between the left & right parts
//Step 5: Repeat Step 4 until right part is exhausted

class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr, *next = nullptr, *cur = head;

        while(cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {

        ListNode* res = head, *tail = head;

        ListNode* slow = findMiddle(head);
        ListNode* cur = slow->next;
        

        //Disconnect left & right
        slow->next = nullptr;

        ListNode* rev = reverse(cur);

        while(rev)
        {
            ListNode* lnxt = tail->next;
            ListNode* rnxt = rev->next;
            tail->next = rev;
            rev->next = lnxt;

            tail = lnxt;
            rev = rnxt;
        }
    }
};
