class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val,ListNode* next=nullptr) {
        this->val=val;
        this->next=next;
    }
};

class Solution {
    ListNode* kthNode(ListNode* head, int k) {
        while (head) {
            k--;
            if (k == 0)
                return head;
            head = head->next;
        }
        return nullptr;
    }
    ListNode* reverse(ListNode* head) {
        ListNode *pre = nullptr, *curr = head, *next;
        while (curr) {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *currGrp = head, *currGrpKth = nullptr, *nextGrp = nullptr;

        ListNode *dummy = new ListNode(-1), *res = dummy;

        while (1) {
            currGrpKth = kthNode(currGrp, k);
            if (currGrpKth == nullptr) {
                res->next = currGrp;
                return dummy->next;
            }
            nextGrp = currGrpKth->next;
            currGrpKth->next = nullptr;
            reverse(currGrp);
            res->next = currGrpKth;
            res = currGrp;
            currGrp = nextGrp;
        }
    }
};