/*
Create an offset between 
first & second pointers
*/
//Dummy helps handle cases where
//we need to remove the first node in the list

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy, *second = dummy;

        for(int i = 0;i<n;i++)
            first = first->next;
      
        while(first->next)
        {
            first = first->next;
            second = second->next;
        }
        //Second is just behind the node to
        //be deleted

        second->next = second->next->next;
        return dummy->next;
        
    }
};
