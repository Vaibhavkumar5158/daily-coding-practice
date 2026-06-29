#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val, lazy;
    int priority, sz;
    Node *left, *right;

    Node(long long v) {
        val = v;
        lazy = 0;
        priority = rand();
        sz = 1;
        left = right = nullptr;
    }
};

int getSize(Node* root) {
    return root ? root->sz : 0;
}

void applyAdd(Node* root, long long x) {
    if (!root) return;
    root->val += x;
    root->lazy += x;
}

void push(Node* root) {
    if (!root || root->lazy == 0) return;

    applyAdd(root->left, root->lazy);
    applyAdd(root->right, root->lazy);

    root->lazy = 0;
}

void pull(Node* root) {
    if (!root) return;
    root->sz = 1 + getSize(root->left) + getSize(root->right);
}

void split(Node* root, int k, Node* &left, Node* &right) {
    if (!root) {
        left = right = nullptr;
        return;
    }

    push(root);

    if (getSize(root->left) >= k) {
        split(root->left, k, left, root->left);
        right = root;
        pull(right);
    } else {
        split(root->right, k - getSize(root->left) - 1, root->right, right);
        left = root;
        pull(left);
    }
}

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->priority > right->priority) {
        push(left);
        left->right = merge(left->right, right);
        pull(left);
        return left;
    } else {
        push(right);
        right->left = merge(left, right->left);
        pull(right);
        return right;
    }
}

// Count how many values are <= x
int countLE(Node* root, long long x) {
    if (!root) return 0;

    push(root);

    if (root->val <= x) {
        return getSize(root->left) + 1 + countLE(root->right, x);
    } else {
        return countLE(root->left, x);
    }
}

long long getLast(Node* root) {
    push(root);

    while (root->right) {
        root = root->right;
        push(root);
    }

    return root->val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(712367);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        Node* root = nullptr;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;

            int pos = countLE(root, x);

            Node *left, *right;
            split(root, pos, left, right);

            // All greater elements are crossed by x,
            // so they increase by x.
            applyAdd(right, x);

            Node* cur = new Node(x);

            root = merge(merge(left, cur), right);
        }

        cout << getLast(root) << '\n';
    }

    return 0;
}