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

class Solution {
    void printLL(Node* node)
    {
        cout<< "\n";
        while(node)
        {
            cout<<node->val<< "\t";
            node = node->next;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node* lHead = nullptr;
        Node* lite = nullptr;
        Node* ite = head;
        unordered_map<Node*, Node*> lOldVsNew;
        while(ite)
        {
            Node* lNode = new Node(ite->val);
            if(!lHead)
            {
                lHead = lNode;
                lite = lNode;
            }
            else
            {
                lite->next = lNode;
                lite = lite->next;
            }
            lOldVsNew[ite] = lNode;
            ite = ite->next;
        }
        ite = head;
        Node* ite2 = lHead;
        while(ite)
        {
            ite2->random = lOldVsNew[ite->random];
            ite = ite->next;
            ite2 = ite2->next;
        }
        //cout<<size;
        return lHead;
    }
};
