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
class Solution
{
private:
    ListNode *merge2Lists(ListNode *a, ListNode *b)
    {
        ListNode *head;
        ListNode *current;
        if (a->val <= b->val)
        {
            head = a;
            a = a->next;
        }
        else
        {
            head = b;
            b = b->next;
        }

        current = head;
        while (a != nullptr && b != nullptr)
        {
            if (a->val <= b->val)
            {
                current->next = a;
                current = a;
                a = a->next;
            }
            else
            {
                current->next = b;
                current = b;
                b = b->next;
            }
        }
        current->next = b == nullptr ? a : b;
        return head;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        queue<ListNode *> q;
        for (ListNode *n : lists)
        {
            if (n == nullptr)
                continue;
            q.push(n);
        }
        while (q.size() >= 2)
        {
            ListNode *a = q.front();
            q.pop();
            ListNode *b = q.front();
            q.pop();
            q.push(merge2Lists(a, b));
        }
        if (q.size() == 0)
            return nullptr;
        return q.front();
    }
};