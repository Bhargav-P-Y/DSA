//This can be used
//to sort an unsorted
//linked list

//FInd the middle node
//Recursively sort left and right
//Merge the sorted parts

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //Hnadle the cases when one or both the lists are empty
        if(!list1) return list2;
        if(!list2) return list1;

        //Dummy node
        //Simplifies constructing the merged list

        ListNode* dummy = new ListNode();

        //Clearer variable names
        ListNode* tail = dummy;
        ListNode* l1 = list1, *l2 = list2;

        while(l1 && l2)
        {
            //Always insert the 
            //smaller node between the two
            if(l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        //If there are nodes
        //still remaining
        if(l1)
            tail->next = l1;
        else if(l2)
            tail->next = l2;

        return dummy->next;
    
        
    }
};
