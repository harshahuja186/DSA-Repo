
class Solution {
    private:

  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(ListNode *head)
    {
        int count = 0;
        ListNode* temp = head;
        while(temp!=nullptr){
            temp=temp->next;
            count++;
        }

        int i = 0;
        temp = head;
        stack<int> st;
        while(i!=count/2){
            st.push(temp->val);
            temp=temp->next;
            i++;
        }

        if(count%2==1) temp = temp -> next;

        while(temp!=nullptr){
            if(temp->val!=st.top()) return false;
            st.pop();
            temp = temp -> next;
        }
        return true;
    }
};
