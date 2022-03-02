#include <bits/stdc++.h>

using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) {
        this -> data = data;
    }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

void levelOrderTraversal(TreeNode<int>* root) {
    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        q.push(NULL);
        while (q.front() != NULL) {
            TreeNode<int>* curr = q.front();
            q.pop();

            cout << curr -> data << " ";

            for (int i = 0; i < curr->children.size(); i++) {
                q.push(curr->children[i]);
            }
        }
        cout << endl;
        q.pop();
    }
}

int main() {

    TreeNode<int>* root = new TreeNode<int>(1);

    return 0;
}