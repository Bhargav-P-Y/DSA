//WHat's the base case?
//What are you supposed to do at every stage

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      
      if(!head) return head;

      newHead = head;

      if(head->next)
      {
        newHead = reverseList(head->next);
        //Essentially the next's node next pointer is reversed
        head->next->next = head;
        head->next = nullptr; 
      }
      return newHead;  
    }
};
/*
Recursive Flow Breakdown
Let’s say your list is: 1 → 2 → 3 → 4 → nullptr

Now walk through the recursion:

Initial call: reverseList(1)

head = 1

newHead = 1 (temporary)

Calls reverseList(2)

Second call: reverseList(2)

head = 2

newHead = 2 (temporary)

Calls reverseList(3)

Third call: reverseList(3)

head = 3

newHead = 3 (temporary)

Calls reverseList(4)

Fourth call: reverseList(4)

head = 4

newHead = 4 (temporary)

head->next == nullptr, so recursion ends here

Returns newHead = 4

🔄 Backtracking Phase (Where Reversal Happens)
Now we go back up the call stack:

In the third call (head = 3):

newHead = reverseList(4) → newHead = 4

head->next->next = head → 4->next = 3

head->next = nullptr → 3->next = nullptr

Returns newHead = 4

In the second call (head = 2):

newHead = reverseList(3) → newHead = 4

3->next = 2, 2->next = nullptr

Returns newHead = 4

In the first call (head = 1):

newHead = reverseList(2) → newHead = 4

2->next = 1, 1->next = nullptr

Returns newHead = 4

*/
