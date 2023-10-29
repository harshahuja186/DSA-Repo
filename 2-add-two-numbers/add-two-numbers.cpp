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
    ListNode *addTwoNumbers(ListNode *num1, ListNode *num2)
    {
        // Write your code here. val
        int carry = 0;
        ListNode* num1_clone = num1;
        ListNode* prev1 = nullptr;
        ListNode* prev2 = nullptr;
        while(num1_clone && num2){
            int sum = num1_clone -> val + num2 -> val + carry;
            carry = sum / 10;
            int remainder = sum % 10;

            num1_clone -> val = remainder;
            prev1 = num1_clone;
            num1_clone = num1_clone -> next;
            prev2 = num2;
            num2 = num2 -> next;
        }

        while(num1_clone != nullptr){
            int sum = num1_clone -> val + carry;
            carry = sum / 10;
            int remainder = sum % 10;

            num1_clone->val = remainder;
            prev1 = num1_clone;
            num1_clone = num1_clone -> next;
        }

        bool flag = false;
        if(num2){ prev1 -> next = num2; flag = true;}

        while(num2){
            int sum = num2 -> val + carry;
            carry = sum / 10;
            int remainder = sum % 10;

            num2 -> val = remainder;
            // num1_clone -> next = num2;
            prev2 = num2;
            num2 = num2 -> next;
        }

        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            if(flag == true) prev2 -> next = newNode;
            else prev1->next = newNode;
        }
        return num1;
    }
};
