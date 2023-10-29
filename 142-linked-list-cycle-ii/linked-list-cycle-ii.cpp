/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool> m;
        while(head!=nullptr){
            if(m.find(head)!=m.end()) return head;
            else m[head] = true;

            head = head->next;
        }
        return nullptr;        
    }
};