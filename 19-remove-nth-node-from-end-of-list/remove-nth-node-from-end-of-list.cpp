
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int K) {
        if(K==0) return head;
        if(K==1 && head -> next == nullptr) return nullptr;
        int count = 0;
        ListNode* cur = head;
        while(cur!=nullptr){
            count++;
            cur = cur -> next;
        }

        K = count - K;
        ListNode* prev = head;
        cur = head;
        if(K==0) return head -> next;
        do{
            if(K==0){
                prev -> next = cur -> next;
                break;
            }
            prev = cur;
            cur = cur -> next;
        }while(K--);
        return head;        
    }
};