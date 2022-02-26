#include <bits/stdc++.h>
#include <queue>

using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode *left, *right;

    BinaryTreeNode(int data) {
        this->data = data;
    }
};

void levelOrder(BinaryTreeNode<int>* root) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        q.push(NULL);
        while (q.front() != NULL) {
            BinaryTreeNode<int>* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        cout << endl;
        q.pop();
    }
}

int main() {
    return 0;
}