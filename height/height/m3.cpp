#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    // Build tree from array using level-order traversal
    Node* buildTree(int arr[], int N) {
        if (N == 0) return nullptr;

        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < N) {
            Node* current = q.front();
            q.pop();

            if (i < N) {
                current->left = new Node(arr[i++]);
                q.push(current->left);
            }

            if (i < N) {
                current->right = new Node(arr[i++]);
                q.push(current->right);
            }
        }

        return root;
    }

    // Compute height using DFS
    int computeHeight(Node* root) {
        if (!root) return -1;  // height of empty tree is -1 (so 1-node tree will return 0)
        int leftH = computeHeight(root->left);
        int rightH = computeHeight(root->right);
        return 1 + max(leftH, rightH);
    }

    int heapHeight(int N, int arr[]) {
        if (N == 1) return 1;
        Node* root = buildTree(arr, N);
        return computeHeight(root);
    }
};
