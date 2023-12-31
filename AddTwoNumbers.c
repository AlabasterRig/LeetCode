struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* currNode = head;

    while(l1 != NULL || l2 != NULL || carry != 0)
    {
        int x, y;
        if(l1 != NULL)
        {
            x = l1->val;
        }
        else{
            x = 0;
        }

        if(l2 != NULL)
        {
            y = l2->val;
        }
        else{
            y = 0;
        }

        int sum = x + y + carry;
        carry = sum/10;
        sum = sum % 10;
        
        struct ListNode* newNode= (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum;
        newNode->next = NULL;

        currNode->next = newNode;
        currNode = currNode->next;

        if(l1 != NULL)
        {
            l1 = l1->next;
        }

        if(l2 != NULL)
        {
            l2 = l2->next;
        }
    }
    return head->next;

}