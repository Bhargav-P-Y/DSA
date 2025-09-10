/*
Fast & slow pointers checks 
for cycles, becasue the fast
pointer gains one node per iteration
so after n nodes, if there was a 
cycle they will meet
*/

// Floyds cycle detection algorithm

/*
How to find point of cycle
REset slow to the head & move fast & slow
at same speed
When they yboth point to the same node
that is the node that forms the beginning of the cycle
*/

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head, *slow = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                return true;
        }
        return false;

        
    }
};
