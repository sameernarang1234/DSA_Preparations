#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode<T> *left, *right;

    BinaryTreeNode(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

BinaryTreeNode<int>* buildTree(vector<int> preOrder, vector<int> inOrder) {
    if (inOrder.empty()) {
        return NULL;
    }
    static int index = 0;

    BinaryTreeNode<int>* node = new BinaryTreeNode<int>(preOrder[index]);

    int inIndex = 0;

    for (int i = 0; i < inOrder.size(); i++) {
        if (inOrder[i] == preOrder[index]) {
            inIndex = i;
            break;
        }
    }
    index++;

    vector<int> leftTree;
    vector<int> rightTree;

    for (int i = 0; i < inIndex; i++) {
        leftTree.push_back(inOrder[i]);
    }
    for (int i = inIndex+1; i < inOrder.size(); i++) {
        rightTree.push_back(inOrder[i]);
    }

    node->left = buildTree(preOrder, leftTree);
    node->right = buildTree(preOrder, rightTree);

    return node;
}

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

    vector<int> preOrder = {5, 6, 2, 3, 9, 10};
    vector<int> inOrder = {2, 6, 3, 9, 5, 10};

    BinaryTreeNode<int>* root = buildTree(preOrder, inOrder);

    levelOrder(root);

    return 0;
}