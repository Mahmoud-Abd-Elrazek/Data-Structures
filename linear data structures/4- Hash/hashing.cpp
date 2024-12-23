#include <iostream>
using namespace std;

class LinkedList {
    class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode (const int&val) : next(nullptr) , val(val) {};
    };
    ListNode* head;
public:
    LinkedList (): head(nullptr) {};
    ~LinkedList () {
        destroy();
    }

    bool empty () const { 
        return head == nullptr;
    }

    void insert (int key) {
        if (this->empty() == true)
            head = new ListNode(key);
        else {
            ListNode* cur = head;
            while (cur->next != nullptr)
                cur = cur->next;
            cur->next = new ListNode(key);
        }
    }
    
    friend ostream& operator<< (ostream&, const LinkedList&);
    friend ostream& operator<< (ostream&, const LinkedList*);
private:
    void destroy () {
        ListNode* del = head;
        while (head) { 
            del = head;
            head = head->next;
            delete del;
            del = nullptr;
        } 
    }
    void print (ostream& out) const { 
        for (ListNode* i = head ; i != nullptr ; i = i->next)
            out << i->val << " -> ";
    }
};

ostream& operator<< (ostream& out , const LinkedList& li) {
    li.print(out);
    return out;
}
ostream& operator<< (ostream& out , const LinkedList* li) {
    li->print(out);
    return out;
}

int main () {
    const int size = 200;
    LinkedList hashTable [size];

    auto hashFunction = [&] (int key)-> int {
        return (key % size);
    };

    int keys[] = {3,8,23,13,7,8,9,2};
    int N = sizeof(keys) / sizeof(*keys) , mxEle = -0x3f3f3f3f;
    for (int i = 0 ; i < N ; ++i) { 
        int item = keys[i];

        mxEle = max(mxEle , item);

        int index = hashFunction(item);
        hashTable[index].insert(item);
    }

    for (int i = 0 ; i <= mxEle ; ++i) { 
        if (hashTable[i].empty() == false) { 
            cout << "[ " << i << " ] -> ";
            cout << hashTable[i] << "NULL\n";
        }
    }
    return 0;
}