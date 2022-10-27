#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node* next;

    Node() {this->val = 0;}
    Node(int val) {
        this->val = val;
    }
};


class LQ {
private:
    Node *head, *tail;
public:
    LQ() {
        head = new Node();
        tail = head;
    }

    void push(int val) {
        tail->next = new Node(val);
        tail = tail->next;
    }

    void pop() {
        if (head == tail) return;
        if (head->next == tail) {
            tail = head;
            head->next = nullptr;
            return;
        }
        auto k = head->next;
        head->next = head->next->next;

        delete k;
    }

    int top() {
        if (head == tail) return -1;
        return head->next->val;
    }

    bool empty() {
        return head == tail;
    }
};

int main() {
    LQ q = LQ();
    vector<int> a = {1, 2, 3};
    
    for (auto &x : a) {
        q.push(x);
    }
    while (!q.empty()) {
        printf("%d", q.top());
        q.pop();
    }
}