#include <bits/stdc++.h>
#include <queue>

using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    if (root == NULL) {
        cout << "INSIDE 1" << endl;
        return true;
    }
    if (root->left == NULL && root->right == NULL) {
        cout << "INSIDE 2" << endl;
        return true;
    }
    if (root->left == NULL && root->right->data <= root->data) {
        cout << "INSIDE 3" << endl;
        return false;
    }
    if (root->right == NULL && root->left->data >= root->data) {
        cout << "INSIDE 4" << endl;
        return false;
    }
    if (!(root->left->data < root->data && root->right->data > root->data)) {
        cout << "INSIDE 5" << endl;
        return false;
    }
    
    cout << "INSIDE END" << endl;
    return (isBST(root->left) && isBST(root->right));
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
    BinaryTreeNode<int>* root = takeInput();
    levelOrder(root);
    // cout << (isBST(root) ? "true" : "false");
}