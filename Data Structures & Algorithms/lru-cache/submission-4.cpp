class LRUCache {
private:
struct Node
{
    int key;
    int val;
    Node* next;
    Node* pre;
    Node(int k, int v)
    {
        key = k;
        val = v;
        next = nullptr;
        pre = nullptr;
    }
};
    int mcapacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* end;

    void remove(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void addFirst(Node* node) {
        node->next = head->next;
        node->pre = head;
        head->next->pre = node;
        head->next = node;
    }
public:
    LRUCache(int capacity) {
        mcapacity = capacity;
        head = new Node(0, 0);
        end = new Node(0, 0);
        head->next = end;
        end->pre = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* ite = mp[key];
        remove(ite);
        addFirst(ite);
        return ite->val;

    }

    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* ite = mp[key];
            ite->val = value;
            remove(ite);
            addFirst(ite);
            return;
        }


        if (mp.size() == mcapacity) {
            Node* lru = end->pre;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }


        Node* lnew = new Node(key, value);
        addFirst(lnew);
        mp[key] = lnew;
    }
};