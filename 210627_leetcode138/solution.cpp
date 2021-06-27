/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        map<Node *, Node *> m;
        Node *newHead = nullptr;
        Node *temp = head;
        Node *temp2;

        while (temp != nullptr)
        {
            if (temp == head)
            {
                newHead = new Node(temp->val);
                temp2 = newHead;
            }
            else
            {
                temp2->next = new Node(temp->val);
                temp2 = temp2->next;
            }
            m.insert(make_pair(temp, temp2));

            temp = temp->next;
        }

        temp = head;
        temp2 = newHead;
        while (temp != nullptr)
        {
            auto i = m.find(temp->random);
            temp2->random = i != m.end() ? i->second : nullptr;

            temp = temp->next;
            temp2 = temp2->next;
        }

        return newHead;
    }
};