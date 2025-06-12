struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // dummy list node so we can later access the head of the list more easily
        ListNode* dummy = new ListNode();
        ListNode* list = dummy;
        bool flag = false;

        // while neither list is empty
        while (list1 != nullptr || list2 != nullptr) {
            
            // check for any cases inolving empty lists. if list 1 is empty then the result list must point to list 2's value.
            // likewise, if list 2 is empty then the result list must point to list 1's value.
            if (list1 == nullptr) {
                list -> next = new ListNode(list2 -> val);

                // move to the next list node
                list2 = list2 -> next;
                list = list -> next;
            } else if (list2 == nullptr) {
                list -> next = new ListNode(list1 -> val);

                // move to the next list node
                list1 = list1 -> next;
                list = list -> next;
            }

            // if both lists are not empty and list 1's value is less than list 2's value
            if (list1 != nullptr && list2 != nullptr && list1 -> val < list2 -> val) {
                list -> next = new ListNode(list1 -> val); // set the resulting list value to that of list 1
                list1 = list1 -> next;
                list = list -> next;

            // if both lists are not empty and list 1's value is greater than list 2's value
            } else if (list1 != nullptr && list2 != nullptr && list1 -> val > list2 -> val) {
                list -> next = new ListNode(list2 -> val); // set the resulting list value to that of list 2
                list2 = list2 -> next;
                list = list -> next;

            // if both lists are not empty and list 1's value is equal to list 2's value
            } else if (list1 != nullptr && list2 != nullptr && list1 -> val == list2 -> val) {
                list -> next = new ListNode(list1 -> val); // set the resulting list value to that of list 1
                ListNode* nlist = list -> next; // create a new node which is pointed at by the previous list node
                nlist -> next = new ListNode(list2 -> val); // set the resulting list value to that of list 2
                list1 = list1 -> next;
                list2 = list2 -> next;
                list = nlist -> next;
            }  
          


        }
        return dummy -> next; // return the head of the list
    }
};