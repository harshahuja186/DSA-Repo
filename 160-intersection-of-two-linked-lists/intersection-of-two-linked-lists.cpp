
class Solution {
public:

    ListNode* getIntersectionNode(ListNode *firstHead, ListNode *secondHead)
    {
        auto getLength = [](ListNode* head){
            int length = 0;
            while(head != nullptr){
                head = head -> next;
                length++;
            }
            return length;
        };

        int length1 = getLength(firstHead);
        int length2 = getLength(secondHead);

        while(length1>length2){
            firstHead=firstHead->next;
            length1--;
        }
        while(length2>length1){
            secondHead=secondHead->next;
            length2--;
        }
        
        while(firstHead!=secondHead){
            firstHead=firstHead->next;
            secondHead=secondHead->next;
        }
        return firstHead;
    }

};