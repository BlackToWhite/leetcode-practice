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
 //by mtf
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = l1;
        ListNode *prev = nullptr;
        while(l1!=nullptr&&l2!=nullptr)
        {
            int num=l1->val+l2->val+carry;
            l1->val = num%10;
            carry = num/10;
            prev = l1;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=nullptr)
        {
            int num = l1->val+carry;
            l1->val = num%10;
            carry = num/10;
            prev = l1;
            l1=l1->next;
        }
        l1=prev;
        while(l2!=nullptr)
        {
            ListNode *temp = new ListNode;
            int num = l2->val + carry;
            temp->val = num%10;
            carry = num/10;
            l1->next=temp;
            l1=l1->next;
            l2=l2->next;
        }
        if(carry)
        {
            l1->next=new ListNode(1);
        }
        return head;
    }
};

//leetcode solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
