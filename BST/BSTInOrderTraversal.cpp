#include <bits/stdc++.h>
#include <vector>

using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode *left, *right;

    BinaryTreeNode(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inOrder(BinaryTreeNode<int>* root, vector<int> &arr) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

vector<int>* getPathUtil(BinaryTreeNode<int>* root, int data, vector<int>* arr) {
    if (root == NULL) {
        // vector<int> arr2;
        // return arr2;
        return NULL;
    }
    
    arr->push_back(root->data);
    if (root->data == data) {
        return arr;
    }
    
    if (data < root->data) {
        return getPathUtil(root->left, data, arr);
    }
    return getPathUtil(root->right, data, arr);
}

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    vector<int>* arr;
    return getPathUtil(root, data, arr);
}

int main() {
    vector<int> arr;
    
    BinaryTreeNode<int>* root1 = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* root2 = new BinaryTreeNode<int>(0);
    BinaryTreeNode<int>* root3 = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int>* root4 = new BinaryTreeNode<int>(-2);
    BinaryTreeNode<int>* root5 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* root6 = new BinaryTreeNode<int>(8);
    BinaryTreeNode<int>* root7 = new BinaryTreeNode<int>(12);

    root1->left = root2;
    root1->right = root3;

    root2->left = root4;
    root2->right = root5;

    root3->left = root6;
    root3->right = root7;
    
    inOrder(root1, arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int>* path = getPath(root1, 12);

    for (int i = 0; i < path->size(); i++) {
        cout << path->at(i) << " ";
    }
    cout << endl;
}