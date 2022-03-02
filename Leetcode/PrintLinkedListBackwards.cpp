// Use Stack Data Structure
#include <bits/stdc++.h>

using namespace std;

class LinkedListNode {
    public:
    int data;
    LinkedListNode* next;

    LinkedListNode(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void printReverse(LinkedListNode* head) {
    stack<LinkedListNode*> st;
    LinkedListNode* curr = head;
    
    while (curr != NULL) {
        st.push(curr);
        curr = curr -> next;
    }

    while (!st.empty()) {
        LinkedListNode* currVal = st.top();
        st.pop();
        cout << currVal -> data << " ";
    }

    cout << endl;
}

int main() {

    LinkedListNode* head = new LinkedListNode(0);
    LinkedListNode* curr = head;

    int N; cin >> N;

    int firstVal; cin >> firstVal; curr -> data = firstVal;

    for (int i = 0; i < N-1; i++) {
        int currVal; cin >> currVal;
        curr -> next = new LinkedListNode(currVal);
        curr = curr -> next;
    }

    printReverse(head);

    return 0;
}