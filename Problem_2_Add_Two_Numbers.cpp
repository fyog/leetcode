
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // dummy list node so we can later access the head of the list more easily
        ListNode* dummy = new ListNode();
        ListNode* list = dummy;
        bool carry = false;
        int sum;

        // while neither list is empty
        while (l1 != nullptr || l2 != nullptr) {

            // if both lists are not empty
            if (l1 != nullptr && l2 != nullptr) {
                
                // if there was a carry value left over from a previous iteration
                if (carry) {
                    sum = l1 -> val + l2 -> val + 1; // sum the two list node values together, plus 1 for the carry value
                    carry = 0; // reset the carry value
                } else { 
                    sum = l1 -> val + l2 -> val; // sum the list node values together
                }
                if (sum > 9) carry = true; // if the sum is greater than 9, increment the carry value
            
            // if list 2 is empty
            } else if (l1 != nullptr && l2 == nullptr) {
                
                // if there was a carry value left over from a previous iteration
                if (carry) {
                    sum = l1 -> val + 1; // the sum is the value of the list 1 node, plus 1 for the carry value
                    carry = false; 
                } else {
                    sum = l1 -> val; // the sum is the value of the list 1 node
                }
                if (sum > 9) carry = true; // if the sum is greater than 9, increment the carry value
            } else {
                if (carry) {
                    sum = l2 -> val + 1; // the sum is the value of the list 1 node, plus 1 for the carry value
                    carry = false;
                } else {
                sum = l2 -> val; // the sum is the value of the list 1 node
                }
                if (sum > 9) carry = true; // if the sum is greater than 9, increment the carry value         
            }

            // move to the next node in the list
            list -> next = new ListNode(sum % 10); // mod 10 the sum when creating the next node (digits can only range from 0 to 9)
            list = list -> next; 
            if (l1 != nullptr) l1 = l1 -> next;
            if (l2 != nullptr) l2 = l2 -> next;
        }

        // if, in the case that the sum of the final digits of both lists results in a carry value, then
        // a final list node with the value of 1 needs to be attached to the list
        if (carry > 0) {
            list -> next = new ListNode(1);
        }
    
        return dummy -> next; // return the head of the list
    }
};